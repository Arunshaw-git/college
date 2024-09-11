# TODO
height=0
while height<1 or height >8:
        try:
             height =int(input("Height: "))
        except:
             print("enter an int")
for i in range(height):
    for j in range(height+(i+2)):

        if(i+j<=(height-2)):
             print(" ",end="")

        elif(j==(height)):

            print("  ",end="")

        else:

             print("#",end="")

    print("")


