search:
	ls

main: gui.o history.o tokenizer.h 
	gcc -o final gui.o history.o

gui.o: gui.c tokenizer.h history.h history.c
	gcc -c gui.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm -f *.o *~ *#
