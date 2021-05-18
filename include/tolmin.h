# ifndef __TOLMIN__H
# define __TOLMIN__H
# include <problem.h>

#ifdef __cplusplus
extern "C"{
# endif

typedef struct MinInfo
{
	Problem		*p;
	int		fevals;
	int		gevals;
	int 		iters;
};
extern double	tolmin(Data &x,MinInfo &Info,int iters=2001);

#ifdef __cplusplus
}
#endif

# endif
