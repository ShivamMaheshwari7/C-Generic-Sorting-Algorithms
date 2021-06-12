#include<stdio.h>

void stoogeSort(int *x,int lb,int ub)
{
int size,g;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
size=(ub-lb)+1;
if(size>2)
{
stoogeSort(x,lb,lb+(size-(size/3))-1);
stoogeSort(x,lb+(size/3),ub);
stoogeSort(x,lb,lb+(size-(size/3))-1);
}
}

int main()
{
int x[10],y,lb,ub;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

lb=0;
ub=9;
stoogeSort(x,lb,ub);

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}