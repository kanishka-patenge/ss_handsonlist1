/*
====================================================================================================================================================================================
Name : 7.c
Author : Patenge Kanishka
Description :
Write a program to copy file1 into file2 ($cp file1 file2)

Date : 10th August 2024
===================================================================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
  int fd = open("one.txt",O_RDWR);
  if(fd == -1)
  {
    printf("Failed \n");
    perror("Message from perror : ");
    return 0;
  }
  int sc = open("two.txt",O_RDWR|O_APPEND);
  if(sc == -1)
  {
    printf("Failed \n");
    perror("Message from perror : ");
    return 0;
  }
  char *ch;
  while(read(fd,ch,1) && ch[0] != '\0')
  {
    write(sc,ch,1);
  }
  
  return 0;
}


/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 7.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat one.txt
This is to test 
hi

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat two.txt
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat two.txt
This is to test 
hi

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat one.txt
This is to test 
hi

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/
