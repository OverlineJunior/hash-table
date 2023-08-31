all: main.exe run

main.exe: main.c ../hash_table.c ../libs/maybe_int.c ../libs/bucket.c ../libs/key_value.c
	@clang -Wall -o main.exe main.c ../hash_table.c ../libs/maybe_int.c ../libs/bucket.c ../libs/key_value.c

run: main.exe
	@./main.exe
