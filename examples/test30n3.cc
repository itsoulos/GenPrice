# include <math.h>

extern "C"
{

# define DIMENSION	3
int	getdimension()
{
	return DIMENSION;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++) x[i]=-10.0;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++) x[i]= 10.0;
}

double	funmin(double *x)
{
	double sum=0.0;
	for(int i=1;i<DIMENSION-1;i++)
		sum+=pow(x[i]-1.0,2.0)*(1.0+pow(sin(3*M_PI*x[i+1]),2.0));
	return 0.1 *(pow(sin(3*M_PI*x[0]),2.0))*sum+pow(x[DIMENSION-1]-1.0,2.0)*(1.0+pow(sin(2.0*M_PI*x[DIMENSION-1]),2.0));
}

void    granal(double *x,double *g)
{
	for(int i=0;i<DIMENSION;i++) g[i]=0.0;
	g[0]=0.1*2*3*M_PI*sin(3*M_PI*x[0])*cos(3*M_PI*x[0]);
	for(int i=1;i<DIMENSION-1;i++)
	{
		g[i]+=2.0*(x[i]-1.0)*(1.0+pow(sin(3*M_PI*x[i+1]),2.0));
		g[i+1]+=pow(x[i]-1.0,2.0)*2.0*3*M_PI*sin(3*M_PI*x[i+1])*cos(3*M_PI*x[i+1]);
	}
	g[DIMENSION-1]+=2.0*(x[DIMENSION-1]-1.0)*(1.0+pow(sin(2.0*M_PI*x[DIMENSION-1]),2.0))+
		pow(x[DIMENSION-1]-1.0,2.0)*2.0*2.0*M_PI*sin(2.0*M_PI*x[DIMENSION-1])*
		cos(2.0*M_PI*x[DIMENSION-1]);
}

}
