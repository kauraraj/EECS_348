#include <stdio.h>
#include <stdlib.h>

float max(float numbers[]) { // Function that returns the max number in a given list

    float max = numbers[0]; // Initialize the max as the first element

    for (int i = 0; i < 12; i++) { 

        if (numbers[i] > max) { // Compare elements in list with current max; if a given element is greater, reassign the maximum value to that
            max = numbers[i];
        }
    }
    return max; // After going through entire list, return maximum value
}

float min(float numbers[]) { // Function that returns the min number in a given list

    float min = numbers[0]; // Initialize the min as the first element

    for (int i = 0; i < 12; i++) {

        if (numbers[i] < min) { // Compare elements in list with current min; if a given element is less, reassign the minimum value to that
            min = numbers[i];
        }
    }
    return min; // After going through entire list, return minimum value
}

float average(float numbers[]) { // Function that returns average of a given list that has numbers

    float total = 0; // Initialize total to 0 as we will add the numbers to this 
    for (int i = 0; i < 12; i++) {
        total += numbers[i]; // Add every element total
    }
    return total/12; // Return the average (total value / number of values)
}

int main() {

    char months[12][20] = {"January", "February", "March", "April","May", "June", "July", "August", "September", "October", "November", "December"}; // Initialize array with months of the year
    float numbers[12];

    FILE *input = fopen("numbers.txt", "r"); // Open a given .txt file that should contain 12 values that have total sales for each month starting from January
    for (int i = 0; i < 12; i++) {
        fscanf(input, "%f", &numbers[i]); // Store each value in the array; the location of each value corresponds to the correct month
    }

    // (1) Monthly sales report for 2022
    printf("Monthly sales report for 2022:\n"); // Format output
    printf("%-10s %5s\n", "Month", "Sales");
    
    for (int i = 0; i < 12; i++) { // Simply print out the values obtained from input file along with the month they're from
        printf("%-10s $%.2f\n", months[i], numbers[i]); 
    }

    // (2) Sales Summary

    printf("Sales summary:\n");
    printf("Minimum sales: \t$%.2f  (%s)\n",min(numbers), months[0]); // Print the month that had the lowest sales
    printf("Maximum sales: \t$%.2f  (%s)\n",max(numbers), months[11]); // Print month with most sales
    printf("Average sales: \t$%.2f\n",average(numbers)); // Print average sales for a given month

    // (3) Six-Month Moving Average Report:
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= 6; i++) { // Iterate over a range of 0-6 that allows us to calulate moving average 
        float moving_avg = 0; 
        for (int j = 0; j < 6; j++) { // Calculate the value of summing 6 elements consecutively that represent the range
            moving_avg += numbers[i + j];
        }
        printf("%-9s - %-9s   $%.2lf\n", months[i], months[i+5],moving_avg /= 6); // Print the moving sum with the corresponding months
    }

    // (4) Sales Report (Highest to Lowest):

    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-10s %5s\n", "Month", "Sales");

    // Since C doesn't have a built-in function that lets us know the index based off of a value, we have to implement something similar

    int locations[12];  // locations stores the location each month should correspond to based on how its sorted

    for (int i = 0; i < 12; i++) {
        locations[i] = i; // Fill out location array with values 0-11 which represent the array indices for months array
    }

    for (int i = 0; i < 11; i++) { // Sort array based on values in the numbers array (this is to make sure our months correspond to right value)
        for (int j = i + 1; j < 12; j++) {
            if (numbers[locations[i]] < numbers[locations[j]]) {
                // Compare values in numbers array using the locations initialized before
                int temp_var = locations[i]; // Swap locations if current element is less than next element
                locations[i] = locations[j];
                locations[j] = temp_var;
            }
        }
    }
    for (int i = 0; i < 12; i++) { // Print months and the numbers that correspond to them
        printf("%-10s $%.2f\n", months[locations[i]], numbers[locations[i]]);

}
    return 0;
}
