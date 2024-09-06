/*
====================================================================================================================================================================================
Name : 30.c
Author : Patenge Kanishka
Description :
Write a program to run a script at a specific time using a Daemon process.

Date : 29th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    pid_t pid = 0;
    pid_t sid = 0;
    int fd = open("test.txt",O_WRONLY);
    pid = fork();
    if(pid < 0)
    {
        perror("Failed to create child process : ");
        exit(1);
    }
    
    if(pid > 0)
    {
        printf("The process id of the parent is %d \n",pid);
        exit(0);
    }
    
    sleep(5);
    
    umask(0);
    
    sid = setsid();
    
    if(sid < 0)
    {
        exit(0);
    }
    
    chdir("/home/kanishka/abc/30");
    close(0);
    close(1);
    close(2);
    
    while(1)
    {
        sleep(2);
        write(fd,"this is deamon\n",15);
    }
    
    
    return 0;
    
}


/*
====================================================================================================================================================================================
Output:

anishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/30$ gcc 30.c -o deamon
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/30$ ./deamon
The process id of the parent is 5206 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/30$ cat test.txt
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/30$ cat test.txt
this is deamon
this is deamon
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/30$ cat test.txt
this is deamon
this is deamon
this is deamon
this is deamon
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/30$ 

// this shows it is deamon process
//1  1000    5696    1490  20   0   2484   128 hrtime Ss   ?          0:00 ./deamon

====================================================================================================================================================================================
*/
