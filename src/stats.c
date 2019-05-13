#include "stats.h"
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <stdio.h>

void stats_clear (stats_t *sp)
{
    sp->sum = 0.0;
    sp->sumComp = 0.0;
    sp->count = 0;
    sp->max = DBL_MIN;
    sp->min = DBL_MAX;
    sp->s = 0.0;
}

double stats_var (stats_t *sp)
{
    if (sp->count > 1)
    {
	return (sp->s / ((double) (sp->count - 1)));
    }
    return 0.0;
}

uint64_t stats_add (stats_t *sp, double val)
{
    double delta0 = val - stats_mean (sp);

    // this updates the "mean"
    double y = val - sp->sumComp;
    double t = sp->sum + y;
    sp->sumComp = (t - sp->sum) - y;
    sp->sum = t;
    sp->count = sp->count + 1;

    double delta1 = val - stats_mean (sp);
    double sNew = delta0 * delta1;
    
    sp->s = sp->s + sNew;
    
    if (val < sp->min)
    {
	sp->min = val;
    }

    if (val > sp->max)
    {
	sp->max = val;
    }
    return sp->count;
}

double stats_mean (stats_t *sp)
{
    if (sp->count > 0)
    {
	return (sp->sum / (double)sp->count);
    }
    return 0.0;
}

double stats_sum (stats_t *sp)
{
    return sp->sum;
}

double stats_min (stats_t *sp)
{
    return sp->min;
}

double stats_max (stats_t *sp)
{
    return sp->max;
}

uint64_t stats_count (stats_t *sp)
{
    return sp->count;
}
    
