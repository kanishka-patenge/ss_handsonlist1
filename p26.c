/*
====================================================================================================================================================================================
Name : p26.c
Author : Patenge Kanishka
Description :
Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date : 29th August 2024
===================================================================================================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This program is created to run executable code \n");
   int res =  system("./random \"from other c program\"");
   if(res == 0)
    printf("Command executed sucessfully\n");
  else
    printf("Command failed\n");
    return 0;
    
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p26.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
This program is created to run executable code 
I am the testp26.c and can be executed with ./random
the string from command line is : from other c program
Command executed sucessfully
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc testp26.c -o random
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./random checking
I am the testp26.c and can be executed with ./random
the string from command line is : checking
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/
