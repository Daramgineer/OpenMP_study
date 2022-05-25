#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
	int t_id = 0;
	int i = 10;
	omp_set_num_threads(8); //thread 사용개수 지정
#pragma omp parallel private(t_id) //thread num 지역변수화
	{
		t_id = omp_get_thread_num(); //thread num 호출
		printf("t_id = %d  i = %d \n", t_id, i);
		i++; //thread num만큼 +
	}
	printf("t_id = %d  i = %d \n", t_id, i);
}