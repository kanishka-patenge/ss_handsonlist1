/*
====================================================================================================================================================================================
Name : 10.c
Author : Patenge Kanishka
Description :
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.

Date : 10th August 2024
===================================================================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
  int fd = open("three.txt",O_RDWR);
  if(fd == -1)
  {
    printf("Failed \n");
    perror("Message from perror : ");
    return 0;
  }
  char *ch = "0123456789";
  write(fd,ch,10);
  int val = lseek(fd,10, SEEK_CUR);
  
  char *an = "abcdefghij";
  write(fd,an,10);
  
  printf("%d\n",val);
  close(fd);
  return 0;
}

/*
====================================================================================================================================================================================
Output:
// output give the lseek value of the file

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 10.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
20
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ od -c three.txt
0000000   0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   a   b   c   d   e   f   g   h   i   j
0000036
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 
====================================================================================================================================================================================
*/

