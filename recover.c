#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <stdint.h>

#define int BLOCK_SIZE 512;
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

    FILE *inpt = fopen(arg[1] , "r");

    if(inpt== NULL)
    {

        printf("file not found");

        return 2;
    }


    for(int i = 0; inpt != EOF ; i++ )
    {

     fread(block,sizeof(block), 1, inpt);

    if(inpt[0]== 0xff && inpt[1] == 0xd8 && inpt[2] == 0xff && (inpt[3] & 0xf0) == 0xe0)
    {
        char name[10] ;

       sprintf(name, "%03i.jpg" ,jpeg_count);

       if(jpg_found == false){

        jpg_found = true:

       }
      else{

        fclose(img);

       }

        img = fopen(name, "w");

        fwrite(block,sizeof(block), 1, img);

        jpg_count++;

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