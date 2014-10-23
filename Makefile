all:
	gcc -o example cut_example.c cut.h

clean:
	rm -f ./example