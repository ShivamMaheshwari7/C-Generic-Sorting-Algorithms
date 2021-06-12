#include<stdio.h>
#include<stdlib.h>
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
int *x,y,req;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
y=0;
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
insertionSort(x,req);
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}