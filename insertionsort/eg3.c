#include<stdio.h>
void insertionSort(int *x,int size)
{
int y,z,num,ep;
ep=size-1;
for(y=1;y<=ep;y++)
{
for(num=x[y],z=y-1;z>=0 && x[z]>num;z--) x[z+1]=x[z];
x[z+1]=num;
}
}
int main()
{
int x[5],y;
y=0;
while(y<=4)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
insertionSort(x,5);
y=0;
while(y<=4)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}