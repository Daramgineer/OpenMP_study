#include<stdio.h>
#include<omp.h>
#include<math.h>

int main()
{
	int t_id;

	omp_set_num_threads(4); //��� thread ���� ����
#pragma omp parallel
	{
		t_id = omp_get_thread_num(); //thread num ����ȭ
		printf("thread num %d & t_id %d\n", omp_get_thread_num(), t_id);
	}
	return 0;
}