#include <math.h>
#include <stdio.h>

extern "C"
{

#define N 20
	static double dmax(double x, double y)
	{
		return x > y ? x : y;
	}

	int getdimension()
	{
		return N;
	}

	void getleftmargin(double *x)
	{
		for (int i = 0; i < sizeof(x) / sizeof(int); i++)
			x[i] = -30;
	}

	void getrightmargin(double *x)
	{
		for (int i = 0; i < sizeof(x) / sizeof(int); i++)
			x[i] = 30;
	}

	double funmin(double *x)
	{
		double sum = 0.0;
		for (int i = 0; i < N - 1; i++)
		{
			sum = sum + 100.0 * pow(x[i] * x[i] - x[i + 1], 2.0) + pow(x[i], 2.0);
		}
		return sum;
	}

	void granal(double *x, double *g)
	{
		for (int i = 0; i < getdimension(); i++)
		{
			g[i] = 0.0;
		}
		for (int i = 0; i < getdimension() - 1; i++)
		{
			g[i] += 100.0 * 4.0 * x[i] * (x[i] * x[i] - x[i + 1]) + 2.0 * x[i];
			g[i + 1] += -100.0 * 2.0 * (x[i] * x[i] - x[i + 1]);
		}
	}
}
