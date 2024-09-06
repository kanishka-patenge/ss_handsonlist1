/*
====================================================================================================================================================================================
Name : p28.c
Author : Patenge Kanishka
Description :
Write a program to get maximum and minimum real time priority.

Date : 28th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <sched.h>

//    Write a program to get maximum and minimum real time priority.

int main()
{
    printf("The following are the min and max real time priority for SCHED_RR : \n");
    
    printf("Maximum real time priority is : %d\n",sched_get_priority_max(SCHED_RR));
    printf("Minimum real time priority is : %d\n",sched_get_priority_min(SCHED_RR));
    
    
    printf("The following are the min and max real time priority for SCHED_FIFO : \n");
    
    printf("Maximum real time priority is : %d\n",sched_get_priority_max(SCHED_FIFO));
    printf("Minimum real time priority is : %d\n",sched_get_priority_min(SCHED_FIFO));
    
    return 0;
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p28.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
The following are the min and max real time priority for SCHED_RR : 
Maximum real time priority is : 99
Minimum real time priority is : 1
The following are the min and max real time priority for SCHED_FIFO : 
Maximum real time priority is : 99
Minimum real time priority is : 1
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 


====================================================================================================================================================================================
*/
