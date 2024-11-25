#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// extern void imgCvtGrayInttoFloat()

void CimgCvtGrayInttoFloat() {
	
}

int main() {
	int height;
	int width;
	int i;
	int j;

	scanf("%d", &height);
	scanf("%d", &width);

	float** inputVals = (float**)malloc(height * sizeof(float*));
	for (i = 0; i < height; i++) {
		inputVals[i] = (float*)malloc(width * sizeof(float));
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("Enter value for array[%d][%d]: ", i, j);
			scanf("%f", &inputVals[i][j]);
		}
	}

	printf("The 2D array is:\n");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", (int)inputVals[i][j]);
		}
		printf("\n");
	}


	return 0;
}