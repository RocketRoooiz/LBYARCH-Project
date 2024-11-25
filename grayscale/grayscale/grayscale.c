#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

extern void ASMimgCvtGrayInttoFloat(int height, int width, uint8_t** inputVals, float** outputVals);

void CimgCvtGrayInttoFloat(int height, int width, uint8_t** inputVals, float** outputVals) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            outputVals[i][j] = (float)inputVals[i][j] / 255.0f;
        }
    }
}

int main() {
    int height;
    int width;
    clock_t start, end;
    double time_taken;

    // Read dimensions
    scanf("%d", &height);
    scanf("%d", &width);

    // Dynamically allocate memory for inputVals and outputVals
    uint8_t** inputVals = (uint8_t**)malloc(height * sizeof(uint8_t*));
    for (int i = 0; i < height; i++) {
        inputVals[i] = (uint8_t*)malloc(width * sizeof(uint8_t));
    }

    float** CoutputVals = (float**)malloc(height * sizeof(float*));
    for (int i = 0; i < height; i++) {
        CoutputVals[i] = (float*)malloc(width * sizeof(float));  // For storing float values
    }

    float** ASMoutputVals = (float**)malloc(height * sizeof(float*));
    for (int i = 0; i < height; i++) {
        ASMoutputVals[i] = (float*)malloc(width * sizeof(float));  // For storing float values
    }

    // Input values for inputVals array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            while (1) {
                int temp;
                if (scanf("%d", &temp) != 1 || temp > 255 || temp < 0) {
                    while (getchar() != '\n');
                    printf("Invalid input! Please enter a value between 0 and 255.\n");
                }
                else {
                    inputVals[i][j] = (uint8_t)temp;
                    break;
                }
            }
        }
    }

    // Print the input array
    printf("\nThe input 2D array is:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%hhu ", inputVals[i][j]);
        }
        printf("\n");
    }

    start = clock();
    // Call function to convert integer to float
    CimgCvtGrayInttoFloat(height, width, inputVals, CoutputVals);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the output array (float values)
    printf("\n=========== C ===========\n");
    printf("The output 2D array is:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", CoutputVals[i][j]);
        }
        printf("\n");
    }
    printf("Total time taken: %.4f\n", time_taken);

    start = clock();
    ASMimgCvtGrayInttoFloat(height, width, inputVals, ASMoutputVals);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the output array (float values)
    printf("\n======= ASSEMBLY =======\n");
    printf("The output 2D array is:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", ASMoutputVals[i][j]);
        }
        printf("\n");
    }
    printf("Total time taken: %.4f\n", time_taken);

    return 0;
}
