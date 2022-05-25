#include <stdio.h>
#include <omp.h>
#include <math.h>


int main() //기본적 for문 형태
{
	int i, x = 0;

#pragma omp parallel private(i) //기본적인 for문 동기화, i변수 thread 종속
#pragma omp for
	for (i = 0; i < 10; i++)
	{
		x++;
		printf("x=%d\n", x);
	}
}

int main() //private, for문 사용없이 같은결과 도출(lock 동기화)
{
	int x = 0;
	omp_lock_t lock; //lock 사용 선언
	omp_init_lock(&lock); //lock 설정 초기화

#pragma omp parallel
	{
		omp_set_lock(&lock);  //이하영역 동기화 진행, i변수 thread 종속
		x++;
		printf("x=%d\n", x);
		omp_unset_lock(&lock); //동기화 해제
	}
}