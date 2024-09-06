/*
====================================================================================================================================================================================
Name : p29.c
Author : Patenge Kanishka
Description :
 Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR)

Date : 28th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>

void printing_priority()
{
    int a = sched_getscheduler(0);
    if(a == -1)
    {
        perror("Error ocuured while reading policy of the present running process \n");
        exit(0);
    }
    if(a & SCHED_RR)
    {
        printf("Policy is Real Time Round Robin \n");
    }
    else if(a & SCHED_FIFO)
    {
        printf("Policy is Real Time FIFO\n");
    }
    else if( a & SCHED_OTHER)
    {
        printf("Standard round-robin time-sharing\n");
    }
    else 
    {
        printf("Other type of policy specified to the the linux \n");
    }
}

int main()
{
   
    
    printf("Current policy of the running program is : \n");
    printing_priority();
    
    struct sched_param param;
    param.sched_priority = 10;
    
    printf("Enter the policy to enter : 1. RR 2. FIFO \n");
    int n;
    scanf("%d",&n);
    if(n == 1)
      n = SCHED_RR;
    else
      n = SCHED_FIFO;
    
    int t = sched_setscheduler(0,n,&param);
    
    if(t == -1)
    {
        perror("Failed to set the policy ");
        printf("\n");
        exit(0);
    }
    
    printf("After Changing  policy of the running program is : \n");
    printing_priority();
    
    

    
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p29.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Current policy of the running program is : 
Other type of policy specified to the the linux 
Enter the policy to enter : 1. RR 2. FIFO 
1
Failed to set the policy : Operation not permitted

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ sudo -s
[sudo] password for kanishka: 
root@kanishka-HP-Laptop-15s-fq5xxx:/home/kanishka/abc# ./a.out
Current policy of the running program is : 
Other type of policy specified to the the linux 
Enter the policy to enter : 1. RR 2. FIFO 
1
After Changing  policy of the running program is : 
Policy is Real Time Round Robin 
root@kanishka-HP-Laptop-15s-fq5xxx:/home/kanishka/abc# ./a.out
Current policy of the running program is : 
Other type of policy specified to the the linux 
Enter the policy to enter : 1. RR 2. FIFO 
2
After Changing  policy of the running program is : 
Policy is Real Time FIFO
root@kanishka-HP-Laptop-15s-fq5xxx:/home/kanishka/abc# exit
exit


====================================================================================================================================================================================
*/
