#include <stdio.h>
#include <omp.h>
#include <math.h>

void single()
{
	int i, t_id;

#pragma omp parallel
	{
#pragma omp single //thread �ϳ�(random)�� ���ͼ� ����, �������� �׵��� ���(barrier)
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
#pragma omp master//master thread(���� 0��)�� ���ͼ� ����, �������� �н�
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