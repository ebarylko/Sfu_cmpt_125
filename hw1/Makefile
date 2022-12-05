test_assignment1: test_assignment1.c assignment1.c check_assignment1.c
	gcc -Wall -std=c99 -o test_assignment1 test_assignment1.c assignment1.c check_assignment1.c -lcheck

check_assignment1.c: assignment1.ts
	checkmk assignment1.ts > check_assignment1.c
