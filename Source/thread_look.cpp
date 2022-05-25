#include <stdio.h>
#include <omp.h>
#include <math.h>


int main() //�⺻�� for�� ����
{
	int i, x = 0;

#pragma omp parallel private(i) //�⺻���� for�� ����ȭ, i���� thread ����
#pragma omp for
	for (i = 0; i < 10; i++)
	{
		x++;
		printf("x=%d\n", x);
	}
}

int main() //private, for�� ������ ������� ����(lock ����ȭ)
{
	int x = 0;
	omp_lock_t lock; //lock ��� ����
	omp_init_lock(&lock); //lock ���� �ʱ�ȭ

#pragma omp parallel
	{
		omp_set_lock(&lock);  //���Ͽ��� ����ȭ ����, i���� thread ����
		x++;
		printf("x=%d\n", x);
		omp_unset_lock(&lock); //����ȭ ����
	}
}