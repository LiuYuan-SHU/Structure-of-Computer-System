OMP_NUM_THREADS=10
export OMP_NUM_THREADS
g++ -fopenmp -o ./Q2.exe ./Q2.cpp
./Q2.exe
rm ./Q2.exe
