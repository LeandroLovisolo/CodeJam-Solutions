.PHONY: all clean small

all: energy

energy: energy.cpp
	g++ -ggdb -o energy energy.cpp

sample: energy
	./energy < sample.in > sample.out && cat sample.out

small: energy
	./energy < B-small-practice.in > B-small-practice.out && cat B-small-practice.out

large: energy
	./energy < B-large-practice.in > B-large-practice.out && cat B-large-practice.out

clean:
	rm -f energy *.out