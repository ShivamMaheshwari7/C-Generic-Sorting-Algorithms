#include<stdio.h>
int main()
{
int num,i;
FILE *f;
f=fopen("datasort.d","rb");

for(i=0;i<5000;i++)
{
fread(&num,sizeof(int),1,f);
printf("%d  ",num);
}

fclose(f);
return 0;
}