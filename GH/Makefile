testaesparsas: testaesparsas.o esparsas.o
	gcc -o testaesparsas testaesparsas.o esparsas.o

testaesparsas.o: testaesparsas.c
	gcc -c testaesparsas.c 

esparsas.o: esparsas.c esparsas.h
	gcc -c esparsas.c

clean:
	rm -f *.o testaesparsas
