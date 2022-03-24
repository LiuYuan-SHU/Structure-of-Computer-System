echo "========================================"

# initialization
TIME="$(date +%H_%M_%S)"
filename="result2_$TIME.txt"
touch $filename
echo "amount\ttime" >> $filename

# delete existing file
if [ -f "method2.exe" ]
then
	echo "Deleting existing file ..."
	rm method2.exe
	echo "Deleting finished"
	echo ""
fi;

# compile file
echo "Compiling Method2 ..."
g++ -std=c++11 -o method2.exe ./method2.cpp

# judge if compiling succeded
if [ -f ./method2.exe ]
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
	./method2.exe $i $filename
	echo "loop finished for $i"
done;

echo "========================================"
echo "Shell finished"
rm ./method2.exe
echo "========================================"
exit 0
