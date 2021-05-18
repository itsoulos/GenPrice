# include <math.h>

using namespace std;

extern "C"
{



int	getdimension()
{
	return 2;
}
void	getleftmargin(double *x)
{
	x[0]=-10.0;
	x[1]=-10.0;
}

void	getrightmargin(double *x)
{
	x[0]=10.0;
	x[1]=10.0;
}
double	funmin(double *x)
{
	double sum1=0.0;
        double sum2=0.0;
        for(int i=1;i<=5;i++)
        {
           sum1+=i*cos((i-1)*x[0]+i);
           sum2+=i*cos((i+1)*x[1]+i);
         }
        return sum1 * sum2;

}

void    granal(double *x,double *g)
{
	 double sum1=0.0;
         double sum2=0.0;
         for(int i=1;i<=5;i++)
         {
            sum1+=-i*(i-1)*sin((i-1)*x[0]+i);
            sum2+=i*cos((i+1)*x[1]+i);
          }
          g[0]=sum1 * sum2;
          sum1=sum2=0;
          for(int i=1;i<=5;i++)
          {
            sum1+=i*cos((i-1)*x[0]+i);
            sum2+=-i*(i+1)*sin((i+1)*x[1]+i);
           }
           g[1]=sum1*sum2;

}

}
