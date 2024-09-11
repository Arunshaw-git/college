import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime


from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    stocks = db.execute("select * from stocks where stocks.id = ?", user_id)
    data = []
    total = 0
    for stock in stocks:
        x = lookup(stock["stock"])
        total_value = round(x["price"] * stock["quantity"], 2)
        stock_data = {
            "symbol": stock["stock"],
            "total_value": total_value,
            "quantity": stock["quantity"],
            "price": x["price"],
        }
        data.append(stock_data)
        total = total + total_value

    cash = db.execute("select cash from users WHERE id = ?", user_id)
    if cash:
        cash2 = round(float(cash[0]["cash"]), 2)
    else:
        cash = 0
        cash2 = cash
    return render_template("index.html", data=data, cash=cash2, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        if not request.form.get("symbol") or not request.form.get("shares"):
            return apology("empty", 400)
        shares = request.form.get("shares")
        if not shares.isdigit() or int(shares) < 1:
            return apology("Invalid quantity", 400)
        quant = int(shares)
        sym = request.form.get("symbol")

        stock_sym = lookup(sym)

        user_id = session["user_id"]

        stocks = db.execute("select * from stocks join users on stocks.id = ?", user_id)
        cash = db.execute("select cash from users where users.id= ?", user_id)
        if stock_sym is not None:
            if cash[0]["cash"] <= 0 and cash[0]["cash"] < (quant * stock_sym["price"]):
                return apology("broke", 400)
            for s in stocks:

                if sym == s["stock"]:

                    db.execute(
                        "UPDATE stocks SET quantity = quantity + ? WHERE id = ? AND stock = ?",
                        quant,
                        user_id,
                        sym,
                    )
                    price = round(float(stock_sym["price"]), 2)

                    db.execute(
                        "insert into transactions(user_id, symbol, quantity, price, type) VALUES (?, ?, ?, ?, 'buy' )",
                        user_id,
                        sym,
                        quant,
                        price,
                    )
                    db.execute(
                        "UPDATE users SET cash = cash - ? WHERE id = ?",
                        int(request.form.get("shares")) * price,
                        user_id,
                    )

                    return redirect("/")

            price = round(float(stock_sym["price"]), 2)
            db.execute(
                "insert into stocks(stock,quantity,id) values(?,?,?)",
                sym,
                int(request.form.get("shares")),
                user_id,

            )
            db.execute(
                "UPDATE users SET cash = cash - ? WHERE id = ?",
                int(request.form.get("shares")) * price,
                user_id,
            )
            db.execute(
                "insert into transactions(user_id, symbol, quantity, price, type) VALUES (?, ?, ?, ?, 'buy' )",
                user_id,
                sym,
                quant,
                price,
            )
            return redirect("/")
        else:
            return apology("no match", 400)

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():

    user_id = session["user_id"]
    history = db.execute("select * from transactions where user_id = ?", user_id)
    return render_template("history.html", data=history)


@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    user_id = session["user_id"]

    if request.method == "POST":
        cash = request.form.get("cash")
        db.execute("update users set cash = cash + ? where users.id = ?", cash, user_id)
        return redirect("/")
    else:
        return render_template("add.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("empty")

        sym = request.form.get("symbol")

        stock = lookup(sym)

        if stock is not None:
            return render_template("quoted.html", stock=stock)
        else:
            return apology("no match", 400)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

            # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        user_check = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        if len(user_check) == 1:
            return apology("invalid username ", 400)

        elif not (request.form.get("confirmation") == request.form.get("password")):
            return apology("invalid password", 400)

        db.execute(
            "INSERT INTO users(username,hash) VALUES(?,?)",
            request.form.get("username"),
            generate_password_hash(request.form.get("password")),
        )
        user_id = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )
        session["user_id"] = user_id[0]["id"]

        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":

        if not request.form.get("symbol") or not request.form.get("shares"):
            return apology("empty", 400)

        quant = int(request.form.get("shares"))

        if quant < 1:
            return apology("cant be negative quantity", 400)

        sym1 = request.form.get("symbol")
        sym = sym1.lower()
        stock_sym = lookup(sym)

        user_id = session["user_id"]
        stocks = db.execute("select * from stocks where stocks.id = ?", user_id)
        # cash = db.execute("select cash from users where users.id= ?", user_id)
        print(stocks)
        if stock_sym is not None:
            price = int(stock_sym["price"])
            for s in stocks:

                if sym == s["stock"]:

                    if quant > s["quantity"]:
                        return apology("you dont own that much", 400)

                    db.execute(
                        "UPDATE stocks SET quantity = quantity - ? WHERE id = ? AND stock = ?",
                        quant,
                        user_id,
                        sym,
                    )
                    db.execute(
                        "UPDATE users SET cash = cash + ? WHERE id = ?",
                        quant * price,
                        user_id,
                    )
                    n = db.execute(
                        "select * from stocks where stocks.id = ? and stocks.stock= ?",
                        user_id,
                        sym,
                    )

                    db.execute(
                        "insert into transactions(user_id, symbol, quantity, price, type) VALUES (?, ?, ?, ?, 'sell' )",
                        user_id,
                        sym,
                        -quant,
                        price,
                    )

                    if n[0]["quantity"] == 0:
                        db.execute(
                            "delete from stocks where stocks.id=? and stocks.stock =?",
                            user_id,
                            sym,
                        )
                        return redirect("/")

                    return redirect("/")

            return apology(f"You don't have any stock named {sym}")

    else:
        user_id = session["user_id"]
        symbols = db.execute("select stock from stocks where id =?", user_id)
        return render_template("sell.html", symbols=[rows['stock'] for rows in symbols])

    return apology("An unexpected error occurred", 400)
