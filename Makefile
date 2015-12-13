animalbin.out : as93_hw5.o Options.o
	gcc as93_hw5.o Options.o -o animalbin.out

as93_hw5.o : as93_hw5.c
	gcc -c as93_hw5.c

Options.o : Options.c
	gcc -c Options.c


clean :
	rm -rf *o animalbin.out animals.csv