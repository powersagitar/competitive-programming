.PHONY: run

run: main
	cat input.txt | ./main

main: unoptimized.cc
	clang++ -o main unoptimized.cc -O3
