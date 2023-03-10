#include<stdio.h>
#include<conio.h>
int gcd(int a,int b)
{     if(a>b)
	{
	if(a%b==0)
	{
	 return b;
	}
	if(b==0)
	{
	 return a;
	}
	else
	{
	return gcd(a%b,b);
	}


	}

	if(a<b)
	{
	 if(b%a==0)
	 {

	  return a;
	 }
	 else if(a==0)
	 {
	  return b;
	 }
	 else
	 {
	  return gcd(b%a,a);
	 }


	}

	}
void main()
{	int a,b;
clrscr();
printf("enter the number1:");
scanf("%d",&a);
printf("Enter the numnber2:");
scanf("%d",&b);
printf("Gcd of a&b=%d",gcd(a,b));


  getch();
 }