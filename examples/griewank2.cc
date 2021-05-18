# include <math.h>

extern "C"
{

int	getdimension()
{
	return 2;
}

void	getleftmargin(double *x)
{
	x[0]=-100;
	x[1]=-100;
}

void	getrightmargin(double *x)
{
	x[0]=100;
	x[1]=100;
}

double	funmin(double *x)
{
	 int n=2;
        double sum=0.0;
        double product=1.0;
        for(int i=0;i<n;i++)
        {
          sum+=x[i]*x[i]/200.0;
          product*=cos(x[i]/sqrt(i+1.0));
        }
        return sum+1.0-product;

}

void    granal(double *x,double *g)
{
	 int n=2;
         double a,b;
         for(int i=0;i<n;i++)
         {
            double product=1.0;
            for(int j=0;j<n;j++)
            {
              product*=cos(x[j]/sqrt(j+1.0));
             }
             a=sin(x[i]/sqrt(i+1.0));
             b=sqrt(i+1.0)*cos(x[i]/sqrt(i+1.0));
             g[i]=x[i]/100.0+a*product/b;
         }

}

}
