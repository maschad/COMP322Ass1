#include "continued.h"

/*recursive algorithm to find gcd*/
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


/*Uses integer division for gcd*/
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
		(*x).head = b/a;
		(*x).tail = getCFlargerThanOne(a,b -a*x->head);
	}

	return x;
}

ContinuedFraction *getCF(unsigned int b, unsigned int a)
{
	ContinuedFraction *z;

	if(b/a > 1)
	{
		z = getCFlargerThanOne(b,a);
	}
	else
	{
		z = new ContinuedFraction;
		(*z).head = 0;
		(*z).tail = getCFlargerThanOne(a,b);
	}

	return z;
}

void cat(ContinuedFraction *frac, unsigned int a)
{
	while(frac->tail != nullptr)
	{
		frac = frac->tail;
	}
	ContinuedFraction *x = new ContinuedFraction;
	(*x).head = a;
	(*x).tail = nullptr;
	frac->tail = x;
}

void cat(ContinuedFraction *frac , ContinuedFraction *end) {
	if(end == nullptr)
	{
		return;
	}
	else
	{
		cat(frac,end->head);
		cat(frac,end->tail);
	}
}

ContinuedFraction *getCF(unsigned int head, ContinuedFraction *fixed, ContinuedFraction *period)
{
	ContinuedFraction *x = new ContinuedFraction;
	(*x).head = head;
	(*x).tail = nullptr;

	cat(x,fixed);
	ContinuedFraction *y, *z;
	for(y = x; y->tail != nullptr; y = y->tail);
	cat(x,period);
	for(z = y; z->tail != nullptr; z = z->tail);
	z->tail = y->tail;
	return x;

}


Fraction getApproximation(ContinuedFraction *fr, unsigned int n)
{
	Fraction y;
	y.numerator = fr->head;
	y.denominator = 1;

	if(n == 1 || fr->head == 0)
	{
		return y;

	}
	else
	{
		Fraction x = getApproximation(fr->tail,n-1);
		Fraction temp;
		temp.numerator = x.numerator;
		temp.denominator = x.denominator;
		x.denominator = temp.numerator;
		x.numerator = temp.denominator;
		x.numerator = x.numerator + x.denominator*fr->head;
		return x;
	}

}
