if [ -f ./hellomp_linux ]
then
	rm ./hellomp_linux
fi;

gcc -fopenmp -O2 -o hellomp_linux hellomp_linux.cpp

