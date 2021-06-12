#include<stdio.h>
int main()
{
int x[10],y,lb,ub,e,f,g,swappingDone;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

lb=0;
ub=9;
swappingDone=0;
while(lb<ub)
{
swappingDone=0;
for(e=lb;e<ub;e++)
{
f=e+1;
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swappingDone=1;
}
}
if(swappingDone==0) break;
ub--;
swappingDone=0;
for(f=ub;f>lb;f--)
{
e=f-1;
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swappingDone=1;
}
}
if(swappingDone==0) break;
lb++;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}