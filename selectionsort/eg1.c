#include<stdio.h>
int main()
{
int x[10],y,e,f,g,si;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
for(e=0;e<=8;e++)
{
si=e;
for(f=e+1;f<=9;f++)
{
if(x[f]<x[si])
{
si=f;
}
}
g=x[si];
x[si]=x[e];
x[e]=g;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}