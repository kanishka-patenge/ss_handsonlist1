/*
====================================================================================================================================================================================
Name : 3.c
Author : Patenge Kanishka
Description :
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call

Date : 8th August 2024
===================================================================================================================================================================================

*/



#include <stdio.h>
#include <fcntl.h>

int main()
{
  int fd = creat("xyz.txt",00770);
  if(fd == -1)
  {
    printf("File is not able to create \n");
    
  }
  else
  {
    printf("File created success fully \n and file descriptor value is : %d \n",fd);
  }
  return 0;
}

/*
===================================================================================================================================================================================
output:
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ls
0214  456  aaaaa       eigth.c     fifth       fourth.c  nineteen.c  p18    p24.c   p27c.c  p30        seventh     sixteen2.c  testp26.c    three.txt
123   555  abc         eleventh    fifth.c     klm.txt   ninth       p20.c  p25.c   p27d.c  random     seventh.c   sixth       test.txt     tweleth
1.c   789  a.out       eleventh.c  fourteen    linkex    ninth.c     p21.c  p26.c   p27e.c  second     sixteen1    sixth.c     third        tweleth.c
3.c   888  common.txt  fifteen     fourteen.c  linkex.c  one.txt     p22.c  p27b.c  p28.c   second.c   sixteen1.c  tenth       thirtheen    two.txt
444   a    eigth       fifteen.c   fourth      nineteen  p16         p23.c  p27.c   p29.c   seventeen  sixteen2    tenth.c     thirtheen.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 3.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
File created success fully 
 and file descriptor value is : 3 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ls
0214  456  aaaaa       eigth.c     fifth       fourth.c  nineteen.c  p18    p24.c   p27c.c  p30        seventh     sixteen2.c  testp26.c    three.txt
123   555  abc         eleventh    fifth.c     klm.txt   ninth       p20.c  p25.c   p27d.c  random     seventh.c   sixth       test.txt     tweleth
1.c   789  a.out       eleventh.c  fourteen    linkex    ninth.c     p21.c  p26.c   p27e.c  second     sixteen1    sixth.c     third        tweleth.c
3.c   888  common.txt  fifteen     fourteen.c  linkex.c  one.txt     p22.c  p27b.c  p28.c   second.c   sixteen1.c  tenth       thirtheen    two.txt
444   a    eigth       fifteen.c   fourth      nineteen  p16         p23.c  p27.c   p29.c   seventeen  sixteen2    tenth.c     thirtheen.c  xyz.txt
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 


*/
