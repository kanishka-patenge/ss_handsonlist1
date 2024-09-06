/*
====================================================================================================================================================================================
Name : 19.c
Author : Patenge Kanishka
Description :
Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date : 27th August 2024
===================================================================================================================================================================================
*/




#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <x86intrin.h> // For __rdtsc()
#include <time.h>
#include <sys/times.h>

// Function to measure time taken by getpid system call

void displaying_time()
{
    struct tms t;
    clock_t clockTime;
    static long clockTicks = 0;
    
    if (clockTicks == 0) 
    {
      clockTicks = sysconf(_SC_CLK_TCK);
      if (clockTicks == -1)
      perror("sysconf");
    }
    clockTime = clock();
    if (clockTime == -1)
      perror("clock");
    printf("clock() -->  : %ld clocks-per-sec (%f secs)\n",(long) clockTime, (double) clockTime / CLOCKS_PER_SEC);
    if (times(&t) == -1)
      perror("times");
    printf("times() -->  : user CPU=%f; system CPU: %f\n",(double) t.tms_utime / clockTicks,(double) t.tms_stime / clockTicks);

}
int main()
{
    uint64_t start, end;
    pid_t pid;
    printf("Displyed time is for 1000000 operations of getpid  so time in seconds is actually micro seconds on average per pid : \n");
    // Read TSC before calling getpid
    start = __rdtsc();

    // Call the getpid system call
    for(int i=0;i<1000000;i++)
      pid = getpid();

    // Read TSC after calling getpid
    end = __rdtsc();

    // Calculate the time taken in TSC ticks
    uint64_t elapsed_ticks = end - start;

    printf("PID: %d\n", pid);
    printf("Time taken by getpid (in TSC ticks): %llu\n", (unsigned long long)elapsed_ticks);
    printf("lscpu info for the system : \n");
    printf("CPU max MHz:         4400.0000 \nCPU min MHz:         400.0000\n");
    printf("Time taken with minimum frequency = %f seconds \n", elapsed_ticks/(double)400000000);
    // printf("Time taken with maximum frequency = %f micro seconds \n", elapsed_ticks/(double)4400);
    printf("Time taken with maximum frequency = %f seconds \n", elapsed_ticks/(double)4400000000);
    
    
    
    printf("Displaying time using the times()  \n");
    printf("CLOCKS_PER_SEC=%ld sysconf(_SC_CLK_TCK)=%ld\n\n",(long) CLOCKS_PER_SEC, sysconf(_SC_CLK_TCK));
    printf("Displyed time is for 1000000 operations of getpid : \n");
    displaying_time();
    for(int i=0;i<1000000;i++)
      pid = getpid();
    displaying_time();
    
    return 0;
    
}


/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 19.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Displyed time is for 1000000 operations of getpid  so time in seconds is actually micro seconds on average per pid : 
PID: 4256
Time taken by getpid (in TSC ticks): 155880558
lscpu info for the system : 
CPU max MHz:         4400.0000 
CPU min MHz:         400.0000
Time taken with minimum frequency = 0.389701 seconds 
Time taken with maximum frequency = 0.035427 seconds 
Displaying time using the times()  
CLOCKS_PER_SEC=1000000 sysconf(_SC_CLK_TCK)=100

Displyed time is for 1000000 operations of getpid : 
clock() -->  : 63483 clocks-per-sec (0.063483 secs)
times() -->  : user CPU=0.020000; system CPU: 0.030000
clock() -->  : 123638 clocks-per-sec (0.123638 secs)
times() -->  : user CPU=0.060000; system CPU: 0.050000
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/


