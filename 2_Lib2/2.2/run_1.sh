echo "========================================"

# initialization
TIME="$(date +%H_%M_%S)"
filename="result1_$TIME.txt"
touch $filename
echo "amount\ttime" >> $filename

# delete existing file
if [ -f "method1.exe" ]
then
	echo "Deleting existing file ..."
	rm method1.exe
	echo "Deleting finished"
	echo ""
fi;

# compile file
echo "Compiling Method1 ..."
g++ -std=c++11 -o method1.exe ./method1.cpp

# judge if compiling succeded
if [ -f ./method1.exe ]
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
	# echo "$i :" >> $filename
	# (./method1.exe i) >> $filename
	./method1.exe $i $filename
	echo "loop finished for $i"
done;

echo "========================================"
echo "Shell finished"
rm ./method1.exe
echo "========================================"
exit 0
