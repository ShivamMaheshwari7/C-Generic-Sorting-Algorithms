#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int size,*tmp,lb3,ub3,i1,i2,i3;
size=ub2-lb1+1;
tmp=(int *)malloc(sizeof(int)*size);
lb3=0;
ub3=size-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=lb3;
i1=lb1;
while(i3<=ub3)
{
x[i1]=tmp[i3];
i1++;
i3++;
}
free(tmp);
}

void insertionSort(int *x,int lb,int ub)
{
int num,z,y;
for(y=lb+1;y<=ub;y++)
{
num=x[y];
z=y-1;
while(z>=lb && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
}
}

int main()
{
int y,num,size,lowerBound,upperBound,lb1,ub1,lb2,ub2;
int *x;
FILE *f;
size=5000;

/* data entry part in file start here */
srand(time(0));
f=fopen("data.d","wb");
for(y=1;y<=size;y++)
{
num=rand();
fwrite(&num,sizeof(int),1,f);
}
fclose(f);
/* data entry part in file ends here */

x=(int *)malloc(sizeof(int)*size);
f=fopen("data.d","rb");
for(y=0;y<size;y++)
{
fread(&x[y],sizeof(int),1,f);
}
fclose(f);

lowerBound=0;
upperBound=63;
while(lowerBound<size)
{
if(upperBound>=size) upperBound=size-1;
insertionSort(x,lowerBound,upperBound);
lowerBound=upperBound+1;
upperBound=lowerBound+63;
}

if(size>64)
{
lb1=0;
ub1=63;
lb2=ub1+1;
ub2=lb2+63;
while(lb2<size)
{
if(ub2>=size) ub2=size-1;
merge(x,lb1,ub1,lb2,ub2);
ub1=ub2;
lb2=ub1+1;
ub2=lb2+63;
}
}

f=fopen("datasort.d","wb");
for(y=0;y<size;y++)
{
fwrite(&x[y],sizeof(int),1,f);
}
fclose(f);
free(x);
return 0;
}