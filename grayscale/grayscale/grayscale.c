#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void grayscale(int b, int* a);

int main() {
	int a = 0;
	int b = 94;
	grayscale(b, &a);
	printf("%d", a);
	return 0;
}