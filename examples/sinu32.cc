# include <math.h>

extern "C"
{

# define DIMENSION	32
int	getdimension()
{
	return DIMENSION;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++)
		x[i]=0.0;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++)
		x[i]=M_PI;
}

double	funmin(double *x)
{
	double p1=1.0,p2=1.0;
	const double z=M_PI/6;
	for(int i=0;i<DIMENSION;i++)
	{
		p1*=sin(x[i]-z);
		p2*=sin(5*(x[i]-z));
	}
	return -2.5 * p1 -p2;
}

void    granal(double *x,double *g)
{
	double p1=1.0,p2=1.0;
	const double z=M_PI/6;
	for(int i=0;i<DIMENSION;i++)
	{
		p1=1.0,p2=1.0;
		for(int j=0;j<DIMENSION;j++)
		{
			if(i==j) continue;
			p1*=sin(x[j]-z);
			p2*=sin(5*(x[j]-z));
		}
		g[i]=-2.5 * cos(x[i]-z)*p1-5.0*p2*cos(5*(x[i]-z));
	}
}

}
