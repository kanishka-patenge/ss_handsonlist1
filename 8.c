/*
====================================================================================================================================================================================
Name : 8.c
Author : Patenge Kanishka
Description :
Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.

Date : 10th August 2024
===================================================================================================================================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{

  int sc = open("two.txt",O_RDONLY);
  if(sc == -1)
  {
    printf("Failed \n");
    perror("Message from perror : ");
    return 0;
  }
  char *ch;
  int line = 1;
  char pre = '\n';
  while(read(sc,ch,1) && ch[0] != '\0')
  {
    if(pre == '\n')
    {
      printf("Line no : %d ",line);
      pre = 'a';
      line++;
    }
    
    
    if(ch[0] == '\n')
    {
      printf("\n");
      pre = ch[0];
    }
    else
    {
      printf("%c",ch[0]);
      pre = ch[0];
    }
  }
  close(sc);
  
  return 0;
}


/*
====================================================================================================================================================================================
Output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 8.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Line no : 1 This is to test
Line no : 2 hi
Line no : 3 This is line three
Line no : 4 This is line four
Line no : 5 end
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 

====================================================================================================================================================================================
*/
