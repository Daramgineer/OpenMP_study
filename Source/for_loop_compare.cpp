#include <stdio.h>
#include <omp.h>
#include <math.h>
#define num_steps 1000000
#define NUM_THREADS 16

void serial()
{
    double sum, step, x, pi;
    int i;
    sum = 0.0;
    step = 1. / (double)num_steps;

    for (i = 1; i < num_steps; i++)
    {
        x = (i - 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    pi = step * sum;
    printf(" numerical pi = %.15f \n", pi);
    printf(" analytical pi = %.15f \n", acos(-1.0));
    printf(" Error = %E \n", fabs(acos(-1.0) - pi));
}

void parallel1()
{
    double sum[NUM_THREADS], step, x, pi;
    int i, t_id;
    step = 1. / (double)num_steps;

#pragma omp parallel private(i, t_id, x)
    {
        t_id = omp_get_thread_num();
        sum[t_id] = 0.0;
        for (i = t_id; i < num_steps; i = i + NUM_THREADS)
        {
            x = (i + 0.5) * step;
            sum[t_id] += 4.0 / (1.0 + x * x);
        }
    }
    for (i = 0, pi = 0.0; i < NUM_THREADS; i++)
        pi += sum[i] * step;

    printf(" numerical pi = %.15f \n", pi);
    printf(" analytical pi = %.15f \n", acos(-1.0));
    printf(" Error = %E \n", fabs(acos(-1.0) - pi));
}

void parallel2()
{
    double sum[NUM_THREADS], step, x, pi;
    int i, t_id;

    step = 1. / (double)num_steps;

#pragma omp parallel private(t_id)
    {
        t_id = omp_get_thread_num();
        sum[t_id] = 0.0;

#pragma omp for private(i, x)
        for (i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum[t_id] += 4.0 / (1.0 + x * x);
        }
    }
    for (i = 0, pi = 0.0; i < NUM_THREADS; i++)
        pi += sum[i] * step;

    printf(" numerical pi = %.15f \n", pi);
    printf(" analytical pi = %.15f \n", acos(-1.0));
    printf(" Error = %E \n", fabs(acos(-1.0) - pi));
}

void parallel3()
{
    double sum, step, x, pi = 0;
    int i, t_id;
    step = 1. / (double)num_steps;

#pragma omp parallel private (i, t_id, x, sum)
    {
        t_id = omp_get_thread_num();
        sum = 0.0;
        for (i = t_id; i < num_steps; i = i + NUM_THREADS)
        {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
#pragma omp critical
        {
            pi += sum * step;
        }
    }
    printf(" numerical pi = %.15f \n", pi);
    printf(" analytical pi = %.15f \n", acos(-1.0));
    printf(" Error = %E \n", fabs(acos(-1.0) - pi));
}

void parallel4()
{
    int i;
    double x, pi, sum = 0.0;
    double step = 1.0 / (double)num_steps;
#pragma omp parallel for reduction(+:sum) private(x)
    for (i = 1; i <= num_steps; i++)
    {
        x = (i - 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    pi = step * sum;
    printf(" numerical pi = %.15f \n", pi);
    printf(" analytical pi = %.15f \n", acos(-1.0));
    printf(" Error = %E \n", fabs(acos(-1.0) - pi));
}

int main()
{
    serial();
    printf("\n");
    parallel1();
    printf("\n");
    parallel2();
    printf("\n");
    parallel3();
    printf("\n");
    parallel4();
    return 0;
}