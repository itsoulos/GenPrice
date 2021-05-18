# include <math.h>

using namespace std;
extern "C"
{

	static double dmax(double a,double b)
	{
		return a>b?a:b;
	}
	int DIMENSION=10;


void	getleftmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++) x[i]=-1e+10;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<DIMENSION;i++) x[i]= 1e+10;
}

int	getdimension()
{
	return DIMENSION;
}


double	funmin(double *x)
{
	double sum=0.0;
	for(int i=0;i<DIMENSION;i++)
		sum+=pow(fabs(x[i]),2.0+10.0*(i*1.0)/(DIMENSION-1.0));
	return sum;
}

void    granal(double *x,double *g)
{
	 for(int i=0;i<getdimension();i++)
         {
                double eps=pow(1e-18,1.0/3.0)*dmax(1.0,fabs(x[i]));
                x[i]+=eps;
                double v1=funmin(x);
                x[i]-=2.0 *eps;
                double v2=funmin(x);
                g[i]=(v1-v2)/(2.0 * eps);
                x[i]+=eps;
        }
}

}
