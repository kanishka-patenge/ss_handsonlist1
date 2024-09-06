/*
====================================================================================================================================================================================
Name : 12.c
Author : Patenge Kanishka
Description :
Write a program to find out the opening mode of a file. Use fcntl

Date : 11th August 2024
===================================================================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
  int fd = open("two.txt",O_RDWR);
  printf("fd for three.txt : %d\n",fd);
  if(fd == -1)
  {
    printf("Failed \n");
    perror("Message from perror : ");
    return 0;
  }
  //int c = fcntl(fd,F_GETFD);
  
  
  int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        return 0;
    }

    printf("File mode: ");
    if (flags & O_RDONLY) {
        printf("read ");
    }
    if (flags & O_WRONLY) {
        printf("write ");
    }
    if (flags & O_RDWR) {
        printf("read/write ");
    }
    if (flags & O_APPEND) {
        printf("append ");
    }
    if (flags & O_CREAT) {
        printf("create ");
    }
    if (flags & O_TRUNC) {
        printf("truncate ");
    }
    if (flags & O_EXCL) {
        printf("exclusive ");
    }

    printf("\n");
  
  
  
    if (flags == -1) {
        perror("fcntl");
  }
  close(fd);
  return 0;
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 12.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
fd for three.txt : 3
File mode: read/write 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 
====================================================================================================================================================================================
*/
