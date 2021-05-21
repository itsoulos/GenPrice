# include <math.h>

/*	Exponential Problem.
 * */
extern "C"
{

# define DIMENSION 8
int	getdimension()
{
	return DIMENSION;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++)
		x[i]=-1.0;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++)
		x[i]= 1.0;
}

double	funmin(double *x)
{
	double s1=0.0;
	for(int i=0;i<DIMENSION;i++) s1+=x[i]*x[i];
	return -exp(-0.5 * s1);
}

void    granal(double *x,double *g)
{
	double s1=0.0;
	for(int i=0;i<DIMENSION;i++) s1+=x[i]*x[i];
	for(int i=0;i<DIMENSION;i++)
	{
		g[i]=0.5 * 2.0 *x[i] *  exp(-0.5 * s1);
	}
}

}
