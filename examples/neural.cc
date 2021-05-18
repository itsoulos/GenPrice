# include <math.h>
# include <stdio.h>

//NNTEST EXAMPLE
extern "C"
{

# define NODE_COUNT	10	
# define DIMENSION	1

double	sig(double x)
{
	return 1.0/(1.0+exp(-x));
}

double	getValue(double *node,double *x)
{
	double arg=0.0;
	double per=0.0;
	int nodes=NODE_COUNT;
	for(int i=1;i<=nodes;i++)
	{
		arg=0.0;
		for(int j=1;j<=DIMENSION;j++)
		{
			int pos=(DIMENSION+2)*i-(DIMENSION+1)+j-1;
			arg+=node[pos]*x[j-1];
		}
		arg+=node[(DIMENSION+2)*i-1];
		per+=node[(DIMENSION+2)*i-(DIMENSION+1)-1]*sig(arg);
	}
	return per;
}

void	getDeriv(double *node,double *x,double *G)
{
	double arg;
        double s;
        int nodes=NODE_COUNT;
        double f,f2;
        for(int i=1;i<=nodes;i++)
        {
                arg = 0.0;
                for(int j=1;j<=DIMENSION;j++)
                {
                        arg+=node[(DIMENSION+2)*i-(DIMENSION+1)+j-1]*x[j-1];
                }
                arg+=node[(DIMENSION+2)*i-1];
                f=sig(arg);
                f2=f*(1.0-f);
                G[(DIMENSION+2)*i-1]=node[(DIMENSION+2)*i-(DIMENSION+1)-1]*f2;
                G[(DIMENSION+2)*i-(DIMENSION+1)-1]=f;
                for(int k=1;k<=DIMENSION;k++)
                {
                        G[(DIMENSION+2)*i-(DIMENSION+1)+k-1]=
                                x[k-1]*f2*node[(DIMENSION+2)*i-(DIMENSION+1)-1];
                }
	}
}

double	getTrainError(double *node,int count,double **xdata,double *ydata)
{
	double sum=0.0;
	double per=0.0;
	for(int i=0;i<count;i++)
	{
		per=getValue(node,xdata[i])-ydata[i];
		sum+=per * per;
	}
	return sum;
}

void	getGradient(double *node,int count,
		double **xdata,double *ydata,double *g)
{
	for(int i=0;i<(DIMENSION+2)*NODE_COUNT;i++) g[i]=0.0;
	double gtemp[(DIMENSION+2)*NODE_COUNT];
	for(int i=0;i<count;i++)
	{
		getDeriv(node,xdata[i],gtemp);
		double per=getValue(node,xdata[i])-ydata[i];
		for(int j=0;j<(DIMENSION+2)*NODE_COUNT;j++)
			g[j]+=gtemp[j]*per;
	}
	for(int j=0;j<(DIMENSION+2)*NODE_COUNT;j++) g[j]*=2.0;
}

int	getdimension()
{
	return (DIMENSION+2) * NODE_COUNT;
}

void	getleftmargin(double *x)
{
	for(int i=0;i<(DIMENSION+2)*NODE_COUNT;i++)
		x[i]=-1e+2;
}

void	getrightmargin(double *x)
{
	for(int i=0;i<(DIMENSION+2)*NODE_COUNT;i++)
		x[i]= 1e+2;
}

double	funmin(double *x)
{
	static int itric=1;
	static double **xdata=NULL;
	static double *ydata=NULL;
	static int    count=0;
	if(itric==1)
	{
		itric = 0;
		FILE *fp;
		fp=fopen("xy.data","r");
		int d;
		fscanf(fp,"%d",&d);
		fscanf(fp,"%d",&count);
		xdata=new double*[count];
		ydata=new double[count];
		for(int i=0;i<count;i++)
		{
			xdata[i]=new double[DIMENSION];
			for(int j=0;j<DIMENSION;j++)
				fscanf(fp,"%lf",&xdata[i][j]);
			fscanf(fp,"%lf",&ydata[i]);
		}
		fclose(fp);
	}
	return getTrainError(x,count,xdata,ydata);
}

void    granal(double *x,double *g)
{
	static int itric=1;
	static double **xdata=NULL;
	static double *ydata=NULL;
	static int    count=0;
	if(itric==1)
	{
		itric = 0;
		FILE *fp;
		fp=fopen("xy.data","r");
		int d;
		fscanf(fp,"%d",&d);
		fscanf(fp,"%d",&count);
		xdata=new double*[count];
		ydata=new double[count];
		for(int i=0;i<count;i++)
		{
			xdata[i]=new double[DIMENSION];
			for(int j=0;j<DIMENSION;j++)
				fscanf(fp,"%lf",&xdata[i][j]);
			fscanf(fp,"%lf",&ydata[i]);
		}
		fclose(fp);
	}
	getGradient(x,count,xdata,ydata,g);
}

}
