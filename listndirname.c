#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
void list(char *p1,char*dname)
{
DIR *dir;
struct dirent *entry;
struct stat info;
int cnt=0;
dir=opendir(dname);
if(dir==NULL)
{
printf("\n Directory %s Not Found. .. ",dname);
}
else
{
if(strcmp(p1,"F")==0)
{
while((entry=readdir(dir))!=NULL)
{
stat(entry->d_name,&info);
if(info.st_mode&&S_IFREG)
printf("%s\n",entry->d_name);
}
}
else if(strcmp(p1,"N")==0)
{
cnt=0;
while((entry=readdir(dir))!=NULL)
{
cnt++;
}
printf("\nTotal no. of entries in directory '%s' = %d ",dname,cnt);
}
else if(strcmp(p1,"I")==0)
{
while((entry=readdir(dir))!=NULL)
{

stat(entry->d_name,&info);
if(info.st_mode&&S_IFREG)
{
printf("File name =%s\t",entry->d_name);
printf("Inode=%d\n",info.st_ino);
}
}
}
}
}
int main()
{
char cmd[80],tok1[10],tok2[10],tok3[10],tok4[10];
int n;
while(1)
{
printf("\nMYSHELL $");
fgets(cmd,80,stdin);
n=sscanf(cmd,"%s%s%s%s",tok1,tok2,tok3,tok4);
switch(n)
{ case 1:
if(fork()==0)
{ execlp(tok1,tok1,NULL);
}
wait(0);
break;
case 2 :
if(fork()==0)
{ execlp(tok1,tok1,tok2,NULL);
}
wait(0);
break;
case 3:
if(strcmp(tok1,"list")==0)
{
list(tok2,tok3);
}
else
{
if(fork()==0)
{ execlp(tok1,tok1,tok2,tok3,NULL);
}
wait(0);
}
break;
case 4 :
if(fork()==0)
{ execlp(tok1,tok1,tok2,tok3,tok4,NULL);
}
wait(0);
break; } } }
