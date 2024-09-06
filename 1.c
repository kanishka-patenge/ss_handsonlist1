/*
====================================================================================================================================================================================
Name : 1.c
Author : Patenge Kanishka
Description :
1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)

Date : 8th August 2024
===================================================================================================================================================================================

*/




#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

void soft_link()
{
    char a[100],b[100];
    printf("Enter the directory for File 1 : ");
    scanf("%s",a);
    printf("Enter the directory for File 2 : ");
    scanf("%s",b);
    int sl = symlink(a,b);
    if(sl == 0)
      printf("Soft Link is sucessful \n");
    else
      printf("Soft Link is failed \n");
}

void hard_link()
{
    char a[100],b[100];
    printf("Enter the directory for File 1 : ");
    scanf("%s",a);
    printf("Enter the directory for File 2 : ");
    scanf("%s",b);
    int sl = link(a,b);
    if(sl == 0)
      printf("Hard Link is sucessful \n");
    else
      printf("Hard Link is failed \n");
}

void fifo_file()
{
    char a[100];
    printf("Enter the name of the File : ");
    scanf("%s",a);
    
    int sl = mkfifo(a,S_IFIFO);
    if(sl == 0)
      printf("fifo file is sucessful \n");
    else
      printf("fifo file is failed \n");
}

int main()
{
	    printf("1. create soft link \n");
	    printf("2. create hard link \n");
	    printf("3. create fifo file \n");
	    
	    do
	    {
	        printf("Enter your choice : ");
	        int choice;
	        scanf("%d",&choice);
	        if(choice == 1)
	              soft_link();
    
	        else if(choice == 2)
	              hard_link();
	              
	        else if(choice == 3)
	              fifo_file();
	    
	        else
	        {
	          printf("Invalid choice \n");
	          break;
	        }
	        
	        
	    }while(1);
	    return 0;
}


/*

===================================================================================================================================================================================
output:
(i) shell command:


kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ln -s one.txt 888
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ln one.txt 444
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ mkfifo 555
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ls
0214  555    abc         eleventh    fifth.c        fourth.c  nineteen.c  p18    p24.c   p27c.c  p30        seventh     sixteen2.c  testp26.c    three.txt
123   789    a.out       eleventh.c  file_create.c  klm.txt   ninth       p20.c  p25.c   p27d.c  random     seventh.c   sixth       test.txt     tweleth
1.c   888    common.txt  fifteen     fourteen       linkex    ninth.c     p21.c  p26.c   p27e.c  second     sixteen1    sixth.c     third        tweleth.c
444   a      eigth       fifteen.c   fourteen.c     linkex.c  one.txt     p22.c  p27b.c  p28.c   second.c   sixteen1.c  tenth       thirtheen    two.txt
456   aaaaa  eigth.c     fifth       fourth         nineteen  p16         p23.c  p27.c   p29.c   seventeen  sixteen2    tenth.c     thirtheen.c  xyz.txt


(ii) System call: 


kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 1.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out
1. create soft link 
2. create hard link 
3. create fifo file 
Enter your choice : 1
Enter the directory for File 1 : one.txt
Enter the directory for File 2 : 123
Soft Link is sucessful 
Enter your choice : 2
Enter the directory for File 1 : one.txt
Enter the directory for File 2 : 456
Hard Link is sucessful 
Enter your choice : 3
Enter the name of the File : 789
fifo file is sucessful 
Enter your choice : 4
Invalid choice 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ls
0214  a           eigth       fifteen.c      fourteen.c  nineteen    p16    p23.c   p27.c   p29.c     seventeen   sixteen2    tenth.c    thirtheen.c  xyz.txt
123   aaaaa       eigth.c     fifth          fourth      nineteen.c  p18    p24.c   p27c.c  p30       seventh     sixteen2.c  testp26.c  three.txt
1.c   abc         eleventh    fifth.c        fourth.c    ninth       p20.c  p25.c   p27d.c  random    seventh.c   sixth       test.txt   tweleth
456   a.out       eleventh.c  file_create.c  klm.txt     ninth.c     p21.c  p26.c   p27e.c  second    sixteen1    sixth.c     third      tweleth.c
789   common.txt  fifteen     fourteen       linkex      one.txt     p22.c  p27b.c  p28.c   second.c  sixteen1.c  tenth       thirtheen  two.txt
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat one.txt
This is to check the copy operations. 

step -1

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat 123
This is to check the copy operations. 

step -1

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat 456
This is to check the copy operations. 

step -1

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 
=================================================================================================================================================================================

*/
