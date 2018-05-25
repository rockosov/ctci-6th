#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_array(char* array, int l, int r) {
    size_t i = 0;

    for (i = l; i < r; ++i) {
        printf("%c ", array[i]);
    }

    printf("%c\n", array[i]);
}

/* Merge arrays array[l..m] and array[m+1..r] */
void merge(char* array, int l, int m, int r) {
    int i = 0;
    int j = 0;
    int k = 0;
    int size_l = m - l + 1;
    int size_r = r - m;

    printf("Merge function\n");
    printf("Array\n");
    print_array(array, l, r);
    printf("l = %d, m = %d, r = %d\n", l, m, r);

    printf("size_l = %d\n", size_l);
    printf("size_r = %d\n", size_r);

    char L[size_l];
    char R[size_r];

    /* Copy left array */
    for (i = 0; i < size_l; ++i) {
        L[i] = array[l + i];
    }

    /* Copy right array */
    for (j = 0; j < size_r; ++j) {
        R[j] = array[m + 1 + j];
    }

    printf("Array L\n");
    print_array(L, 0, size_l - 1);

    printf("Array R\n");
    print_array(R, 0, size_r - 1);

    i = 0;
    j = 0;
    k = l;
    while(i < size_l && j < size_r) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while(i < size_l) {
        array[k++] = L[i++];
    }

    while(j < size_r) {
        array[k++] = R[j++];
    }

    printf("Full array after merge function\n");
    printf("%s\n", array);
}

void merge_sort(char* array, int l, int r) {
    int m = 0;

    if (l < r) {
        printf("Merge sort\n");
        printf("Array\n");
        print_array(array, l, r);
        printf("l = %d, r = %d\n", l, r);

        m = l + (r - l) / 2;
        printf("m = %d\n", m);

        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

bool is_permutation(char* array1, char* array2) {
    size_t array1_len = strlen(array1);
    size_t array2_len = strlen(array2);

    if (array1_len != array2_len) {
        return false;
    }

    printf("Before merge sort\n");
    printf("array1 = %s\n", array1);
    printf("array2 = %s\n", array2);

    merge_sort(array1, 0, array1_len - 1);
    merge_sort(array2, 0, array2_len - 1);

    printf("After merge sort\n");
    printf("array1 = %s\n", array1);
    printf("array2 = %s\n", array2);

    return strcmp(array1, array2) == 0;
}

int main(int argc, char** argv) {
    char array1[] = "bcd";
    char array2[] = "dca";

    printf("array1 = %s\n", array1);
    printf("array2 = %s\n", array2);

    printf("is permutation = %s\n",
           is_permutation(array1, array2) ? "true" : "false");

    return 0;
}

