#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
	int i, t_id;
	int N = 20;
	omp_set_num_threads(8);
#pragma omp parallel private(t_id)
	{
		t_id = omp_get_thread_num();
#pragma omp for
		for (i = 0; i < N; i++)
			printf("Check Number %d %d\n", t_id, i); //모든 thread가 나눠서 20호출 (개수 및 순서는 0~7 랜덤)
	}
	return 0;
}