#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
int count_letters(char text[2000]);
int count_words(char text[2000]);
int count_sentences(char text[2000]);
int main(void)
{
    char text[2000];

 //   int words;
 //  int space;
   /* do{
        printf("Text: ");

          scanf("%s",&text);
        for(int i=0; text[i]!='\0'; i++){

            if(ispunct(text[i]) || isspace(text[i])){

                 int word=1;
                 break;
        }
       }

      }while(word!=1); */
            printf("Text: ");

            fgets(text,sizeof(text),stdin);

           // printf("%s",text);
        int letters =count_letters(text);
        int words = count_words(text);
        int sentences = count_sentences(text);

          float L = (float)((letters*100)/words);
          float S = (float)((sentences*100)/words);

          float index = (0.0588 * L) - (0.296 * S) - 15.8;
           int r_index= round(index);
        printf("%d\n",r_index);

        if(r_index<1){

            printf("Before grade 1");
            }

        else if(r_index<16)
            {

            printf("Grade %d",r_index);

            }

        else {

            printf("Grade 16+");
        }



}

int count_letters(char text[2000]){

    int num=0;

   for(int i=0; text[i]!='\0'; i++){

        if(isalpha(text[i])){

               num++;

            }

          }

   return num;

}

int count_words(char text[2000]){

    int num1=0;

    for(int i =0; text[i]!='\0';i++)
       {



        if(isspace(text[i]))
        {
          num1++;
        if(isspace(text[i+1]))
        {
            i++;
        }

         }
       }

       return num1;

}

int count_sentences(char text[2000]){

      int num2=0;
      for(int i=0; text[i]!='\0'; i++)
         {
            if(text[i]=='.' || text[i]=='?' || text[i]=='!')
              {

                   num2++;

              }


         }

       return num2;



}