#include<stdio.h>
int main()
{
int num,i;
FILE *f;
f=fopen("datasort.d","rb");

fseek(f,500000000,SEEK_SET);

for(i=0;i<15000;i++)
{
fread(&num,sizeof(int),1,f);
printf("%d  ",num);
}

fclose(f);
return 0;
}