#include<stdio.h>
#include <unistd.h>
void main()
{
 int a[2],x;
 pipe(a);
 char s[20],s1[20];
 x=fork();

 if (x>0)
 {
   printf("Parent process is running:\n");
   printf("Enter the String:\n");
   scanf("%s",s);
   write(a[1],s,10);
 }
else if(x==0)
 {
  read(a[0],s1,10);
  printf("Child process running:\n");
  printf("String Entered is:%s\n",s1);
 }
else
 printf("Error Message:");

}
