# ifndef __PROBLEM__H
# define __PROBLEM__H
# include <vector>
using namespace std;
typedef vector<double> Data;

/*	06-11-2004
 *	=================================================
 *	This class implements a generic problem for 
 *	optimization purposes. 
 *	=================================================
 * */
class Problem
{
	protected:
		/*	FIELDS DESCRIPTION:
		 *	=================================================
		 *	lmargin:	The left margins of the problem.
		 *	rmargin:	The right margins of the problem.
		 *	dimension:	The dimension of the problem.
		 *	=================================================
		 * */
		Data	lmargin;
		Data	rmargin;
		int     dimension;
		int	fevals,gevals;
	public:
		/*	METHODS DESCRIPTION:
		 *	=============================================================
		 *	Problem(N):	Sets only the dimension for the 
		 *			objective problem.
		 *	Problem(N,l,r):	Set the dimension and the margins of
		 *			the objective problem.
		 *	setLeftMargin(l): Sets the left margin of the problem to l.
		 *	setRightMargin(r):Sets the right margin of the problem to r.
		 *	getLeftMargin():  Returns the left margin of the problem.
		 *	getRightMargin(): Returns the right margin of the problem.
		 *	getDimension()    Returns the dimension of the problem.
		 *	funmin(x):	Returns the function to be minimized.
		 *	granal(x,g):	Returns to g the granal of the function to 
		 *			be minimized.
		 *	~Problem():	The destructor of the proposed problem.
		 *	=============================================================
		 * */
		Problem(int N);
		Problem(int N,Data l,Data r);
		void	setLeftMargin(Data l);
		void	setRightMargin(Data r);
		int	getDimension()  const;
		Data 	getLeftMargin() 	const;
		Data 	getRightMargin() 	const;
		int	getGradientCriterion(Data x1,Data x2);
		int	getGradientCriterion(Data x1,Data x2,Data g1,Data g2);
		virtual double funmin(Data x);
		virtual void   granal(Data x,Data &g);
		void	getSample(Data &x);
		int	getfevals();
		int	getgevals();
		int	isPointIn(Data x);
		~Problem();
};

# endif
