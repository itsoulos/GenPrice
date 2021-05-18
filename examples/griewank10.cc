# include <math.h>
using namespace std;


extern "C"
{
int	getdimension()
{
	return 10;
}



void	getleftmargin(double *x)
{
	for(int i=0;i<getdimension();i++) x[i]=-600;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<getdimension();i++) x[i]= 600;
}

double  funmin(double *x)
{
        int n=10;
        double sum=0.0;
        double product=1.0;
        for(int i=0;i<n;i++)
        {
           sum+=x[i]*x[i]/4000.0;
           product*=cos(x[i]/sqrt(i+1.0));
        }
        return sum+1.0-product;

}
void    granal(double *x,double *g)
{
         int n=10;
        for(int i=0;i<n;i++)
        {
            double product=1.0;
            for(int j=0;j<n;j++)
            {
               if(i==j) continue;
               product*=cos(x[j]/sqrt(j+1.0));
            }
            g[i]=x[i]/2000.0+sin(x[i]/sqrt(i+1.0))*product/sqrt(i+1.0);
        }
}



}
