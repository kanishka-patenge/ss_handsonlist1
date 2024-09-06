/*
====================================================================================================================================================================================
Name : p16.c
Author : Patenge Kanishka
Description :
Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock

Date : 28th August 2024
===================================================================================================================================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{

  int fd = open("test.txt",O_WRONLY|O_APPEND);
  if(fd == -1)
  {
    printf("File cannot be opened \n");
    exit(0);
  }
  struct flock locking;
  locking.l_type = F_WRLCK;
  locking.l_whence = SEEK_SET;
  locking.l_start = 0;
  locking.l_len = 0;
  
  
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtained the lock for writing so exiting the program \n");
    exit(0);
  }
 // sleep(10);
  char *buffer = "This to written by locking the file \n";
  write(fd,buffer,37);
  
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  
  close(fd);
  
  fd = open("test.txt",O_RDONLY);
  locking.l_type = F_RDLCK;
  
  stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtained the lock  for reading file so exiting the program  \n");
    exit(0);
  }
  
  char ss[1024];
  
  while(read(fd,ss,1))
  {
    printf("%s",ss);
  }
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
  

}


/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cd 16
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/16$ gcc p16.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/16$ ./a.out
This to written by locking the file 
This to written by locking the file 
This to written by locking the file 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/16$ cat test.txt
This to written by locking the file 
This to written by locking the file 
This to written by locking the file 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/16$ ls
a.out  p16.c  test.txt
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc/16$ 

====================================================================================================================================================================================
*/
