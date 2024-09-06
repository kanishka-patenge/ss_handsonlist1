/*
====================================================================================================================================================================================
Name : p21.c
Author : Patenge Kanishka
Description :
Write a program, call fork and print the parent and child process id

Date : 27th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t child;
  switch(child = fork())
  {
    case -1:
      perror("error while creating the child \n");
      break;
    case 0:
      printf("the process id of the child by the child is %d \n",getpid());
      break;
    default:
      printf("the process id the child from parent is %d \n process id of the parent from parent is :%d \n",child,getpid());
      break;
  }
}

/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p21.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
the process id the child from parent is 4393 
 process id of the parent from parent is :4392 
the process id of the child by the child is 4393 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/
