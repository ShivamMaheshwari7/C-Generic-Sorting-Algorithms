#include<stdio.h>
int main()
{
int x[10],y,e,f,g,pp,stack[10][2],top,lowerBound,upperBound,lb,ub;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
lowerBound=0;
upperBound=9;
top=10;
// push lower bound,upper bound on stack
top--;
stack[top][0]=lowerBound;
stack[top][1]=upperBound;
while(top!=10)          // enter the loop construct if the stack is not empty
{
// pop from stack into lb,ub
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
// move e forward
while(e<ub && x[e]<=x[lb]) e++;
// move f backward
while(x[f]>x[lb]) f--;
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
pp=f;
}
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}