#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * Given an image represented by an NxN matrix, where each pixel in the
 * image is 4 bytes, write a method to rotate the image by 90 degrees.
 * Can you do this in place?
 */

/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

#define N 5

void print_square_matrix(int matrix[][N]) {
    int i = 0;
    int j = 0;

    printf("Square Matrix:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf(" %.2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void four_swap(int* top, int* right, int* bottom, int* left) {
    int tmp = *top;

    *top = *left;
    *left = *bottom;
    *bottom = *right;
    *right = tmp;

    return;
}

void rotate_square_matrix(int matrix[][N]) {
    int layer = 0;
    int end = 0;
    int start = 0;
    int i = 0;

    for (layer = 0; layer < N / 2; ++layer) {
        start = layer;
        end = (N - 1 - layer);
        for (i = start; i < end; ++i) {
            four_swap(&matrix[start][i],
                      &matrix[i][end],
                      &matrix[end][end - i],
                      &matrix[end - i][start]);
        }
    }

    return;
}

int main(int argc, char** argv) {
    int matrix[N][N] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    printf("Matrix before rotation:\n");
    print_square_matrix(matrix);

    rotate_square_matrix(matrix);

    printf("Matrix after rotation:\n");
    print_square_matrix(matrix);

    return 0;
}

