#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{
#pragma omp parallel
	{
		printf("Hi %d\n", omp_get_thread_num());
	}
	printf("\n");

	omp_set_num_threads(4);//사용 thread 개수 지정
#pragma omp parallel
	{
		printf("Hi %d\n", omp_get_thread_num());
	}
	printf("\n");

	omp_set_num_threads(2);//사용 thread 개수 지정
#pragma omp parallel
	{
		printf("Hi %d\n", omp_get_thread_num());
	}
	return 0;
}