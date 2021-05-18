#include <genprice.h>
#include <grs.h>
#include <tolmin.h>
#include <math.h>
#include <get_options_price.h>

vector<double> minima;

double getMean(vector<double> &x)
{
	double s=0.0;
	for(int i=0;i<x.size();i++) s+=x[i];
	return s/x.size();
}

double getVariance(vector<double> &x)
{
	double m= getMean(x);
	double s=0.0;
	for(int i=0;i<x.size();i++)
		s+=pow(x[i]-m,2.0);
	return s/x.size();
}

GenPrice::GenPrice(Problem *p)
{
	problem = p;
	M = 25 * p->getDimension();
	//M = 25;
	xmin.resize(p->getDimension());
	xmax.resize(p->getDimension());
	sample = new Collection(p->getDimension());
	center.resize(problem->getDimension());
}

	double x1 = 0.0, x2 = 0.0, stopat = 0.0, variance=0.0, oldBesty = 1e+100;
	int iters;
	int miters=0;
bool	GenPrice::check()
{

	double fm = (fmin<oldBesty)>1e-4;//fabs(1.0 + fabs(fmin));

	x1 = x1 + fm;
	x2 = x2 + fm * fm;
	variance = x2 / (miters+1 ) - (x1 / (miters +1)) * (x1 / (miters+1 ));
	variance = fabs(variance);
	miters++;
	if(variance<1e-8 &&miters<3) variance=x1/miters;
	if (fmin < oldBesty)
	{
		oldBesty = fmin;
		stopat = variance / 2.0;
	}
	printf("GCRS. Iteration: %4d Fitness: %10.5lf Variance: %10.5lf Stopat: %10.5lf \n", miters, fmin, variance, stopat);
	if (variance <= stopat && miters >= 1000)
	{

		MinInfo Info;
		Info.p = problem;
		double f = problem->funmin(xmin);
		fmin = tolmin(xmin, Info);
		return true;
	}
	return false;
}

void GenPrice::Solve()
{
	int dimension = problem->getDimension();
	Collection *sample2 = new Collection(dimension);
	vector<int> index;
	index.resize(dimension + 1);
	Data xk;
	xk.resize(dimension);
	double fk;
	int success = 0;
	int posmax = 0;
	int posmin = 0;
	Grs *Solver = new Grs(problem);
	Solver->setGenomeCount(genome_count);
	Solver->setGenomeLength(10 * problem->getDimension());
	/**/
	double oldymin = -1e+100;
	int run_flag = 0;
	/*
	 * */
		MinInfo Info;
		Info.p=problem;
step0:
	iters = 1;
	Data x;
	x.resize(dimension);
	double y;
	for (int i = 0; i < M; i++)
	{
		problem->getSample(x);
		y = problem->funmin(x);
		sample->addSample(x, y);
	}
step1:
	fmax = -1e+100;
	fmin = 1e+100;
	for (int i = 0; i < M; i++)
	{
		y = sample->getSampleY(i);
		if (y < fmin)
		{
			posmin = i;
			fmin = y;
			sample->getSampleX(i, xmin);
		}
		if (y > fmax)
		{
			posmax = i;
			fmax = y;
			sample->getSampleX(i, xmax);
		}
	}
		if(check()) 
		{

		delete Solver;
		delete sample2;
			return;
		}
	if (iters >= 100000)
	{
		delete Solver;
		MinInfo Info;
		Info.p = problem;
		double f = problem->funmin(xmin);
		fmin = tolmin(xmin, Info);
		delete sample2;
		return;
	}
//		printf("iters=%d fmin=%.10lg diff=%.10lg\n",iters,fmin,fabs(fmax-fmin));
	if(fabs(fmax-fmin)<1e-6)
	{
		delete Solver;
		double f= problem->funmin(xmin);
		fmin=tolmin(xmin,Info);
		delete sample2;
		return;
	}
	
	
	
step2:
	sample2->clear();
	for (int i = 0; i < dimension; i++)
		center[i] = 0.0;
	for (int i = 0; i < dimension + 1; i++)
		index[i] = -1;
	for (int i = 0; i < dimension + 1; i++)
	{
		int r, flag;
		do
		{
			r = rand() % M;
			flag = 0;
			for (int j = 0; j < i; j++)
			{
				if (index[j] == r)
				{
					flag = 1;
					break;
				}
			}
		} while (flag);
		index[i] = r;
		sample->getSampleX(r, x);
		y = sample->getSampleY(r);
		sample2->addSample(x, y);
		if (i != dimension)
			for (int j = 0; j < dimension; j++)
				center[j] = center[j] + 1.0 / dimension * x[j];
	}
	sample2->getSampleX(dimension, x);
	for (int i = 0; i < dimension; i++)
		xk[i] = 2.0 * center[i] - x[i];
	if (!problem->isPointIn(xk))
		goto step2;
	fk = problem->funmin(xk);
	//Info.iters=3;
	//Solver->Solve(xk,fk);
	success += (fk <= fmax);
	if (fk <= fmax)
	{
		sample->replaceSample(posmax, xk, fk);
		iters++;
		goto step1;
	}

step3:
	if (fk > fmax)
	{
		if (success * 1.0 / iters > 0.5)
		{
			iters++;
			goto step2;
		}
		else
		{
			for (int i = 0; i < dimension; i++)
				xk[i] = 0.5 * center[i] + 0.5 * x[i];
			if (!problem->isPointIn(xk))
				goto step2;
			fk = problem->funmin(xk);
	fk=tolmin(xk,Info,10);	
			success += (fk <= fmax);
			if (fk < fmax)
			{
				sample->replaceSample(posmax, xk, fk);
				iters++;
				goto step1;
			}
			else
			{
				iters++;
				goto step2;
			}
		}
	}
step4:
	if (fk <= fmax)
	{
		sample->replaceSample(posmax, xk, fk);
		iters++;
		goto step1;
	}
}

void GenPrice::getMinimum(Data &x, double &y)
{
	x = xmin;
	y = fmin;
}

int GenPrice::getM() const
{
	return M;
}

void GenPrice::setM(int m)
{
	M = m;
}

GenPrice::~GenPrice()
{
	delete sample;
}
