/*
====================================================================================================================================================================================
Name : p23.c
Author : Patenge Kanishka
Description :
Write a program to create a Zombie state of the running program

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
      printf("the process id of the child by the child is %d \n",getpid());
      printf("the process id of the parent by child is %d \n",getppid());
      exit(0);
      break;
    default:
      sleep(3);
      printf("the process id the child from parent is %d \n process id of the parent from parent is :%d \n",child,getpid());
      break;
  }
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ps -o pid,ppid,status,cmd
    PID    PPID STATUS CMD
   3140    3121      - bash
   4504    3140      - ps -o pid,ppid,status,cmd
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p23.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out &
[1] 4511
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ the process id of the child by the child is 4512 
the process id of the parent by child is 4511 
ps -o pid,ppid,status,cmd
    PID    PPID STATUS CMD
   3140    3121      - bash
   4511    3140      - ./a.out
   4512    4511      - [a.out] <defunct>
   4514    3140      - ps -o pid,ppid,status,cmd
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ the process id the child from parent is 4512 
 process id of the parent from parent is :4511 



====================================================================================================================================================================================
*/
