#include <stdio.h>
#include <omp.h>
#include <math.h>

void single()
{
	int i, t_id;

#pragma omp parallel
	{
#pragma omp single //thread 하나(random)만 들어와서 동작, 나머지는 그동안 대기(barrier)
		{
			printf("Hi im single num %d", omp_get_thread_num());
		}
	}
}

void master()
{
	int i, t_id;

#pragma omp parallel
	{
#pragma omp master//master thread(보통 0번)만 들어와서 동작, 나머지는 패스
		{
			printf("Hi im master num %d", omp_get_thread_num());
		}
	}
}

int main()
{
	single();
	master();
	return 0;
}