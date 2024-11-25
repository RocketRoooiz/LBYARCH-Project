#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// extern void imgCvtGrayInttoFloat()

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

    // Read dimensions
    scanf("%d", &height);
    scanf("%d", &width);

    // Dynamically allocate memory for inputVals and outputVals
    uint8_t** inputVals = (uint8_t**)malloc(height * sizeof(uint8_t*));
    for (int i = 0; i < height; i++) {
        inputVals[i] = (uint8_t*)malloc(width * sizeof(uint8_t)); 
    }

    float** outputVals = (float**)malloc(height * sizeof(float*));
    for (int i = 0; i < height; i++) {
        outputVals[i] = (float*)malloc(width * sizeof(float));  // For storing float values
    }

    // Input values for inputVals array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            while (1) {
                int temp;
                printf("Enter value for array[%d][%d]: ", i, j);
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
    printf("The input 2D array is:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%hhu ", inputVals[i][j]); 
        }
        printf("\n");
    }

    // Call function to convert integer to float
    CimgCvtGrayInttoFloat(height, width, inputVals, outputVals);

    // Print the output array (float values)
    printf("The output 2D array is:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", outputVals[i][j]);  
        }
        printf("\n");
    }


    return 0;
}
