#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would become
 * a2b1c5a3. If the "compressed" string would not become smaller than the
 * original string, your method should return the original string. You can
 * assume the string has only uppercase and lowercase letters (a - z)
 */

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

int digit_width(int digit) {
    return floor(log10(abs(digit))) + 1;
}

char* compress_string(char* str) {
    size_t compressed_str_len = 0;
    char* compressed_str = NULL;
    size_t str_len = strlen(str);
    size_t i = 0;
    size_t j = 0;
    char current_sym = str[0];
    int sum = 1;

    for (i = 1; i < str_len; ++i) {
        if (str[i] == current_sym) {
            sum += 1;
        } else {
            compressed_str_len += digit_width(sum) + 1;

            sum = 1;
            current_sym = str[i];
        }
    }
    compressed_str_len += digit_width(sum) + 1;

    if (compressed_str_len >= str_len) {
        return str;
    } else {
        compressed_str = malloc(compressed_str_len + 1);

        memset(compressed_str, 0, compressed_str_len + 1);

        current_sym = str[0];
        sum = 1;
        for (i = 1, j = 0; i < str_len; ++i) {
            if (str[i] == current_sym) {
                sum += 1;
            } else {
                compressed_str[j++] = current_sym;
                snprintf(compressed_str + j, digit_width(sum) + 1, "%d", sum);
                j += digit_width(sum);

                sum = 1;
                current_sym = str[i];
            }
        }
        compressed_str[j++] = current_sym;
        snprintf(compressed_str + j, digit_width(sum) + 1, "%d", sum);
    }

    return compressed_str;
}

int main(int argc, char** argv) {
    char* test_data[] = {
        "aabcccccaaac",
        "aabcccccaaaaaaaaaaaaac",
        "aaaaaaaaaabcdefghijk",
        "aaaaaaaaaabcdefg",
        "aaaaaaaaaabcdefgh",
        "aabbcdAz",
        "abc"
    };
    size_t i = 0;
    char* compressed_str = NULL;
    bool the_same = false;

    for (i = 0; i < (sizeof(test_data) / sizeof(*test_data)); ++i) {
        compressed_str = compress_string(test_data[i]);
        the_same = (compressed_str == test_data[i]);
        printf("%s -> %s (%s)\n", test_data[i], compressed_str,
               the_same ? "same" : "new");
        if (!the_same) {
            free(compressed_str);
        }
    }

    return 0;
}

