if [ -f ./hellomp_linux_2 ]
then
	rm ./hellomp_linux_2
fi;

gcc -fopenmp -O2 -o hellomp_linux hellomp_linux_2.cpp

