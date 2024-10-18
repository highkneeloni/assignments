#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
void count(char *p1,char*fname)
{
int handle,ccnt=0,wcnt=0,lcnt=0;
char ch;
handle=open(fname,O_RDONLY);
if(handle==-1)
{
printf("\n File %s Not Found... ",fname);
}
else
{
while(read(handle,&ch,1))
{
if(ch==' '||ch=='\t')
wcnt++;
else if(ch=='\n')
{
lcnt++;
wcnt++;
}
ccnt++;
}
close(handle);
if(strcmp(p1,"C")==0)
{
printf("\nTotal No. of character in file = %d",ccnt);
}
else if(strcmp(p1,"W")==0)
{
printf("\nTotal No. of words in file = %d",wcnt);
}
else if(strcmp(p1,"L")==0)
{
printf("\nTotal No. of Lines in file = %d",lcnt);
}
else
{

printf("\nInvalidOption.....\n");
}
}
}
int main()
{
char cmd[80],tok1[10],tok2[10],tok3[10],tok4[10];
int n;
while(1)
{
printf("\nMYSHELL $]");
fgets(cmd,80,stdin);
n=sscanf(cmd,"%s%s%s%s",tok1,tok2,tok3,tok4);
switch(n)
{
case 1:
if(fork()==0)
{
execlp(tok1,tok1,NULL);
}
wait(0);
break;
case 2 :
if(fork()==0)
{
execlp(tok1,tok1,tok2,NULL);
}
wait(0);
break;
case 3:
if(strcmp(tok1,"count")==0)
{
count(tok2,tok3);
}
else
{
if(fork()==0)
{
execlp(tok1,tok1,tok2,tok3,NULL);
}
wait(0);
}
break;
case 4 :
if(fork()==0)
{
execlp(tok1,tok1,tok2,tok3,tok4,NULL);
}
wait(0);
break;
}
}

}
