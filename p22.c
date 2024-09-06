/*
====================================================================================================================================================================================
Name : p22.c
Author : Patenge Kanishka
Description :
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Date : 27th August 2024
===================================================================================================================================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // exit()
#include <fcntl.h>// to open()

int main()
{
  pid_t child;
  int fd = open("test.txt",O_RDWR|O_APPEND);
  char *p = "This is by the parent \n";
  char *c = "This is by the child \n";
  
  char ch[1024];
  if(fd == -1)
  {
    perror("Error while opening the file ");
    exit(0);
  }
  switch(child = fork())
  {
    case -1:
      perror("error while creating the child \n");
      break;
    case 0:
      printf("Writing by the child process \n");
      //lseek(fd,0,SEEK_END);
      write(fd,c,22);
      break;
    default:
      //printf("Parent is going to sleep \n");
      //lseek(fd,0,SEEK_END);
      printf("Writing by the parent process \n");
      write(fd,p,23);
      break;
  }
  
  close(fd);
  return 0;
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p22.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat test.txt
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Writing by the parent process 
Writing by the child process 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat test.txt
This is by the parent 
This is by the child 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/
