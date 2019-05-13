#pragma once
#include <stdint.h>

typedef struct
{
    double sum;
    double sumComp;
    
    uint64_t count;
    double max;
    double min;

    double s;
} stats_t;

void stats_clear (stats_t *sp);
uint64_t stats_add (stats_t *sp, double val);
double stats_mean (stats_t *sp);
double stats_sum (stats_t *sp);
double stats_min (stats_t *sp);
double stats_max (stats_t *sp);
double stats_var (stats_t *sp);
uint64_t stats_count (stats_t *sp);
