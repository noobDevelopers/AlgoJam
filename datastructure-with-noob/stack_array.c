#include<stdio.h>

#define n 5
int stack[n];
int top=-1;
void push()
{
    int x;
    if(top==n-1)
    {
    printf("Overflow\n");
    
    }
    printf("enter data\n");
    scanf("%d",&x);
    top=top+1;
    stack[top]=x;
}

void pop()
{
    int x;
    if(top==-1)
    {
    printf("Underflow\n");
        }
    x=stack[top];
    printf("The popped element is %d\n",x);
    top=top-1;
}

void peek()
{
int x;
x=stack[top];
printf("THe top most element is %d\n",x);
}

void display()
{
  int i;
  printf("abc\n");
  for(i=top;i>=0;i--)
  {
      printf("%d ",stack[i]);
  }
  printf("\n");
}
int main() 
{
int ch;
do
{   printf("1 for Push \n2 for pop \n3 for peek \n4 for display \n0 for exit\n");
    
    printf("enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        case 4:
        display();
        break;
        default:
        printf("Invalid Choice\n");
        break;
    }
}while(ch!=0);
  return 0;
}

