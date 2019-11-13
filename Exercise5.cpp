#include <iostream>
#include <cmath>
int main(int argc, char **argv)
{
    int N=atoi(argv[1]); //casting to int
    int *arr = NULL;
    arr = new int[N];
    int *p = arr;
    for(int i =0;i<N;i++)
    {
        p[i]=i;
    }
    return 0;
}