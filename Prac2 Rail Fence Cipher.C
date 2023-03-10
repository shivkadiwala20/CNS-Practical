#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()
{
 int i,j,k,len,rails,count,code[100][100];
 char str[100];
 clrscr();
 printf("\n\t\t Rail Fence Technique");
 printf("\n\nEnter the input string : ");
 fflush(stdin);
 gets(str);
 len=strlen(str);

printf("Enter number of rails\n");
scanf("%d",&rails);
for(i=0;i<rails;i++)
{
 for(j=0;j<len;j++)
 {
  code[i][j]=0;
 }
}count=0;
j=0;
while(j<len)
{
if(count%2==0)
{
 for(i=0;i<rails;i++)
 {
  code[i][j]=(int)str[j];
  j++;
 }
}
else
 {
    for(i=rails-2;i>0;i--)
    {
	code[i][j]=(int)str[j];
	j++;
     }
 }
  count++;
}
printf("Encrypted code is:\n");
for(i=0;i<rails;i++)
{
 for(j=0;j<len;j++)
 {
   if(code[i][j] !=0)
   printf("%c",code[i][j]);
  }
}
printf("\n");    	  //repeating above procedure
count=0;
j=0;   
printf("Decrypted code is :\n");
while(j<len)
{
if(count%2==0)
{
 for(i=0;i<rails;i++)
 {
  //strcpy(code[i][j],str[j]);
  printf("%c",code[i][j]);
  j++;
 }

}
else
{

 for(i=rails-2;i>0;i--)
 {
  printf("%c",code[i][j]);
 j++;
 }
}

count++;
}
printf("\n");
getch();
return 0;
}