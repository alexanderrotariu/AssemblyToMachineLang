hw3: main.o parser.o assembler.o
	gcc -o hw3 main.o parser.o assembler.o

main.o: main.c parser.h
	gcc -c main.c

parser.o: parser.c parser.h
	gcc -c parser.c

assembler.o: assembler.c parser.h assembler.h
	gcc -c assembler.c

clean:
	rm *.o
	rm hw3
