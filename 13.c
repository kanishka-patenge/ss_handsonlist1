/*
====================================================================================================================================================================================
Name : 13.c
Author : Patenge Kanishka
Description :
Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select)

Date : 11th August 2024
===================================================================================================================================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/select.h>


int main()
{
  fd_set rfd,wfd;
  FD_ZERO(&rfd);
  FD_ZERO(&wfd);
  FD_SET(0,&rfd);
  FD_SET(1,&wfd);
  struct timeval t;
  t.tv_sec = 10;
  t.tv_usec = 0;
  
  int s =  select(2, &rfd,NULL,NULL,&t);
  printf("value of the select = %d\n",s);
  if(s == -1)
  {
    perror("select() failed as : ");
    return 0;
  }
  if(s)
  {
    printf("Data is ready \n");
  }
  else
  {
    printf("Data is not ready in 10 sec \n");
  }
                  

  
  return 0;
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 13.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
value of the select = 0
Data is not ready in 10 sec 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
87564114
value of the select = 1
Data is ready 

====================================================================================================================================================================================
*/
