#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node 
{
    //declare coeff as data type integer to store the coefficient of the polynomial.
    //decalre expo as data type integer to store the exponent of the polynomial.
    struct node *link;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *temp=NULL;

struct node *getnode()
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    return ptr;
}

struct node *addnode(struct node *start,int coeff,int expo)
{

    temp=getnode();
    //store coeff in the coeff part of the node
    //store expo in the expo part of the node
    if(start==NULL)
    {
        start=temp;
        temp->link=NULL;
        return start;
    }
    temp->link=start;
    start=temp;
    return start;
}

struct node *add_poly(struct node *start3 ,struct node *start2, struct node *start1)
{
 
  int sum_coeff,count=0;
  struct node *ptr1,*ptr2;
  ptr1=start1->link;
  ptr2=start2->link;
  while(ptr1!=NULL&&ptr2!=NULL)
  {
   if(ptr1->expo==ptr2->expo)
    {
     sum_coeff=ptr1->coeff+ptr2->coeff;
     start3=addnode(start3,sum_coeff,ptr1->expo);
     ptr1=ptr1->link;
     ptr2=ptr2->link;
     count++;
    }
   else if(ptr1->expo>ptr2->expo)
    {
      start3=addnode(start3,ptr1->coeff,ptr1->expo);
      ptr1=ptr1->link;
      count++;
    }
   else
   {
    start3=addnode(start3,ptr2->coeff,ptr2->expo);
    ptr2=ptr2->link;
    count++;
   }
  }
cout<<count<<endl;
return start3;
} 

//Create a function display_poly which will display the resultant polynomial and takig the arguement start3
struct node *display_poly()
{


    
}

int main()
{   
    int enter,coe,exp;
    cout<<"Enter First Poly"<<endl;
    while(enter!=-1)
    {
        
        cout<<"Enter the coefficient and exponent of x"<<endl;
        cin>>coe>>exp;
        start1=addnode(start1,coe,exp);
        cout<<"Press 0 to add term and -1 to end"<<endl;
        cin>>enter;
    }
    cout<<endl<<"Enter Second polynomial"<<endl;
    enter=0;
    while(enter!=-1)
    {
        cout<<"Enter the coefficient and exponent of x"<<endl;
        cin>>coe>>exp;
        start2=addnode(start2,coe,exp);
        cout<<"Press 0 to add term and -1 to end"<<endl;
        cin>>enter;
    }
    start3=add_poly(start3,start2,start1);
    start1=displaypoly(start1);
    return 0;
}