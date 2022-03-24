//	1. 对于每个线程都打印出它的id号，对于id号为0的线程打印出线程数目。
//	2. gcc -fopenmp -O2 -o hellomp.out hellomp.c
//		-o 后接生成的可执行文件名。若不指定，则默认的输出文件名为a.out；
//		-fopenmp 启动OpenMP环境；
//		-O2 使用编译器的O2优化选项。	

#include <cstdio>
#include <omp.h>
#include <stdio.h>

using namespace std;

int main()
{
	int nthreads, tid;
	omp_set_num_threads(8);

	/*****************************************************************
	 *	1. #pragma omp parallel 是一条OpenMP标准语句，
	 *		它的含义是让它后面的语句按照多线程来执行。
	 *		需要注意的是每个线程都去做相同的事情。
	 *	2. #pragma omp parallel private(nthreads, tid)为编译制导语句，
	 *		每个线程都自己的nthreads和tid两个私有变量，
	 *		线程对私有变量的修改不影响其它线程中的该变量。
	 *****************************************************************/
#pragma omp parallel private(nthreads, tid)
	{
		tid = omp_get_thread_num();
		printf("Hello World from OMP thread %d\n", tid);
		if (tid == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Number of threads is %d\n", nthreads);
		}
	}
}
