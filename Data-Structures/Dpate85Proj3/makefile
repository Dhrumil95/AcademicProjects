

hmap.o: hmap.c hmap.h
	gcc -c hmap.c
	
jumble: jumble.c hmap.o
	gcc jumble.c hmap.o -o jumble
clean:
	rm -f *.o jumble

