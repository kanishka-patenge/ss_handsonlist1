/*
====================================================================================================================================================================================
Name : p20.c
Author : Patenge Kanishka
Description :
Find out the priority of your running program. Modify the priority with nice command.

Date : 27th August 2024
===================================================================================================================================================================================
*/


#include<stdio.h>

// use the following commands 
// top -d 3 --> to track the details of the process running
// nice [commond]  --> should use before the running the process like ::  nice -n 2 ./a.out
// renice -n 2 -p [pid]
// renice -n 2 -u [user]
int main()
{
	while(1);
	return 0;
}

/*
====================================================================================================================================================================================
Output:

// normmal priorit is 20
4312 kanishka  22   2    2484    896    896 R 100.0   0.0   0:55.03 a.out                                                                                                           

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p20.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ nice -n 2 ./a.out



====================================================================================================================================================================================
*/
