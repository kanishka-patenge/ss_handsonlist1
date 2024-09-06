/*
====================================================================================================================================================================================
Name : 6.c
Author : Patenge Kanishka
Description :
Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Date : 10th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

#include<fcntl.h>

int main()
{
  
  int a;
  printf("Enter the how many bytes of data to take : ");
  scanf("%d",&a);
  
  
  
  extern FILE *stdin;
 read(0, stdin, a);
 write(1, stdin, a);
 
 printf("\n");
 

}

/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 6.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Enter the how many bytes of data to take : 5
fives
fives


====================================================================================================================================================================================
*/
