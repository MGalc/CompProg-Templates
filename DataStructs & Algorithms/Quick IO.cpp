// This file just includes some quick I/O for better runtime on problems.
// Won't be used in competitive programming settings as cin/cout with sync disabled is fast enough
// Note that I did not write this. I found this online and could not find an author.

#include<cstdio>
#define gc getchar_unlocked
 
void scanint(int &x)
{
	register int c=gc();
	x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
void scanint(long long int &x)
{
	register int c=gc();
	x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
