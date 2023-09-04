
greet =input("Greeting: ")
h = "hello"
if greet.lower()[0:5] in h:
      print("$0", end='')

elif greet[0] in ["h", "H"]:
      if greet.lower() != h:
                print("$20", end='')

else:
      print("$100", end='')

