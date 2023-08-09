#include<ctype.h>
#include<cs50.h>

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{
    // Get input words from both players

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    bool alpha= true;
     do{


    for(int i=0; word1[i]!='\0';i++){

        if(!isalpha(word1[i])){

           alpha= false;

            break;

        }
        else{

        alpha=true;

        }

        }

    }while(alpha==false);



    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1>score2){

    printf("Player 1 wins\n");


    }
    else if(score2>score1){

        printf("Player 2 wins\n");

        }
        else{
        printf("Tie");
        }

    // TODO: Print the winner
}

int compute_score(char *word)
{
    // TODO: Compute and return score for string
    char ch;
    int n=0;
    int sum=0;
    for(int i =0;word[i]!='\0'; i++) {


        for(int j=0; j<26; j++){

        if(toupper(word[i])==j+65){

          sum+=POINTS[j];

          break;



        }

        }

        }
        return sum;
}
