#include<stdio.h>
#include<stdlib.h>

typedef struct __stack_node
{
int data;
struct __stack_node *next;
}StackNode;

typedef struct __stack
{
StackNode *top;
int size;
}Stack;

void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}

void push(Stack *stack,int data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=data;
t->next=stack->top;
stack->top=t;
stack->size++;
}

int pop(Stack *stack)
{
int data;
StackNode *t;
data=stack->top->data;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
free(t);
return data;
}

int isEmpty(Stack *stack)
{
return stack->size==0;
}

void clearStack(Stack *stack)
{
StackNode *t;
while(stack->top!=NULL)
{
t=stack->top;
stack->top=stack->top->next;
stack->size--;
free(t);
}
stack->size=0;
}

int main()
{
int x[10],y,largest,smallest,range,num,j;
Stack *stacks;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

largest=x[0];
smallest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
if(x[y]<smallest) smallest=x[y];
}
range=(largest-smallest)+1;
stacks=(Stack *)malloc(sizeof(Stack)*range);
for(y=0;y<range;y++) initStack(&stacks[y]);
for(y=0;y<=9;y++)
{
num=x[y];
push(&stacks[num-smallest],num);
}

/* collection of numbers from Lists */
j=0;
for(y=0;y<range;y++)
{
while(!isEmpty(&stacks[y]))
{
num=pop(&stacks[y]);
x[j]=num;
j++;
}
}

for(y=0;y<range;y++) clearStack(&stacks[y]);
free(stacks);
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}