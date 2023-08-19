#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <stdint.h>

typedef uint8_t byte;

int main(int argc, char *argv[])
{
    int jpeg_count =0;
    byte block[512];

    FILE *img;
    bool jpg_found = false;

    if(argc !=2){
        printf("file not found");
        return 1;
    }

    FILE *inpt = fopen(argv[1] , "r");

    if(inpt== NULL)
    {

        printf("file not found");

        return 2;
    }


 while (fread(block, sizeof(block), 1, inpt) == 1)
    {

     fread(block,sizeof(block), 1, inpt);


    if (block[0] == 0xff &&
        block[1] == 0xd8 &&
        block[2] == 0xff &&
        (block[3] & 0xf0) == 0xe0)
    {
        char name[10] ;

       sprintf(name, "%03i.jpg" ,jpeg_count);
       printf("processing file: %s\n", name);

       if(jpg_found ==true ){

        fclose(img);

       }
      else{

     jpg_found = true;

       }

        img = fopen(name, "w");

        fwrite(block,sizeof(block), 1, img);

        jpeg_count++;

    }
    else{

        if(jpg_found==true){

            fwrite(block,sizeof(block),1,img);

        }
    }

 }
  fclose(inpt);
    fclose(img);

}