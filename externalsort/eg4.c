#include<stdio.h>
#include<stdlib.h>

int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb])
{
e++;
}
while(x[f]>x[lb])
{
f--;
}
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lb,int ub)
{
int pp;
if(ub<=lb) return;
pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
}

int main()
{
int y,num,i,*x;
FILE *f,*file;
f=fopen("data.d","rb");
fseek(f,4000000,SEEK_SET);

x=(int *)malloc(sizeof(int)*1000);
for(i=0;i<1000;i++)
{
fread((x+i),sizeof(int),1,f);
}

fclose(f);

//quickSort(x,0,1000-1);

file=fopen("d.d","wb");
for(i=0;i<1000;i++)
{
fwrite((x+i),sizeof(int),1,file);
}
fclose(file);
free(x);

/*
file=fopen("d.d","rb");
for(y=0;y<1000;y++)
{
fread(&num,sizeof(int),1,file);
printf("%d  ",num);
}

fclose(file);
*/
return 0;
}