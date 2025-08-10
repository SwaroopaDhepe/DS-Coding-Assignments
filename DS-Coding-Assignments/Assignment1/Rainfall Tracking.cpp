//Rainfall Tracking:
Write a program to track rainfall data for 3 cities over 4 months. Using a 2D array, we can store the data, calculate the average rainfall for each city, and display the rainfall data in a tabular format.

#include <iostream>
using namespace std;

int main() {
    float rainfall[3][4];
    float average = 0;
    float total = 0;

    printf("\nEnter rainfall data for 3 cities:\n");
    for(int c = 0; c < 3; c++) {
        printf("For city %d: \n", c + 1);
        for(int m = 0; m < 4; m++) {
            printf("For month %d: ", m + 1);
            scanf("%f", &rainfall[c][m]);
        }
    }

    printf("\nRainfall Tracker:\n");
    printf("Sr.No.\tCity Name\tM1\t\tM2\t\tM3\t\tM4\t\tAverage\n");

    for(int i = 0; i < 3; i++) {
        total = 0;
        printf("%d\tCity %d\t\t", i + 1, i + 1);
        for(int j = 0; j < 4; j++) {
            printf("%.2f\t\t", rainfall[i][j]);
            total += rainfall[i][j];
        }
        average = total / 4.0;
        printf("%.2f\n", average);
    }

    return 0;
}
