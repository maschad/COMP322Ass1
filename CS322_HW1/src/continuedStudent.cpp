#include "continued.h"

unsigned int gcd(unsigned int a, unsigned int b)
{
	if(a == 0)
	{
		return b;
	}
	else
	{
		return gcd(b%a,a);
	}
}

unsigned int gcdFaster(unsigned int u, unsigned int v)
{
	 // simple cases (termination)
	    if (u == v)
	        return u;

	    if (u == 0)
	        return v;

	    if (v == 0)
	        return u;

	    // look for factors of 2
	    if (~u & 1) // u is even
	    {
	        if (v & 1) // v is odd
	            return gcd(u >> 1, v);
	        else // both u and v are even
	            return gcd(u >> 1, v >> 1) << 1;
	    }

	    if (~v & 1) // u is odd, v is even
	        return gcd(u, v >> 1);

	    // reduce larger argument
	    if (u > v)
	        return gcd((u - v) >> 1, v);

	    return gcd((v - u) >> 1, u);
}
ContinuedFraction *getCFlargerThanOne(unsigned int b, unsigned int a)
{
	ContinuedFraction *x = new ContinuedFraction;

	if(a == 0)
	{
		(*x).head = b;
		(*x).tail = nullptr;

	}
	else
	{
		ContinuedFraction *y = new ContinuedFraction;
		(*y).head = b%a;
		(*x).head = b/a * a;
		(*x).tail = y;
	}

	return x;
}

ContinuedFraction *getCF(unsigned int b, unsigned int a)
{
	ContinuedFraction *z = new ContinuedFraction;

	if(b/a > 1)
	{
		z = getCFlargerThanOne(b,a);
	}
	else
	{
		z = getCFlargerThanOne(0,a);
	}

	return z;
}


ContinuedFraction *getCF(unsigned int head, ContinuedFraction *fixed, ContinuedFraction *period)
{
	ContinuedFraction *x = new ContinuedFraction;
	(*x).head = head;

	if((*x).tail == nullptr)
	{
		return x;
	}
	else
	{

	}

}


Fraction getApproximation(ContinuedFraction *fr, unsigned int n) {
  // your code here
}
