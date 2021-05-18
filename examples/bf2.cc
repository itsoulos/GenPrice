# include <math.h>

using namespace std;


/*	Bohachevsky 2 Problem
 *
 * */
extern "C"
{

int	getdimension()
{
	return 2;
}

void	getleftmargin(double *x)
{
	x[0]=-50.0;
	x[1]=-50.0;
}

void	getrightmargin(double *x)
{
	x[0]=50.0;
	x[1]=50.0;
}


double	funmin(double *x)
{
	return x[0]*x[0]+2.0*x[1]*x[1]-0.3*cos(3.0*M_PI*x[0])*cos(4.0*M_PI*x[1])+0.3;
}

void    granal(double *x,double *g)
{
	g[0]=2.0*x[0]+0.3*3.0*M_PI*sin(3.0*M_PI*x[0])*cos(4.0*M_PI*x[1]);
	g[1]=4.0*x[1]+0.3*4.0*M_PI*sin(4.0*M_PI*x[1])*cos(3.0*M_PI*x[0]);
}
  
}
