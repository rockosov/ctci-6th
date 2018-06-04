#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * Task: Write a method to replace all spaces in a string with '%20: You may
 * assume that the string has sufficient space at the end to hold the
 * additional characters, and that you are given the "true" length of the
 * string.
 * EXAMPLE
 * Input: "Mr John Smith    ", 13
 * Output: "Mr%20John%20Smith"
 */

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1), we don't have additional space
 */

/* This function print string array which doesn't have \0 byte in the end. */
void print_string_array(char* array, size_t len) {
    size_t i = 0;

    for (i = 0; i < (len - 1); ++i) {
        printf("%c", array[i]);
    }

    printf("%c\n", array[i]);
}

size_t urlify(char* input_array, size_t input_len) {
    int i = 0;
    int j = 0;
    size_t actual_len = input_len;

    for (i = 0; i < input_len; ++i) {
        if (input_array[i] == ' ') {
            actual_len += 2; /* 2 extra bytes for %20 */
        }
    }

    j = actual_len - 1;
    for (i = input_len - 1; i >= 0; --i) {
        if (input_array[i] != ' ') {
            input_array[j--] = input_array[i];
        } else {
            input_array[j--] = '0';
            input_array[j--] = '2';
            input_array[j--] = '%';
        }
    }

    return actual_len;
}

int main(int argc, char** argv) {
    size_t input_len = 13;
    size_t actual_len = 0;
    char input_array[] = {'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ',
                          'S', 'm', 'i', 't', 'h', ' ', ' ', ' ', ' '};

    printf("Input Array String before URLify:\n");
    print_string_array(input_array, input_len);

    actual_len = urlify(input_array, input_len);

    printf("Input Array String after URLify:\n");
    print_string_array(input_array, actual_len);

    return 0;
}

