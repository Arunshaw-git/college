#include<stdio.h>


int main(void){

   int length1;
   int length2;
    printf("enter the length of first array:\n");
    scanf("%d",&length1);
    printf("enter the length of second array:\n");
    scanf("%d",&length2);
    int arr2[length2];
     int arr1[length1];

    printf("Enter the elements of first array: \n" );

    for(int i=0; i<length1 ;i++){
            int n;
        scanf("%d\n",&n);
        arr1[i]=n;
    }
    printf("Enter the elements of second array: \n" );

    for(int i=0; i<length2 ;i++){
           int n;
        scanf("%d\n",&n);
        arr2[i]=n;
    }
    for (int i = 0; i < length1; i++) {
        // Print each element of the array.
        printf("%d ", arr1[i]);
    }
   int total=length1+length2;
    if((total)%2==0){

        if(length1<total/2){

            int n =arr2[(total/2)-(length1-1)]+ ;
            printf("%d",n);


        }


    }


}