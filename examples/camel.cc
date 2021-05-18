# include <math.h>

extern "C"
{

int	getdimension()
{
	return 2;
}

void	getleftmargin(double *x)
{
	x[0]=-5;
	x[1]=-5;
}

void	getrightmargin(double *x)
{
	x[0]=5;
	x[1]=5;
}

double	funmin(double *x)
{
 double x1=x[0],x2=x[1];
 return 4*x1*x1-2.1*x1*x1*x1*x1+x1*x1*x1*x1*x1*x1/3.0+x1*x2-4*x2*x2+4*x2*x2*x2*x2;
}

void    granal(double *x,double *g)
{
 double x1=x[0],x2=x[1];
 g[0]=8*x1-8.4*x1*x1*x1+2*x1*x1*x1*x1*x1+x2;
 g[1]=x1-8*x2+16*x2*x2*x2;
}

}
