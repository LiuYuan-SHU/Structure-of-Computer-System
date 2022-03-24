#include <cstdio>
#include <omp.h>
#include <stdio.h>

using namespace std;

int main()
{
	int nthreads, tid;
	// comment next line, use command in bash:
	//		1. OMP_NUM_THREADS=10
	//		2. export OMP_NUM_THREADS
	// omp_set_num_threads(8);

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
