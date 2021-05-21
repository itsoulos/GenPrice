# include <math.h>

extern "C"
{
	
	static double dmax(double a,double b)
	{
		return a>b?a:b;
	}

int	getdimension()
{
	return 2;
}

void	getleftmargin(double *x)
{
	x[0]=-5;
	x[1]=0;
}

void	getrightmargin(double *x)
{
	x[0]=10;
	x[1]=15;
}

double	funmin(double *x)
{
	double x1=x[0];
	double x2=x[1];
	return pow(x2-5.1/(4*M_PI*M_PI)*x1*x1+5.0/M_PI-6.0,2.0)+10.0*(1.0-1.0/(8.0*M_PI))*cos(x1)+10.0;
}

void    granal(double *x,double *g)
{
	double x1=x[0];
	double x2=x[1];
	g[0]=-2.0*x1*5.1/(4*M_PI*M_PI)*2.0*(x2-5.1/(4*M_PI*M_PI)*x1*x1+5.0/M_PI-6.0)
		-10.0*(1.0-1.0/(8.0*M_PI))*sin(x1);
	g[1]=2.0*(x2-5.1/(4*M_PI*M_PI)*x1*x1+5.0/M_PI-6.0);
}

}
