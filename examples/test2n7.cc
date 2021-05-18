# include <math.h>

extern "C"
{
# define N	7
int	getdimension()
{
	return N;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<N;i++) x[i]=-5.0;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<N;i++) x[i]= 5.0;
}

double	funmin(double *x)
{
	double sum=0.0;
	for(int i=0;i<N;i++)
		sum+=0.5 * (pow(x[i],4.0)-16.0 * pow(x[i],2.0)+5.0*x[i]);
	return sum;
}

void    granal(double *x,double *g)
{
	for(int i=0;i<N;i++)
	{
		g[i]=0.5 * (4.0*pow(x[i],3.0)-32*x[i]+5.0);
	}
}

}
