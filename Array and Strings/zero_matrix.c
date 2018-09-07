#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * Write an algorithm such that if an element in an MxN matrix is 0,
 * its entire row and column are set to O.
 */

/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

#define M 4
#define N 5

void print_matrix(int matrix[M][N]) {
    int i = 0;
    int j = 0;

    printf("Matrix:\n");
    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; ++j) {
            printf(" %.2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void zeroing_matrix(int matrix[M][N]) {
    bool first_row_has_zero = false;
    bool first_column_has_zero = false;
    int i = 0;
    int j = 0;

    /* Determine do we need to zeroing first row in the end */
    for (i = 0; i < N; ++i) {
        if (matrix[0][i] == 0) {
            first_row_has_zero = true;
        }
    }

    /* Determine do we need to zeroing first column in the end */
    for (i = 0; i < M; ++i) {
        if (matrix[i][0] == 0) {
            first_column_has_zero = true;
        }
    }

    /* Check all other elements */
    for (i = 1; i < M; ++i) {
        for (j = 1; j < N; ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    /* Zeroing based on first row data */
    if (first_row_has_zero || first_column_has_zero) {
        matrix[0][0] = 0;
    }

    for (j = 1; j < N; ++j) {
        if (matrix[0][j] == 0) {
            for (i = 1; i < M; ++i) {
                matrix[i][j] = 0;
            }
        }

        if (first_row_has_zero) {
            matrix[0][j] = 0;
        }
    }

    /* Zeroing based on first column data */
    for (i = 1; i < M; ++i) {
        if (matrix[i][0] == 0) {
            for (j = 1; j < N; ++j) {
                matrix[i][j] = 0;
            }
        }

        if (first_column_has_zero) {
            matrix[i][0] = 0;
        }
    }

    return;
}

int main(int argc, char** argv) {
    int matrix[M][N] = {
        { 1,  2,  0,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13,  0, 15},
        { 0, 22, 23, 24, 25}
    };

    printf("Matrix before zeroing:\n");
    print_matrix(matrix);

    zeroing_matrix(matrix);

    printf("Matrix after zeroing:\n");
    print_matrix(matrix);

    return 0;
}

