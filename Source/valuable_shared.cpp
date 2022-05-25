#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
	int a[10];
	int t_id, i;
	omp_set_num_threads(8);
#pragma omp parallel shared(a) private(t_id) //같은 a배열에 접속
	{
		t_id = omp_get_thread_num(); //thread num 호출
		a[t_id] = t_id + 2;
	}
	for (i = 0; i < 10; i++)
	{
		printf("a[%d] = %d\n", i, a[i]); // 사용thread = 8개, a배열은 10개, 같은배열에 접속->a배열 순차출력,      마지막 2개배열에는 랜덤값 input
	}
	return 0;
}