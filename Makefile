a.out: main.o base.o extra.o
	gcc -o a.out main.o base.o extra.o
main.o: base.h extra.h record.h main.c
	gcc -c -o main.o main.c
base.o : base.h base.c
	gcc -c -o base.o base.c
extra.o: extra.h extra.c
	gcc -c -o extra.o extra.c
clean:
	rm a.out main.o base.o extras.o

