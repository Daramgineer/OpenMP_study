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
			printf("Check Number %d %d\n", t_id, i); //��� thread�� ������ 20ȣ�� (���� �� ������ 0~7 ����)
	}
	return 0;
}