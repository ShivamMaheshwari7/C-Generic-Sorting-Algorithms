#include<stdio.h>
int main()
{
int x[10],y,z,num;
y=0;
while(y<=9)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
y=1;
while(y<=9)
{
num=x[y];
z=y-1;
while(z>=0 && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
y=0;
while(y<=9)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}