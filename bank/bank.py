
greet =input("Greeting: ")
h = "hello"
if greet.lower().strip()[0:5] in h:
      print("$0", end="")

elif greet[0] in ["h", "H"]:
        print("$20", end="")

else:
      print("$100", end="")

print("")