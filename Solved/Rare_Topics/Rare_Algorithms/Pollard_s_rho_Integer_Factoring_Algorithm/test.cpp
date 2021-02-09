/*
    Algo:   Pollar Rho
    Task:   Prime Factorization of an Integer
    Author: Chandan Mittal
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"


const long long MAX = 100000000;
const long long LMT = 10000;
bool isprime[MAX];

void sieve()    //Sieve of Eratosthenes
{
    memset(isprime, true, sizeof(isprime));

    long long i, k, j;
    isprime[1] = false;
    for (i = 4; i <= MAX; i+=2)
    {
        isprime[i] = false;
    }
    for (i = 3; i <= LMT; i+=2)
    {
        if(isprime[i])
            for (j = i*i, k = i<<1; j <= MAX; j+=k)
            {
                isprime[j] = false;
            }
    }
}

long long abso(long long a)     //fn to return absolute value
{
    return a>0?a:-a;
}
long long gcd(long long a,long long b)    //Euclidean GCD recursive fn
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

long long pollard_rho(long long n)  //pollard rho implementation
{
    if(n%2==0)
        return 2;

    long long x = rand()%n+1;
    long long c = rand()%n+1;
    long long y = x;
    long long g = 1;

    //fn is f(x) = x*x + c
    while(g==1)
    {
        x = ((x*x)%n + c)%n;    
        y = ((y*y)%n + c)%n;
        y = ((y*y)%n + c)%n;
        g = gcd(abso(x-y),n);
    }
    return g;
}

long long factors[MAX/100], total;

void factorize(long long n)   //fn to factorize the number
{
    if(n == 1)
        return;

    if(isprime[n])      //if n is prime,store it
    {
        factors[total++] = n;
        return;
    }
    long long divisor = pollard_rho(n);   //get a divisor of n
    factorize(divisor);
    factorize(n/divisor);
}

int main()  //Driver Program
{
    srand(time(NULL));
    sieve();

	long long n;
    //scanf("%d",&n);

    total = 0;
    factorize(983160949277722);

    for (long long i = 0; i < total; ++i)
    {
        printf("%d ",factors[i] );
    }
    printf("\n");
	return 0;
}