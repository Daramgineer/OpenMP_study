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

	omp_set_num_threads(4);//��� thread ���� ����
#pragma omp parallel
	{
		printf("Hi %d\n", omp_get_thread_num());
	}
	printf("\n");

	omp_set_num_threads(2);//��� thread ���� ����
#pragma omp parallel
	{
		printf("Hi %d\n", omp_get_thread_num());
	}
	return 0;
}