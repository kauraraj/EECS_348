#include <iostream>
#include <fstream>
#include <string>

#define MAX_SIZE 50

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int N);
void matrix_addition(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int matrix_c[MAX_SIZE][MAX_SIZE], int n);
void matrix_multiplication(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int matrix_c[MAX_SIZE][MAX_SIZE], int n);
void matrix_subtraction(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int matrix_c[MAX_SIZE][MAX_SIZE], int n);
void matrix_update(int matrix[MAX_SIZE][MAX_SIZE],int row, int column, int new_val, int n);
int matrix_max(int matrix[MAX_SIZE][MAX_SIZE], int n);
void matrix_transposition(int matrix[MAX_SIZE][MAX_SIZE],int matrix_transposed[MAX_SIZE][MAX_SIZE], int n);
void read_matrices_from_file(const char* filename, int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int& n);


// Problem 2
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
// Problem 3
void matrix_addition(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int matrix_c[MAX_SIZE][MAX_SIZE], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                matrix_c[i][j] = matrix_a[i][j] + matrix_b[i][j];
            }
        }
}
// Problem 4
void matrix_multiplication(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int matrix_c[MAX_SIZE][MAX_SIZE], int n) {

    for(int i = 0; i < n; i++) { // Want ensure matrix C is empty to ensure validity of arithmetic
        for(int j = 0; j < n; j++) {
            matrix_c[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                matrix_c[i][j] = matrix_c[i][j] + matrix_a[i][k] * matrix_b[k][j];
            }   
        }
    }
}
// Problem 5
void matrix_subtraction(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int matrix_c[MAX_SIZE][MAX_SIZE], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                matrix_c[i][j] = matrix_a[i][j] - matrix_b[i][j];
            }
        }

}

// Problem 6
void matrix_update(int matrix[MAX_SIZE][MAX_SIZE],int row, int column, int new_val, int n) {
    matrix[row][column] = new_val;
}

// Problem 7

int matrix_max(int matrix[MAX_SIZE][MAX_SIZE], int n) {

    int max_val = matrix[0][0];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
    }
    return max_val;
}

// Problem 8

void matrix_transposition(int matrix[MAX_SIZE][MAX_SIZE],int matrix_transposed[MAX_SIZE][MAX_SIZE], int n) {

    for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix_transposed[i][j] = matrix[j][i];
            }
        }
}

// Problem 1

void read_matrices_from_file(const char* filename, int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int& n) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file\n";
        exit(1);
    }

    file >> n; // Read the size of the matrices

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> matrix_a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> matrix_b[i][j];
        }
    }

    file.close();
}

int main() {

    int matrix_a[MAX_SIZE][MAX_SIZE],matrix_b[MAX_SIZE][MAX_SIZE], matrix_c[MAX_SIZE][MAX_SIZE];
    int n;
    int row, column, new_val;

    read_matrices_from_file("matrix_input.txt", matrix_a, matrix_b, n);

    std::cout << std::setw(5) << "\nMatrix 1:\n";
    print_matrix(matrix_a, n);
    std::cout << std::setw(5) << "Matrix 2:\n";
    print_matrix(matrix_b, n);

    std::cout << std::setw(5) << "Matrix 1 + Matrix 2 results in:\n";
    matrix_addition(matrix_a, matrix_b, matrix_c, n);
    print_matrix(matrix_c, n);

    std::cout << std::setw(5) << "Matrix 1 * Matrix 2 results in:\n";
    matrix_multiplication(matrix_a, matrix_b, matrix_c, n);
    print_matrix(matrix_c, n);


    std::cout << std::setw(5) << "Matrix 1 - Matrix 2 results in:\n";
    matrix_subtraction(matrix_a, matrix_b, matrix_c, n);
    print_matrix(matrix_c, n);

    std::cout << "Enter a new value and the row & column you want to place it in\n\n";
    std::cout << "New value: ";
    std::cin >> new_val;
    std::cout << "\nRow: ";
    std::cin >> row;
    std::cout << "\nColumn: ";
    std::cin >> column;

    if(row >= n || column >= n) {
        std::cout << "Invalid insertion position. You cannot place a value outside of the matrix dimensions. Exiting code...";
        return 0;
    }

    matrix_update(matrix_a,row,column,new_val,n);
    std::cout << std::setw(5) << "\nMatrix 1 after inserting " << new_val << " at row " << row << " and column " << column << "\n";
    print_matrix(matrix_a, n);

    std::cout << std::setw(5) << "The max value in matrix a is: " << matrix_max(matrix_a, n) << "\n";
    std::cout << std::setw(5) << "\nThe transposed matrix a is:\n";
    matrix_transposition(matrix_a, matrix_c, n);
    print_matrix(matrix_c, n);

    return 0;
}