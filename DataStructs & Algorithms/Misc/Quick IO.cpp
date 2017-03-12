// This file just includes some quick I/O for better run time on problems.
// Shouldn't be used in competitive programming settings as cin/cout with sync disabled is fast enough
// Note that I did not write this. I found this online and could not find an author.

#include<cstdio>
#define gc getchar_unlocked
 
void scanint(int &x)
{
	int c=gc();
	x = 0;
    for (;(c<48 || c>57);c = gc());
    for (;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
void scannegint(int &x)
{
    bool neg = false;
	int c=gc();
	x = 0;
    for (;(c!=45 && (c<48 || c>57));c = gc());
    if (c == '-') {
        neg = true;
        c = gc();
    }
    for (;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x = (x^0xFFFFFFFF)+1;
}
void scanint(long long int &x)
{
	int c=gc();
	x = 0;
    for (;(c<48 || c>57);c = gc());
    for (;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


// Other Fast IO's found (Couldn't find an author anywhere)
// TODO: Might want to change multiplication by 10 to (x<<1)+(x<<3)
#define llu long long unsigned
#define lld long long
#define ld long
 
int scan_d() {
	int ip=getchar_unlocked(),ret=0,flag=1;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())
	if(ip=='-'){
		flag=-1;
		ip=getchar_unlocked();
		break;
	}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';
	return flag*ret;
}
 
ld scan_ld() {
	int ip=getchar_unlocked(),flag=1;
	ld ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())
		if(ip=='-'){
			flag=-1;
			ip=getchar_unlocked();
			break;
		}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';
	return flag*ret;
}
 
lld scan_lld() {
	int ip=getchar_unlocked(),flag=1;
	lld ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())
		if(ip=='-'){
			flag=-1;
			ip=getchar_unlocked();
			break;
		}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';
	return flag*ret;
}
 
llu scan_llu() {
	int ip=getchar_unlocked();
	llu ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';
	return ret;
}
 
inline void print_d(int n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=10;
	char output_buffer[10];
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<10);
}
 
void print_ld(ld n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=11;
	char output_buffer[11];
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<11);
}
 
void print_lld(lld n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=21;
	char output_buffer[21];
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<21);
}
 
void print_llu(llu n) {
	int i=21;
	char output_buffer[21];
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<21);
}
 
void println_d(int n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=10;
	char output_buffer[11];
	output_buffer[10]='\n';
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<11);
}
 
void println_ld(ld n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=11;char output_buffer[12];
	output_buffer[11]='\n';
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<12);
}
 
void println_lld(lld n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<22);
}
 
void println_llu(llu n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<22);
}
 
char sp;
void printsp_d(int n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=10;
	char output_buffer[11];
	output_buffer[10]=sp;
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<11);
}
 
void printsp_ld(ld n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=11;
	char output_buffer[12];
	output_buffer[11]=sp;
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<12);
}
 
void printsp_lld(lld n) {
	if(n<0){
		n=-n;
		putchar_unlocked('-');
	}
	int i=21;
	char output_buffer[22];
	output_buffer[21]=sp;
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}
	while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<22);
}
 
void printsp_llu(llu n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]=sp;
	do{
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}while(++i<22);
}
