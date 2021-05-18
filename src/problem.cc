# include <problem.h>		
# include <stdlib.h>
# include <math.h>


Problem::Problem(int N)
{
	fevals=gevals=0;
	dimension = N;
	lmargin.resize(0);
	rmargin.resize(0);
}

Problem::Problem(int N,Data l,Data r)
{
	fevals=gevals=0;
	dimension = N;
	lmargin.resize(N);
	lmargin = l;
	rmargin.resize(N);
	rmargin = r;
}

int	Problem::getfevals()
{
	return fevals;
}

int	Problem::getgevals()
{
	return gevals;
}

void	Problem::setLeftMargin(Data l)
{
	lmargin = l;
}

void	Problem::setRightMargin(Data r)
{
	rmargin = r;
}

int	Problem::getDimension()		const
{
	return dimension;
}

Data 	Problem::getLeftMargin() 	const
{
	return lmargin;
}

Data 	Problem::getRightMargin() 	const
{
	return rmargin;
}

double 	Problem::funmin(Data x)
{
	return 0.0;
}

void   	Problem::granal(Data x,Data &g)
{
}

int	Problem::getGradientCriterion(Data x1,Data x2,Data g1,Data g2)
{
	double s=0.0;
	for(int i=0;i<x1.size();i++)
		s+=(x1[i]-x2[i])*(g1[i]-g2[i]);
	return s>=0;
}

int	Problem::getGradientCriterion(Data x1,Data x2)
{
	Data g1,g2;
	g1.resize(x1.size());
	g2.resize(x2.size());
	granal(x1,g1);
	granal(x2,g2);
	double s=0.0;
	for(int i=0;i<x1.size();i++)
		s+=(x1[i]-x2[i])*(g1[i]-g2[i]);
	return s>=0;
}

void	Problem::getSample(Data &x)
{
	if(lmargin.size())
	{
		for(int i=0;i<dimension;i++)
		        x[i]=lmargin[i]+(rmargin[i]-lmargin[i])*(drand48());

	}
	else
	{
		for(int i=0;i<dimension;i++)
			x[i]=2.0*drand48()-1.0;
	}
}

int	Problem::isPointIn(Data x)
{
	int i;
	for(i=0;i<x.size();i++)
	{
		if(x[i]<lmargin[i] || x[i]>rmargin[i]) return 0;
	}
	return 1;
}

Problem::~Problem()
{
}
