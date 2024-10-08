#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

typedef uint8_t byte;

int main(int argc, char *argv[]) {

    if(argc != 2){

        fprintf(stderr,"input the filename properly \n");
        return 1;
    }

     FILE *inpt = fopen(argv[1], "r");

    if(inpt == NULL){

       fprintf(stderr,"couldn't open %s \n",argv[1]);
        return 2;
    }
    byte block[512];

    FILE *jpg;
    bool jpgfound= false;
    int jpgcount = 0;

    while(fread(block,sizeof(block),1,inpt)==1){

        if(block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0){
             char name[8];

            sprintf(name,"%03i.jpg",jpgcount);

            if(jpgfound == true){

                fclose(jpg);
            }
            else{

                jpgfound = true;

            }
                 jpg = fopen(name, "w");
            fwrite(block, sizeof(block), 1, jpg);

              jpgcount++;

        }
        else{

            if(jpgfound == true)
            {

    fwrite(block, sizeof(block), 1, jpg);

            }

        }


    }


    fclose(inpt);
    fclose(jpg);

}
