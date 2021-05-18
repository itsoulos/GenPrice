# ifndef __GENPRICE__H
# define __GENPRICE__H

# include <problem.h>
# include <collection.h>
# include <vector>
using namespace std;

class GenPrice
{
	private:
		Problem *problem;
		Data xmax,xmin,center;
		double fmax,fmin;
		int M;
		Collection *sample;
	public:
		GenPrice(Problem *p);
		void	Solve();
		void	getMinimum(Data &x,double &y);
		int	getM() const;
		void	setM(int m);
		bool    check();
		~GenPrice();
};
# endif
