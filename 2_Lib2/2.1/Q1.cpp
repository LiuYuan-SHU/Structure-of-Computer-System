/*****************************************************
 * 1. 对于每个线程都打印出它的id号，对于id号为0的线程打印出线程数目。
 * 2. g++编译选项
 * 		g++ -fopenmp -O2 -o hellomp.out hellomp.cpp
 * 			-o 后接生成的可执行文件名。若不指定，则默认的输出文件名为a.out；
 * 			-fopenmp 启动OpenMP环境；
 * 			-O2 使用编译器的O2优化选项。	
 * 3. 添加Visual Studio对OpenMP编译选项：
 * 		1. 右键点击`Solution Explorer`中的项目名称，选择`Properties`
 * 		2. 将`Configuration`改为`All Configurations`
 * 		3. 将`Platform`改为`All Platforms`
 * 		4. 在`Configurations Properties`中，选择`C/C++`
 * 		5. 在`Language`子选项中将
 * 			1.	`Open MP Support`设置为Yes
 * 			2.	`Conformance Mode`设置为No
 * 	
 ************************************************************
 *
 *	1. Print its ID number for each thread, and print the number of threads for the thread whose ID is 0.
 *	2. G++ compilation option
 *		g++ -fopenmp -O2 -o hellomp.out hellomp.cpp
 *			-o Specifies the executable file name generated after delivery. 
 *				If this parameter is not specified, the default output file name is a.out.
 *			-fopenmp Starts the OpenMP environment.
 *			-o2 uses the O2 optimization option of the compiler.
 *	3. Add Visual Studio to OpenMP compilation options:
 *		1. Right-click the project name in 'Solution Explorer' and select 'Properties'
 *		2. Change 'Configuration' to 'All Configurations'
 *		3. Change 'Platform' to 'All Platforms'
 *		4. In 'Configurations Properties', select' C/C++ '
 *		5. In the 'Language' sub-option
 *			1. Set 'Open MP Support' to Yes
 *			2. Set 'Conformance Mode' to No
 *****************************************************/

#include <cstdio>
#include <omp.h>

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
	 * 
	 * 1. `#pragma omp parallel` is a standard OpenMP statement
	 *		It means that the statements that follow it execute in multiple threads.
	 *		Note that each thread does the same thing.
	 * 2. `#pragma omp parallel private(nthreads, tid)` is a compile guidance statement
	 *		Each thread has its own private `nthreads` and `tid` variables,
	 *		Changes made by one thread to a private variable do not affect that variable in other threads.
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
