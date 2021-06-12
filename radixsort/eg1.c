#include<stdlib.h>
#include<stdio.h>
typedef struct __queue_node
{
int num;
struct __queue_node *next;
}QueueNode;
typedef struct __queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;
void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}
void addToQueue(Queue *queue,int num)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->num=num;
t->next=NULL;
if(queue->start==NULL)
{
queue->start=t;
queue->end=t;
}
else
{
queue->end->next=t;
queue->end=t;
}
queue->size++;
}
int removeFromQueue(Queue *queue)
{
int num;
QueueNode *t;
num=queue->start->num;
t=queue->start;
queue->start=queue->start->next;
if(queue->start==NULL) queue->end=NULL;
free(t);
queue->size--;
return num;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=queue->start->next;
queue->size--;
free(t);
}
queue->end=NULL;
queue->size=0;
}
int main()
{
int x[10],y,e,f,i,num,largest,dc,k;
Queue queues[10];

for(i=0;i<=9;i++) initQueue(&queues[i]);

for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
}
e=10;
f=1;
k=1;
while(k<=dc)
{
// spread out in 10 queues according to digit at kth place
y=0;
while(y<=9)
{
num=x[y];
i=(num%e)/f;
addToQueue(&queues[i],num);
y++;
}
// collect all numbers from 10 queues and keep it in array
i=0;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
x[i]=num;
i++;
}
y++;
}
e=e*10;
f=f*10;
k++;
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}