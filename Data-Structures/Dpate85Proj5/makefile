
all: fakemake

fakemake: main.c hmap.h hmap.o graph.h graph.o
	gcc main.c hmap.o graph.o -o fakemake

hmap.o: hmap.c hmap.h
	gcc -c hmap.c

graph.o: graph.c graph.h
	gcc -c graph.c

clean: 
	rm fakemake *.o
