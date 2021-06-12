#include<stdio.h>
int main()
{
int x[10],y,size,swappingDone,e,f,g;
size=10;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

swappingDone=0;
while(1)
{
swappingDone=0;
/*loop for odd */
for(e=1;e<size;e=e+2)
{
if(e+1>=size) break;
if(x[e+1]<x[e])
{
g=x[e+1];
x[e+1]=x[e];
x[e]=g;
swappingDone=1;
}
}
/* loop for even */
for(f=0;f<size;f=f+2)
{
if(f+1>=size) break;
if(x[f+1]<x[f])
{
g=x[f+1];
x[f+1]=x[f];
x[f]=g;
swappingDone=1;
}
}
if(swappingDone==0) break;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}