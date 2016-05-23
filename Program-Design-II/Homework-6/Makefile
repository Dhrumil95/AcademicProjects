CC = gcc

objects = 

llist.o: $(objects)
	$(CC) llist.c -c

imsort: $(objects)
	$(CC) imsort.c llist.c -o imsort -lm

clean: 
	rm *.o imsort
