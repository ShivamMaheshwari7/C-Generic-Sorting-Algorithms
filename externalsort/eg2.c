#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int y,num;
FILE *f;
srand(time(0));
f=fopen("data.d","wb");
for(y=0;y<150000000;y++)
{
num=rand();
fwrite(&num,sizeof(int),1,f);
}
fclose(f);
return 0;
}