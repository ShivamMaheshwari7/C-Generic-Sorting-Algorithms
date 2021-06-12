#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int y;
srand(time(0));
for(y=0;y<=9;y++) printf("%d  ",rand());
printf("\n");
return 0;
}