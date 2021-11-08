#include <stdio.h>
#include "NumClass.h"

int main (){
    int num1=-1;
    int num2=-1;
    scanf("%d",&num1);
    scanf("%d",&num2);
    if(num1<num2){
        num1=num1+num2;
        num2=num1-num2;
        num1=num1-num2;
    }
    printf("The Armstrong numbers are:");
    int temp=num2;
    for (; num2 <= num1; num2=num2+1)
    {
       if( isArmstrong(num2) == 1){
           printf(" %d",num2);
       }
    }
     printf("\n");
     printf("The Palindromes are:");
     num2=temp;
    for (; num2 <= num1;  num2=num2+1)
    {
     if( isPalindrome(num2) == 1){
           printf(" %d",num2);
       }
    }
     printf("\n");
     printf("The Prime numbers are:");
     num2=temp;
    for (; num2 <= num1;  num2=num2+1)
    {
     if( isPrime(num2) == 1){
           printf(" %d",num2);
       }
    }
    printf("\n");
     printf("The Strong numbers are:");
     num2=temp;
    for (; num2 <= num1;  num2=num2+1)
    {
     if( isStrong(num2) == 1){
           printf(" %d",num2);
       }
    }
    printf("\n") ;
}