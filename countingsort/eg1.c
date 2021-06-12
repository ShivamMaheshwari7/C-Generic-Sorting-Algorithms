#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10],y,lb,ub,largest,i,num,k;
int *tmp;
lb=0;
ub=9;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

largest=x[lb];
y=lb+1;
while(y<=ub)
{
if(x[y]>largest) largest=x[y];
y++;
}

tmp=(int *)malloc(sizeof(int)*(largest+1));
for(y=0;y<=largest;y++)
{
tmp[y]=0;
}

y=lb;
while(y<=ub)
{
tmp[x[y]]++;
y++;
}

k=lb;
y=0;
while(y<=largest)
{
num=tmp[y];
for(i=1;i<=num;i++)
{
x[k]=y;
k++;
}
y++;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);

free(tmp);
return 0;
}