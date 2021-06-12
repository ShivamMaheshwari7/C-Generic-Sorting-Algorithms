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
for(y=1;y<=9;y++)
{
for(num=x[y],z=y-1;z>=0 && x[z]>num;z--) x[z+1]=x[z];
x[z+1]=num;
}
y=0;
while(y<=9)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}