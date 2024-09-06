/*
====================================================================================================================================================================================
Name : p24.c
Author : Patenge Kanishka
Description :
Write a program to create an orphan process

Date : 27th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t child;
  switch(child = fork())
  {
    case -1:
      perror("error while creating the child \n");
      break;
    case 0:
      sleep(10);
      printf("the process id of the child by the child is %d \n",getpid());
      printf("the process id of the parent by child is %d \n",getppid());
      exit(0);
      break;
    default:
      sleep(2);
      printf("the process id the child from parent is %d \n process id of the parent from parent is :%d \n",child,getpid());
      break;
  }
}

/*
====================================================================================================================================================================================
Output:
// There is the mismatch with the pid of parent by parent and child
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p24.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
the process id the child from parent is 4551 
 process id of the parent from parent is :4550 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ the process id of the child by the child is 4551 
the process id of the parent by child is 1544 



====================================================================================================================================================================================
*/
