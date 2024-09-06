/*
====================================================================================================================================================================================
Name : 11.c
Author : Patenge Kanishka
Description :
Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl

Date : 11th August 2024
===================================================================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
  int fd = open("three.txt",O_RDWR);
  printf("fd for three.txt : %d\n",fd);
  if(fd == -1)
  {
    printf("Failed \n");
    perror("Message from perror : ");
    return 0;
  }
  int fd1 = dup(fd);
  printf("fd for dup(fd) : %d\n",fd1);
  int t = open("one.txt",O_RDWR);
  printf("fd for one.txt t =  %d\n",t);
  
  int fcntltt = fcntl(fd,F_DUPFD,t);
  printf("fd for fcntl(fd,F_DUPFD,t) == %d\n",fcntltt);
  
  char *ttt = "updated by fcntl \n";
  write(fcntltt,ttt,18);
  
  int fd2 = dup2(fd,t);
  printf("fd for dup2(fd,t) fd2 = %d\n",fd2);
  char *ch = "updated by fd LSJjojsl slgksfj \n";
  write(fd,ch,32);
  
  char *an = "updated by dup1() fd 1sg kjkgj; \n";
  write(fd1,an,33);
  
  char *ss = "updated by dup2() fd2 tihth  kajd\n";
  
  write(fd2,ss,34);
  
  close(fd);
  return 0;
}

/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 11.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
fd for three.txt : 3
fd for dup(fd) : 4
fd for one.txt t =  5
fd for fcntl(fd,F_DUPFD,t) == 6
fd for dup2(fd,t) fd2 = 5
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat three.txt
updated by fcntl 
updated by fd LSJjojsl slgksfj 
updated by dup1() fd 1sg kjkgj; 
updated by dup2() fd2 tihth  kajd
ted by dup2() fd2 tihth  kajd
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 




====================================================================================================================================================================================
*/
