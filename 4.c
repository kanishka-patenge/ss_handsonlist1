/*
====================================================================================================================================================================================
Name : 4.c
Author : Patenge Kanishka
Description :
Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Date : 9th August 2024
===================================================================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>

int main()
{
  int fd = open("xyz.txt",O_EXCL|O_CREAT|O_RDWR);
  if(fd == -1)
  {
    printf("Failed \n");
    perror("Message from perror : ");
  }
  else
  {
    printf("Sucess AND fd  : %d \n",fd);
  }
  return 0;
}



/*
====================================================================================================================================================================================
output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 4.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Failed 
Message from perror : : File exists

====================================================================================================================================================================================
*/
