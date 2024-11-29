#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// extern void imgCvtGrayInttoFloat(int height, int width, uint8_t** inputVals, float** outputVals);

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
    int choice;
    double avgtime = 0.0;
    srand(time(0));
    uint8_t random;
    clock_t start, end;
    double time_taken;

    // Read dimensions
    printf("Enter:\n1 if Manual input\n2 if Automated 10 x 10 matrix\n3 if Automated 100 x 100 matrix\n4 if automated 1000 x 1000 matrix\ninput: ");
    scanf("%d", &choice);
    if (choice == 1) {
        scanf("%d", &height);
        scanf("%d", &width);
    } else if (choice == 2) {
        height = 10;
        width = 10;
    } else if (choice == 3) {
        height = 100;
        width = 100;
    } else if (choice == 4) {
        height = 1000;
        width = 1000;
    }

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
            if (choice == 1) {
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
            else {
                random = rand() % 256;
                inputVals[i][j] = random;
            }
        }
    }
    */


    for (int i = 1; i <= 30; i++) {
        start = clock();
        // Call function to convert integer to float
        CimgCvtGrayInttoFloat(height, width, inputVals, CoutputVals);
        end = clock();
        time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        printf("Total time taken(%d): %.4f\n", i, time_taken);
        avgtime += time_taken;
    }
    
    avgtime /= 30;

    printf("Average time taken: %.4f\n", avgtime);

    /*
    printf("\n=========== C ===========\n");
    /*
    printf("The output 2D array is:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", CoutputVals[i][j]);
        }
        printf("\n");
    }
    */

    /*
    start = clock();
    imgCvtGrayInttoFloat(height, width, inputVals, ASMoutputVals);
    end = clock();
    time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

    // Print the output array (float values)
    printf("\n======= ASSEMBLY =======\n");
    /*
    printf("The output 2D array is:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", ASMoutputVals[i][j]);
        }
        printf("\n");
    }
    printf("Total time taken: %.4f\n", time_taken);
    */

    return 0;
}
