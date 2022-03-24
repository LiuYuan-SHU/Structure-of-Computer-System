#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <omp.h>
#include <time.h>

using namespace std;

#define MAX_SIZE 10000
#define MY_NUM_OF_THREADS 24

int A[MAX_SIZE][MAX_SIZE];
int length = 0;

void init()
{
	assert(length > 0);
	for(int i = 0; i < length; i++)
	{
		A[i][0] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		for(int j = 1; j < length; j++)
		{
			A[i][j] = rand()%10;
		}
	}
}

double addRow_method()
{
	int i,j;
	clock_t start, end;
	start = clock();
#pragma omp parallel for num_threads(MY_NUM_OF_THREADS) private(i,j)
	for(i = 0; i < length; i++)
	{
		for(j = 1; j < length; j++)
		{
			A[i][0] += A[i][j];
		}
	} 
#pragma omp barrier
	end = clock();

	return (end - start) * 1.0 / CLOCKS_PER_SEC;
}



int main(int argc, char** argv)
{
	assert(argc == 3);
	length = atoi(argv[1]);
	string filename(argv[2]);
	ofstream out(filename, ofstream::app);

	init();

	out << length << '\t' << addRow_method() << endl;

#ifndef NDEBUG
	int sum = 0;
	for (int i = 0; i < length; i++, sum = 0)
	{
		for (int j = 0; j < length; j++)
		{
			cout << A[i][j] << " ";
			sum += A[i][j];
		}
		cout << endl;
		cout << "sum = " << (sum - A[i][0]) << endl;
	}
#endif

	out.close();

	return 0;
}
