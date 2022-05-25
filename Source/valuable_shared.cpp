#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
	int a[10];
	int t_id, i;
	omp_set_num_threads(8);
#pragma omp parallel shared(a) private(t_id) //���� a�迭�� ����
	{
		t_id = omp_get_thread_num(); //thread num ȣ��
		a[t_id] = t_id + 2;
	}
	for (i = 0; i < 10; i++)
	{
		printf("a[%d] = %d\n", i, a[i]); // ���thread = 8��, a�迭�� 10��, �����迭�� ����->a�迭 �������,      ������ 2���迭���� ������ input
	}
	return 0;
}