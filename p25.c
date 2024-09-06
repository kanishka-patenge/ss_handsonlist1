/*
====================================================================================================================================================================================
Name : p25.c
Author : Patenge Kanishka
Description :
Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call)

Date : 27th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t a,b,c;
    printf("Parent before creating the process \n");
    a = fork();
    sleep(2);
    if(a == 0)
    {
        printf("I am first process and I am going for the sleep \n");
        sleep(10);
        printf(" p1 Terminating after the sleep \n");
        exit(0);
    }
    
    b = fork();
    sleep(2);
    if(b == 0)
    {
        printf("I am second process and I am going to the sleep \n");
        sleep(20);
        printf("p2 Terminating after the sleep \n");
        exit(0);
    }
    
    c = fork();
    sleep(2);
    if(c == 0)
    {
      printf(" I am third process and I am going to the sleep \n");
      sleep(5);
      printf("p3 Terminating after the sleep \n");
      exit(0);
    }
    sleep(1);
    printf("Parent created all process and waiting the process p2 to finish \n");
    waitpid(b,NULL,0);
    printf("execuring parent after p2 terminated \n");

}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p25.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Parent before creating the process 
I am first process and I am going for the sleep 
I am second process and I am going to the sleep 
 I am third process and I am going to the sleep 
Parent created all process and waiting the process p2 to finish 
p3 Terminating after the sleep 
 p1 Terminating after the sleep 
p2 Terminating after the sleep 
execuring parent after p2 terminated 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 


====================================================================================================================================================================================
*/
