#include<stdio.h>
#include <unistd.h>
void main()
{
 int a[2],d[2],x;
 pipe(a);
 pipe(d);
 char s[20],s1[20],b[20],c[20];
 x=fork();

 if (x>0)
 {
   printf("-----Parent is Writing-----\n");
   printf("Enter the String:\n");
   scanf("%s",s);
   write(d[1],s,10);
   read(a[0],b,10);
   printf("------Parent is Reading-------\n");
   printf("String Entered is:%s\n",b);
   
 }
else if(x==0)
 {
  read(d[0],s1,10);
  printf("---------Child is Reading--------\n");
  printf("String Entered is:%s\n",s1);
  printf("----------Child is Writing-------\n");
  printf("Enter the String:\n");
  scanf("%s",c);
  write(a[1],c,10);
 }
else
 printf("Error Message:");

}
