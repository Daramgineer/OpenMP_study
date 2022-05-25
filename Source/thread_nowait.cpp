#include <stdio.h>
#include <omp.h>
#include <math.h>
#define N 20

int main()
{
	int i, t_id, a[N], b[N];

#pragma omp parallel private(i)
	{
#pragma omp for nowait //nowait�� �ɸ� a���� thread�� b�� �ȳѾ�� �ٽ� a���� ����.
		for (i = 0; i < N; i++)
		{
			a[i] = i;
			printf("a[%d] = %d , t_id = %d\n", i, a[i], omp_get_thread_num());
		}
#pragma omp for
		for (i = 0; i < N; i++)
		{
			b[i] = i;
			printf("b[%d] = %d , t_id = %d\n", i, b[i], omp_get_thread_num());
		}
	}
}