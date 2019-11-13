#include <iostream>
long fib_recursion(long n)
{
    long n_fibonacci; 
    if (n==0)
        n_fibonacci = 0;
    else if (n==1)
        n_fibonacci = 1;
    else
        n_fibonacci = fib_recursion(n-1) + fib_recursion(n-2);
    return n_fibonacci;
}

long fib_for(long n)
{
    long a = 1;
    long b = 0;
    for(int i = 0; i<n; i++)
    {
        long a1 = a+b;
        long b1 = a;
        a = a1;
        b = b1;
    }
    return b;
}

int main(void)
{
    long number=10;
    std::cout<< "Fibonacci of "<< number<<" (with recursion) = " <<fib_recursion(number)<<"\n";
    std::cout<< "Fibonacci of "<< number<<" (with for cycle) = " <<fib_for(number)<<"\n";
    return 0;
}