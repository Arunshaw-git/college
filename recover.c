#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#define int BLOCK_SIZE 512;
int main(int argc, char *argv[])
{ int jpeg_count =0;
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

     FILE *buffer;

    for(int i = 0; inpt != EOF ; i++ )
    {

     fread(buffer, 512, 1, inpt);

    if(buffer[0]== 0xff && bufffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
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

        fwrite(buffer,512 , 1, img);

        jpg_count++;

    }
    else{

        if(jpg_found==true){

            fwrite(buffer,512,1,img);
            
        }
    }

 }

}