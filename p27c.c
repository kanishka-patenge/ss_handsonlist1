/*
====================================================================================================================================================================================
Name : p27c.c
Author : Patenge Kanishka
Description :
Write a program to execute ls -Rl by the following system calls
c. execle

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
   
    char *path = "/bin/ls";
    char *arg1 = "-Rl";
    char *cmd = "ls";
    
    printf("Using the execle() to execute ls -Rl \n");
    char *file = "ls";
    execle(path,cmd,arg1,NULL,0);
    
}

/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc p27c.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
Using the execle() to execute ls -Rl 
.:
total 576
-rw-rw-r-- 4 kanishka kanishka    21 Aug 29 17:44 0214
-rw-rw-r-- 1 kanishka kanishka  5157 Aug 29 17:12 1.c
-rw-rw-r-- 1 kanishka kanishka  1876 Aug 29 18:04 10.c
-rw-rw-r-- 1 kanishka kanishka  2376 Aug 29 18:19 11.c
-rw-rw-r-- 1 kanishka kanishka  2041 Aug 29 18:22 12.c
lrwxrwxrwx 1 kanishka kanishka     7 Aug 29 17:05 123 -> one.txt
-rw-rw-r-- 1 kanishka kanishka  1819 Aug 29 18:27 13.c
-rw-rw-r-- 1 kanishka kanishka  2234 Aug 29 18:31 14.c
-rw-rw-r-- 1 kanishka kanishka  4468 Aug 29 18:34 15.c
drwxrwxr-x 2 kanishka kanishka  4096 Aug 29 18:38 16
drwxrwxr-x 2 kanishka kanishka  4096 Aug 29 18:59 17
drwxrwxr-x 2 kanishka kanishka  4096 Aug 29 19:05 18
-rw-rw-r-- 1 kanishka kanishka  4034 Aug 29 19:07 19.c
-rw-rw-r-- 1 kanishka kanishka  2728 Aug 29 17:20 3.c
-rw-rw-r-- 1 kanishka kanishka  1318 Aug 29 17:35 4.c
-rw-rw-r-- 4 kanishka kanishka    21 Aug 29 17:44 444
-rw-rw-r-- 4 kanishka kanishka    21 Aug 29 17:44 456
-rw-rw-r-- 1 kanishka kanishka  2181 Aug 29 17:42 5.c
prw-rw-r-- 1 kanishka kanishka     0 Aug 29 17:11 555
-rw-rw-r-- 1 kanishka kanishka  1338 Aug 29 17:43 6.c
-rw-rw-r-- 1 kanishka kanishka  1779 Aug 29 17:47 7.c
p--------- 1 kanishka kanishka     0 Aug 29 17:05 789
-rw-rw-r-- 1 kanishka kanishka  1830 Aug 29 17:52 8.c
lrwxrwxrwx 1 kanishka kanishka     7 Aug 29 17:10 888 -> one.txt
-rw-rw-r-- 1 kanishka kanishka  2434 Aug 29 17:56 9.c
lrwxrwxrwx 1 kanishka kanishka     7 Aug  9 17:32 a -> xyz.txt
-rwxrwxr-x 1 kanishka kanishka 16000 Aug 29 19:35 a.out
lrwxrwxrwx 1 kanishka kanishka     8 Aug 11 12:26 aaaaa -> test.txt
prw-rw-r-- 1 kanishka kanishka     0 Aug 11 12:27 abc
-rw-rw-rw- 1 kanishka kanishka    40 Aug 20 17:40 common.txt
-rwxrwxr-x 1 kanishka kanishka 16216 Aug 10 17:08 eigth
-rw-rw-r-- 1 kanishka kanishka   588 Aug 10 17:08 eigth.c
-rwxrwxr-x 1 kanishka kanishka 16296 Aug 11 08:50 eleventh
-rw-rw-r-- 1 kanishka kanishka   875 Aug 11 08:50 eleventh.c
-rwxrwxr-x 1 kanishka kanishka 16032 Aug 11 12:39 fifteen
-rw-rw-r-- 1 kanishka kanishka   166 Aug 11 12:38 fifteen.c
-rwxrwxr-x 1 kanishka kanishka 15992 Aug  9 18:38 fifth
-rw-rw-r-- 1 kanishka kanishka   313 Aug  9 18:38 fifth.c
-rwx------ 1 kanishka kanishka     0 Aug 29 17:33 five.txt
-rwx------ 1 kanishka kanishka     0 Aug 29 17:33 four.txt
-rwxrwxr-x 1 kanishka kanishka 16056 Aug 11 12:25 fourteen
-rw-rw-r-- 1 kanishka kanishka  1630 Aug 11 12:25 fourteen.c
-rwxrwxr-x 1 kanishka kanishka 16080 Aug  9 17:59 fourth
-rw-rw-r-- 1 kanishka kanishka   256 Aug  9 17:59 fourth.c
-rw------- 1 kanishka kanishka     0 Aug  9 17:49 klm.txt
-rwxrwxr-x 1 kanishka kanishka 16312 Aug  8 15:33 linkex
-rw-rw-r-- 1 kanishka kanishka  4117 Aug 29 17:07 linkex.c
-rwxrwxr-x 1 kanishka kanishka 16352 Aug 27 18:38 nineteen
-rw-rw-r-- 1 kanishka kanishka  2231 Aug 27 18:38 nineteen.c
-rwxrwxr-x 1 kanishka kanishka 16184 Aug 10 18:01 ninth
-rw-rw-r-- 1 kanishka kanishka   872 Aug 10 18:01 ninth.c
-rw-rw-r-- 4 kanishka kanishka    21 Aug 29 17:44 one.txt
-rw-rw-r-- 1 kanishka kanishka  1529 Aug 29 19:12 p20.c
-rw-rw-r-- 1 kanishka kanishka  1628 Aug 29 19:14 p21.c
-rw-rw-r-- 1 kanishka kanishka  2149 Aug 29 19:17 p22.c
-rw-rw-r-- 1 kanishka kanishka  2231 Aug 29 19:22 p23.c
-rw-rw-r-- 1 kanishka kanishka  1860 Aug 29 19:25 p24.c
-rw-rw-r-- 1 kanishka kanishka  2480 Aug 29 19:27 p25.c
-rw-rw-r-- 1 kanishka kanishka  1878 Aug 29 19:31 p26.c
-rw-rw-r-- 1 kanishka kanishka  7623 Aug 29 19:32 p27.c
-rw-rw-r-- 1 kanishka kanishka  7540 Aug 29 19:34 p27b.c
-rw-rw-r-- 1 kanishka kanishka   776 Aug 29 19:35 p27c.c
-rw-rw-r-- 1 kanishka kanishka   403 Aug 28 07:56 p27d.c
-rw-rw-r-- 1 kanishka kanishka   471 Aug 28 07:59 p27e.c
-rw-rw-r-- 1 kanishka kanishka   681 Aug 28 15:58 p28.c
-rw-rw-r-- 1 kanishka kanishka  1364 Aug 28 17:03 p29.c
drwxrwxr-x 2 kanishka kanishka  4096 Aug 28 18:56 p30
-rwxrwxr-x 1 kanishka kanishka 16008 Aug 27 23:48 random
-rwxrwxr-x 1 kanishka kanishka 15768 Aug  8 16:59 second
-rw-rw-r-- 1 kanishka kanishka    55 Aug  8 16:59 second.c
-rwxrwxr-x 1 kanishka kanishka 16128 Aug 10 16:38 seventh
-rw-rw-r-- 1 kanishka kanishka   446 Aug 10 16:38 seventh.c
-rwxrwxr-x 1 kanishka kanishka 16088 Aug 20 17:40 sixteen1
-rw-rw-r-- 1 kanishka kanishka   331 Aug 20 17:40 sixteen1.c
-rwxrwxr-x 1 kanishka kanishka 16088 Aug 20 17:40 sixteen2
-rw-rw-r-- 1 kanishka kanishka   312 Aug 20 17:40 sixteen2.c
-rwxrwxr-x 1 kanishka kanishka 16232 Aug 10 12:17 sixth
-rw-rw-r-- 1 kanishka kanishka   253 Aug 10 12:17 sixth.c
-rwxrwxr-x 1 kanishka kanishka 16216 Aug 10 19:35 tenth
-rw-rw-r-- 1 kanishka kanishka   390 Aug 10 19:35 tenth.c
-rw-rw-r-- 1 kanishka kanishka    45 Aug 29 19:17 test.txt
-rw-rw-r-- 1 kanishka kanishka   195 Aug 27 23:48 testp26.c
-rwxrwxr-x 1 kanishka kanishka 16040 Aug  9 17:25 third
-rwxrwxr-x 1 kanishka kanishka 16144 Aug 11 12:00 thirtheen
-rw-rw-r-- 1 kanishka kanishka   542 Aug 11 12:00 thirtheen.c
-rw-rw-r-- 1 kanishka kanishka   147 Aug 29 18:18 three.txt
-rwxrwxr-x 1 kanishka kanishka 16216 Aug 11 11:14 tweleth
-rw-rw-r-- 1 kanishka kanishka   950 Aug 11 11:14 tweleth.c
-rw-rw-rw- 1 kanishka kanishka    60 Aug 29 17:50 two.txt
-rwxrwx--- 1 kanishka kanishka     0 Aug 29 17:16 xyz.txt

./16:
total 24
-rwxrwxr-x 1 kanishka kanishka 16304 Aug 29 18:36 a.out
-rw-rw-r-- 1 kanishka kanishka  2588 Aug 29 18:38 p16.c
-rw-rw-r-- 1 kanishka kanishka   111 Aug 29 18:36 test.txt

./17:
total 96
-rwxrwxr-x 1 kanishka kanishka 16456 Aug 29 18:49 a.out
-rwxrwxr-x 1 kanishka kanishka 16216 Aug 21 20:52 first
-rwxrwxr-x 1 kanishka kanishka 16456 Aug 22 08:36 second
-rwxrwxr-x 1 kanishka kanishka 16152 Aug 21 21:18 test
-rw-rw-r-- 1 kanishka kanishka   589 Aug 21 21:17 testing.c
-rw-rw-r-- 1 kanishka kanishka  4312 Aug 29 18:53 ticket_add.c
-rw-rw-r-- 1 kanishka kanishka    40 Aug 29 18:51 ticket_count.txt
-rw-rw-r-- 1 kanishka kanishka   324 Aug 29 18:51 ticket_details.txt
-rw-rw-r-- 1 kanishka kanishka  1361 Aug 29 18:59 ticket_initial.c

./18:
total 36
-rwxrwxr-x 1 kanishka kanishka 16464 Aug 29 19:01 a.out
-rw-rw-r-- 1 kanishka kanishka  1977 Aug 29 19:05 initial.c
-rw-rw-r-- 1 kanishka kanishka  4141 Aug 29 19:04 p18.c
-rw-rw-r-- 1 kanishka kanishka    24 Aug 29 19:02 record.txt

./p30:
total 0
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 


====================================================================================================================================================================================
*/
