/*
====================================================================================================================================================================================
Name : 2.c
Author : Patenge Kanishka
Description :
Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.

Date : 8th August 2024
===================================================================================================================================================================================
*/

#include<stdio.h>
int main()
{
	while(1);
	return 0;
}


/*
====================================================================================================================================================================================
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ gcc 2.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ ./a.out &
[1] 4908
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ cat /proc/4908/status
Name:	a.out
Umask:	0002
State:	R (running)
Tgid:	4908
Ngid:	0
Pid:	4908
PPid:	3140
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	4908
NSpid:	4908
NSpgid:	4908
NSsid:	3140
VmPeak:	    2544 kB
VmSize:	    2484 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	     896 kB
VmRSS:	     896 kB
RssAnon:	       0 kB
RssFile:	     896 kB
RssShmem:	       0 kB
VmData:	      92 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1672 kB
VmPTE:	      36 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	1
SigQ:	0/30125
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	fff
Cpus_allowed_list:	0-11
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	0
nonvoluntary_ctxt_switches:	80
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/abc$ 


====================================================================================================================================================================================
*/
