echo "========================================"

# initialization
TIME="$(date +%H_%M_%S)"
filename="result_prac_$TIME.txt"
touch $filename
echo "amount\ttime" >> $filename

# delete existing file
if [ -f "practice.exe" ]
then
	echo "Deleting existing file ..."
	rm practice.exe
	echo "Deleting finished"
	echo ""
fi;

# compile file
echo "Compiling practice ..."
g++ -D NDEBUG -std=c++11 -O3 -o practice.exe ./practice.cpp

# judge if compiling succeded
if [ -f ./practice.exe ]
then
	echo "Compiling successfully, running the program ..."
	echo "Start with 100, add 100 per time ..."
	echo "please check the result in $filename"
else
	echo "Compiling failed, Shell exiting ..."
	exit -1
fi;

# loop the program, till num reaches 100000
for ((i=100; i <= 10000; i = i + 100))
do
	./practice.exe $i $filename
	echo "loop finished for $i"
done;

echo "========================================"
echo "Shell finished"
rm ./practice.exe
echo "========================================"
exit 0
