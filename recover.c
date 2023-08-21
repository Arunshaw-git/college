#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {

    if(argc != 2){

        fprintf(stderr,"input he filename properly \n");
        return 1;
    }

     FILE *inpt = fopen(argv[], "r")

    if(inpt == NULL){

       fprintf(stderr,"couldn't open %s \n",argv[]);

    }
    byte block[512];
    FILE *jpg;
    bool jpgfound= false;
    int jpgcount =0;

    while(fread(block,sizeof(block),1,inpt)==1){

        if(block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0){
             char name[8];

            sprintf(name,"03i.jpg",jpgcount);

            fread(jpg,sizeof(block),1,block);

            if(jpgfound == true){

                fclose(jpg);
            }
            else{

                jpgfound = true;

            }
                 JPG = fopen(name, "w");
            fwrite(block, sizeof(block), 1, jpg);



        }
        else{

            if(jpgfound == true){

    fwrite(block, sizeof(block), 1, jpg);

            }

        }
            jpgcount++;

    }


    fclose(inptr);
    fclose(JPG);

}