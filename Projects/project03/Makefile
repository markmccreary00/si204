part1: 
	g++ part1.cpp easycurses.cpp myLib.cpp -l ncurses -o part1
part2: 
	g++ part2.cpp easycurses.cpp myLib.cpp Pos.cpp -l ncurses -o part2
part3: 
	
part4: 

part5: 

################## DON'T TOUCH BELOW ##################
run1: part1
	@./part1
run_%: %
	@test -f $* && echo "$*: Code compiled successfully" 

