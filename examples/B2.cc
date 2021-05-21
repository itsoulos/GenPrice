# include <math.h>

extern "C"
{

int	getdimension()
{
	return 2;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<getdimension();i++) x[i]=-100.0;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<getdimension();i++) x[i]= 100.0;
}

double	funmin(double *x)
{
	return x[0]*x[0]+2.0*x[1]*x[1]-0.3*cos(3.0*M_PI*x[0])-0.4*cos(4.0*M_PI*x[1])+0.7;
}

void    granal(double *x,double *g)
{
	g[0]=2.0*x[0]+0.9*M_PI*sin(3.0*M_PI*x[0]);
	g[1]=4.0*x[1]+1.6*M_PI*sin(4.0*M_PI*x[1]);
}

}
