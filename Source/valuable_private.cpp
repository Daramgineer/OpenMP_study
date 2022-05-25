#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
	int t_id = 0;
	int i = 10;
	omp_set_num_threads(8); //thread ��밳�� ����
#pragma omp parallel private(t_id) //thread num ��������ȭ
	{
		t_id = omp_get_thread_num(); //thread num ȣ��
		printf("t_id = %d  i = %d \n", t_id, i);
		i++; //thread num��ŭ +
	}
	printf("t_id = %d  i = %d \n", t_id, i);
}