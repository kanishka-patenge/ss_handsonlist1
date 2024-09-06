/*
====================================================================================================================================================================================
Name : 14.c
Author : Patenge Kanishka
Description :
Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.

Date : 11th August 2024
===================================================================================================================================================================================
*/



#include <sys/stat.h>
#include <sys/types.h>
#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int arg,char *args[])
{
  struct stat ans;
  
  int f = stat(args[1],&ans);
  if(f == -1)
  {
    printf("failed \n");
    return 0;
  }
  ans.st_mode = ans.st_mode&S_IFMT;
  
  if(ans.st_mode == S_IFSOCK)
  {
    printf("Socket file\n");
  }
  if(ans.st_mode == S_IFLNK)
  {
    printf("Symbolic link \n");
  }
  if(ans.st_mode == S_IFREG)
  {
    printf("Regular file \n");
  }
  if(ans.st_mode == S_IFBLK)
  {
    printf("Block device \n");
  }
  if(ans.st_mode == S_IFDIR)
  {
    printf("Directory \n");
  }
  if(ans.st_mode == S_IFCHR)
  {
    printf("Character Device \n");
  }
  if(ans.st_mode == S_IFIFO)
  {
    printf("FIFO File \n");
  }
  

  return 0;
}

/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 14.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out one.txt
Regular file 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out 123
Regular file 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out 789
FIFO File 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out second.c
Regular file 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out p16
Directory 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/

