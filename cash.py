# TODO

from cs50 import get_float


def main():
    cents = -1
    while True:
        try:
            cents = get_float("cents owed: ")
            if cents > 0:
                break
        except ValueError:
            print("invalid input")
    cents = round(cents * 100)

    quaters = round(cents // 25)
    cents = round(cents - quaters * 25)

    dimes = cents // 10
    cents = round(cents - dimes * 10)

    nickels = cents // 5
    cents = round(cents - nickels * 5)

    pennies = cents / 1
    cents = cents - pennies * 1

    coins = round(quaters + dimes + nickels + pennies)

    print(coins)


main()
