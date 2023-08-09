#include <stdio.h>
#include <cs50.h>

int main()
{       int n;
    do{
    printf("height:\n");
    scanf("%d",&n);
    }
    while(n>8||n<=0);

    for(int i=1; i<=n; i++){

      for(int j=1; j<=(n+i+1); j++){

      if((i+j)<=n){

        printf(" ");

           }
            else if (j == n+1){
            printf("  ");
           }
        else{

        printf("#");

        }

        }
        printf("\n");
        }

    return 0;
}