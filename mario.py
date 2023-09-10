# TODO
height=0
while True:
     height =int(input("Height: "))
         if (height<=1 or height >=8):
              break

for i in range(height):
    for j in range(height+(i+2)):

        if(i+j<=(height-2)):
             print(" ",end="")

        elif(j==(height)):

            print("  ",end="")

        else:

             print("#",end="")

    print("")


