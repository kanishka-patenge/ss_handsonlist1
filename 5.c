/*
====================================================================================================================================================================================
Name : 5.c
Author : Patenge Kanishka
Description :
Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.

Date : 9th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdlib.h>

int main()
{
  creat("one.txt",00700);
  creat("two.txt",00700);
  creat("three.txt",00700);
  creat("four.txt",00700);
  creat("five.txt",00700);
  
  while(1)
  {
  // to reduce the cpu usage 
    sleep(1);
    
  }
  
  return 0;
}


/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 5.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out &
[1] 5879
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cd /proc/5879/fd
kanishka@kanishka-HP-Laptop-15s-fq5xxx:/proc/5879/fd$ ls -l
total 0
lrwx------ 1 kanishka kanishka 64 Aug 29 17:33 0 -> /dev/pts/1
lrwx------ 1 kanishka kanishka 64 Aug 29 17:33 1 -> /dev/pts/1
lrwx------ 1 kanishka kanishka 64 Aug 29 17:33 2 -> /dev/pts/1
l-wx------ 1 kanishka kanishka 64 Aug 29 17:33 3 -> /home/kanishka/abc/one.txt
l-wx------ 1 kanishka kanishka 64 Aug 29 17:33 4 -> /home/kanishka/abc/two.txt
l-wx------ 1 kanishka kanishka 64 Aug 29 17:33 5 -> /home/kanishka/abc/three.txt
l-wx------ 1 kanishka kanishka 64 Aug 29 17:33 6 -> /home/kanishka/abc/four.txt
l-wx------ 1 kanishka kanishka 64 Aug 29 17:33 7 -> /home/kanishka/abc/five.txt
kanishka@kanishka-HP-Laptop-15s-fq5xxx:/proc/5879/fd$ 

====================================================================================================================================================================================
*/
