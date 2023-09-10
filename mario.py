# TODO

while (height<1 and height >8):
         height =int(input("Height: "))

for i in range(height):
    for j in range(height+(i+2)):

        if(i+j<=(height-2)):
             print(" ",end="")

        elif(j==(height)):

            print("  ",end="")

        else:

             print("#",end="")

    print("")


