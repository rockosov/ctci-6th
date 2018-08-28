#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * Given a string, write a function to check if it is a permutation of a
 * palindrome. A palindrome is a word or phrase that is the same forwards and
 * backwards. A permutation is a rearrangement of letters.The palindrome does
 * not need to be limited to just dictionary words.
 * EXAMPLE
 * Input: Tact Coa
 * Output: True (permutations: "taco cat". "atco cta". etc.)
 */

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

int char2bit(char sym) {
    if (sym >= 'A' && sym <= 'Z') {
        return (sym - 'A');
    } else if (sym >= 'a' && sym <= 'z') {
        return (sym - 'a');
    } else {
        return -1;
    }
}

bool is_palindrome(const char* str, size_t len) {
    unsigned int lowercase_bitmap = 0;
    size_t i = 0;

    for (i = 0; i < len; ++i) {
        if (char2bit(str[i]) != -1) {
            lowercase_bitmap ^= (1 << char2bit(str[i]));
        }
    }

    return (lowercase_bitmap != 0) && (((lowercase_bitmap - 1) & lowercase_bitmap) == 0);
}

int main(int argc, char** argv) {
    const char* test_palindroms[] = {"Tact Coa", "TacttaCt Ccoooaa", "Tact Cooa"};
    int i = 0;
    size_t len = 0;

    for (i = 0; i < sizeof(test_palindroms) / sizeof(*test_palindroms); ++i) {
        len = strlen(test_palindroms[i]);
        printf("Input[%d]: %s\n", i, test_palindroms[i]);
        printf("Output[%d]: %s\n", i, is_palindrome(test_palindroms[i], len) ? "True" : "False");
    }

    return 0;
}

