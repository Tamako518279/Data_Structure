#include <stdio.h>
#include <stdlib.h>
#include <math.h>




long Fact(long n)   //阶乘
{
    if(n == 0) return 1;
    else return n*Fact(n-1);
}

long Fib(long n)  //二阶斐波那契数列
{
    if(n == 1 || n == 2) return 1;
    else return Fib(n-1) + Fib(n-2);
}

/*分治法
void p(参数表)
{
   if(递归结束条件成立)  可直接求解;   //递归终止条件
   else p(较小的参数);               //递归步骤
}

*/
void move(int *m,char A,int n,char C)
{ 
    (*m)++;
}
void Hanoi(int* m,int n,char A,char B,char C)
{
 
  if(n == 1) move(m,A,1,C);
  else 
  {
    Hanoi(m,n-1,A,C,B);
    move(m,A,n,C);
    Hanoi(m,n-1,B,A,C);
  }
}

int main(void)
{
    int count = 0;
    int n = 10;
    Hanoi(&count,n,'A','B','C');
    printf("%d %ld %ld\n",count,Fact(n),Fib(n));
    return 0;
    
}

