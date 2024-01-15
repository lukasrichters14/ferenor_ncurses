ferenor: ferenor.c windows.c
	gcc -g ferenor.c windows.c -o ferenor -lncurses


clean:
	rm ferenor
	rm *.o