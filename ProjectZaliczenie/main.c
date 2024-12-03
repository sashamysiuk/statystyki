#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <pbPlots.h>
#include <supportLib.h>

void draw_chart(float* nums, int size, float average, float stand_dev) {
    int* x;
    x = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        x[i] = i + 1;
    }
   
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    DrawBarPlot(imageRef, 600, 400, x, size, nums, size);

    size_t length;
    //double *pngData = ConvertToPNG(&length,imageRef->image);

    //WriteToFile(pngData, length, "plot.png");
}

float calc_average(float* nums, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return sum / size;
}

float calc_standard_dev(float* nums, int size, float average) {
    float sum = 0;

    for (int i = 0; i < size; i++) {
        sum += pow(nums[i] - average,2);
    }
    return sqrt(sum / (size-1));
}

int main() {
    float* nums;
    int size;

    printf("Enter array size:");
    scanf_s("%d", &size);

    if (size == 0) {
        printf("Size cant be 0 \n");
        system("pause");
        return 1;
    }

    nums = (float*)malloc(size * sizeof(float));

    if (nums == NULL) {
        printf("Memory not allocated.\n");
        system("pause");
        return 1;
    }
    else {
        printf("Input numbers: \n");
        float number;

        for (int i = 0; i < size; i++) {
            printf("%d. ", i+1);
            scanf_s("%f", &number);
            nums[i] = number;
        } 

        float average = calc_average(nums, size);
        printf("Average number in your array: %f\n", average);

        float stand_dev = calc_standard_dev(nums, size, average);

        if (size < 2) {
            printf("Can't calculate standard deviation for your sample, please provide at least two numbers\n");
        }
        else {
            printf("Standard deviation in your array: %f\n", stand_dev);
        }

        draw_chart(nums, size, average, stand_dev);
      
        system("pause");
        return 0;
    }
}