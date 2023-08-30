all: main.exe run

main.exe: main.c ../hash_table.c
	@clang -Wall -o main.exe main.c ../hash_table.c

run: main.exe
	@./main.exe
