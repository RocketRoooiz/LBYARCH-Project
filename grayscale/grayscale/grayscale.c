#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

extern void imgCvtGrayInttoFloat(int height, int width, uint8_t** inputVals, float** outputVals);

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
    double Cavgtime = 0.0;
    double ASMavgtime = 0.0;
    srand(time(0));
    uint8_t random;
    clock_t start, end;
    double CTime_Taken[30], ASMTime_Taken[30];

    // Read dimensions
    printf("Options:\n1 - Manual input\n2 - Automated 10 x 10 matrix\n3 - Automated 100 x 100 matrix\n4 - Automated 1000 x 1000 matrix\nInput: ");
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

    for (int i = 0; i < 30; i++) {
        start = clock();
        CimgCvtGrayInttoFloat(height, width, inputVals, CoutputVals);
        end = clock();
        CTime_Taken[i] = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        Cavgtime += CTime_Taken[i];
        
        start = clock();
        imgCvtGrayInttoFloat(height, width, inputVals, ASMoutputVals);
        end = clock();
        ASMTime_Taken[i] = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        ASMavgtime += ASMTime_Taken[i];
    }

    // Print the output array (float values)
    printf("\n=================== Output 2D Array ===================\n");
    printf("-------------------------- C --------------------------\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", CoutputVals[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------- ASM -------------------------\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", ASMoutputVals[i][j]);
        }
        printf("\n");
    }
    printf("=======================================================\n");    

    int valid = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((ASMoutputVals[i][j] - CoutputVals[i][j]) != 0) {
                valid = 0;
            }
        }
    }

    if (valid == 0) {
        printf("\nOutput difference between C and ASM!\n");
    }
    else {
        printf("\nC and ASM have the same outputs.\n");
    }

    printf("======== Times (msec) ========\n");
    printf("| Loop # | C Time | ASM Time |\n");
    printf("+--------+--------+----------+\n");
    for (int i = 0; i < 30; i++) {
        printf("|   %-4d ", i+1);
        printf("| %.4f ", CTime_Taken[i]);
        printf("|  %.4f  |\n", ASMTime_Taken[i]);
    }
    Cavgtime /= 30;
    ASMavgtime /= 30;
    printf("+--------+--------+----------+\n");
    printf("|  Avg:  | %.4f |  %.4f  | msecs\n", Cavgtime, ASMavgtime);
    printf("==============================\n\n");

    return 0;
}
