/*
====================================================================================================================================================================================
Name : 9.c
Author : Patenge Kanishka
Description :
Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date : 10th August 2024
===================================================================================================================================================================================
*/


#include <sys/stat.h>
#include <sys/types.h>
#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <time.h>

int main()
{
  struct stat ans;
  char ch[1024];
  printf("Enter the file name to know the details of it : ");
  scanf("%s",ch);
  int f = stat(ch,&ans);
  if(f == -1)
  {
    printf("failed \n");
    return 0;
  }
  printf("Inode number of the file : %ld\n",ans.st_ino);
  printf("Count of the hard links : %ld\n",ans.st_nlink);
  printf("User id : %d\n",ans.st_uid);
  printf("Group id : %d\n",ans.st_gid);
  printf("Size of the file : %ld\n",ans.st_size);
  printf("Block size : %ld\n",ans.st_blksize);
  printf("Number of Blocks : %ld\n",ans.st_blocks);
  printf("Last access time : %s\n",ctime(&ans.st_atime));
  printf("Last Modified time : %s\n",ctime(&ans.st_mtime));
  printf("Last Change time : %s\n",ctime(&ans.st_ctime));
  

  return 0;
}


/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 9.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Enter the file name to know the details of it : one.txt
Inode number of the file : 3700747
Count of the hard links : 4
User id : 1000
Group id : 1000
Size of the file : 21
Block size : 4096
Number of Blocks : 8
Last access time : Thu Aug 29 17:45:06 2024

Last Modified time : Thu Aug 29 17:44:51 2024

Last Change time : Thu Aug 29 17:44:51 2024

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/
