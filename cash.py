# TODO

from cs50 import get_float

def main():
    cents =-1
    while True:
        try:
            cents = get_float("cents owed: ")
            if cents>0 :
                break
        except ValueError:
            print("invalid input")
    cents= round(cents*100)

    quaters = (cents //25)
    cents = (cents - quaters *25)

    dimes = cents //10
    cents = (cents - dimes *10)

    nickels = cents //5
    cents = r(cents - nickels *5)

    pennies = cents /1
    cents = cents - pennies*1

    coins = (quaters + dimes + nickels + pennies)

    print(coins)


main()