#include<stdio.h>
int main()
{
int x[10],y,largestNumberIndex,g,i,size,e,f;
size=10;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

while(size>1)
{
largestNumberIndex=0;
for(i=1;i<size;i++)
{
if(x[i]>x[largestNumberIndex]) largestNumberIndex=i;
}
if(largestNumberIndex==(size-1))
{
size--;
continue;
}
for(e=0,f=largestNumberIndex;e<f;e++,f--)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
for(e=0,f=size-1;e<f;e++,f--)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
size--;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}