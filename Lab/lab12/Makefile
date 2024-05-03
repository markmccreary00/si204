part1: 
	g++ part1.cpp listLib.cpp -o part1
part2: 
	g++ part2.cpp listLib.cpp -o part2
part3: 
	g++ part3.cpp listLib.cpp -o part3
part4: 
	g++ part4.cpp listLib.cpp -o part4

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py
