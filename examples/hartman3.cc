# include <math.h>
using namespace std;
extern "C"
{
	static double dmax(double a,double b)
	{
		return a>b?a:b;
	}


int	getdimension()
{
	return 3;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<getdimension();i++) x[i]=-0.0;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<getdimension();i++) x[i]= 1;
}
double	funmin(double *x)
{
	static double a[4][3]={{3,10,30},{0.1,10,35},{3,10,30},{0.1,10,35}};
	static double c[4]={1,1.2,3.0,3.2};
	static double p[4][3]={{0.36890,0.11700,0.26730},
			{0.46990,0.43870,0.74700},
			{0.10910,0.87320,0.55470},
			{0.03815,0.57430,0.88280}};
	double sum=0.0;
	for(int i=0;i<4;i++)
	{
		double s=0.0;
		for(int j=0;j<3;j++) s=s+a[i][j]*pow(x[j]-p[i][j],2.0);
		sum=sum+c[i]*exp(-s);
	}
	return -sum;
}

void    granal(double *x,double *g)
{
	static double a[4][3]={{3,10,30},{0.1,10,35},{3,10,30},{0.1,10,35}};
	static double c[4]={1,1.2,3.0,3.2};
	static double p[4][3]={{0.36890,0.11700,0.26730},
			{0.46990,0.43870,0.74700},
			{0.10910,0.87320,0.55470},
			{0.03815,0.57430,0.88280}};
	for(int i=0;i<getdimension();i++) g[i]=0.0;
	for(int j=0;j<getdimension();j++) 
	{
		double pj=0.0;
		for(int i=0;i<4;i++)
		{
			double sum1=0.0;
			for(int k=0;k<getdimension();k++)
				sum1+=a[i][k]*pow(x[k]-p[i][k],2.0);
			pj+=c[i]*exp(-sum1)*(-2.0)*a[i][j]*(x[j]-p[i][j]);
		}
		g[j]=-pj;
	}

}

}
