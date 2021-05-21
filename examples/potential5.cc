# include <math.h>
# include <stdio.h>
extern "C"{
# define 	NAT	5
static double dmax(double a,double b){return a>b?a:b;}
int	getdimension()
{
	return	3 * NAT;
}

int	hasmargins()
{
	return 1;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<3*NAT;i++) x[i]= -1;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<3*NAT; i++) x[i]= 1;
}


double	Pow(double x,int n)
{
	double p=1.0;
	for(int i=0;i<n;i++) p*=x;
	return p;
}

double	pot(double r)
{
	double	eps=1.0;
	double 	sig =1.0;
	double	eps4=4.0 *eps;
	double sbyr6=Pow(sig/r,6);
	return eps4 * sbyr6*(sbyr6-1.0);
}

double	funmin(double *x)
{
	double value=0.0;
	double  *xx=new double[NAT];
	double *yy =new double[NAT];
	double *zz =new double[NAT];
	for(int i=1;i<=NAT;i++)
	{
		int i3=3 * i;
		xx[i-1]=x[i3-2-1];
		yy[i-1]=x[i3-1-1];
		zz[i-1]=x[i3-1];
	}
	//for(int i=1;i<=NAT-1;i++)
	for(int i=1;i<=NAT;i++)
	{
		//for(int j=i+1;j<=NAT;j++)
		for(int j=1;j<=NAT;j++)
		{
			if(i==j) continue;
			double dx=xx[i-1]-xx[j-1];
			double dy=yy[i-1]-yy[j-1];
			double dz=zz[i-1]-zz[j-1];
			double rij=sqrt(dx*dx+dy*dy+dz*dz);
			value=value+pot(rij);
		}
	}
	delete[] xx;
	delete[] yy;
	delete[] zz;
	return 0.5 * value;
}

double gpot(double r)
{

	double eps = 1.0, sig = 1.0;
        double eps4 = 4*eps;
        double sl = 0.0;

        double sbyr7 = pow((sig/r),7);
        double sbyr6 = pow((sig/r),6);
        return eps4*sbyr6*(-12.0*sbyr7 + 6.0*(sig/r))+sl/(r*r);

}

void    granal(double *x,double *g)
{
	int natoms=NAT;
    for(int i=1;i<=natoms;i++)
    {
	    int i31=3*i; 
	    int idim=3 * i;
	    g[idim-1]=0.0;
	    g[idim-1-1]=0.0;
	    g[idim-2-1]=0.0;
	    for(int j=1;j<=natoms;j++)
	    {
		    int i32=3*j;
		    if(j!=i)
		    {
			double rij = sqrt( (x[i31-2-1] - x[i32-2-1])*(x[i31-2-1] - x[i32-2-1])+
                                              (x[i31-1-1] - x[i32-1-1])*(x[i31-1-1] - x[i32-1-1])+
                                              (x[i31-1] - x[i32-1])*(x[i31-1] - x[i32-1]) );

			double gp = gpot(rij);
			g[idim-2-1]+=gp* (x[i31-2-1] - x[i32-2-1])/rij;
			g[idim-1-1]+=gp*(x[i31-1-1] - x[i32-1-1])/rij;
			g[idim-1]+=gp*(x[i31-1] - x[i32-1])/rij;
		    }
	    }
    }

}


}
