#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 * EXAMPLE
 * pale, ple -> true
 * pales, pale -> true
 * pale, bale -> true
 * pale, bake -> false
 */

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

bool one_edit_check(const char* s1, const char* s2) {
    const char* shorter = NULL;
    const char* longer = NULL;
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);
    size_t shorter_index = 0;
    size_t longer_index = 0;
    size_t shorter_len = 0;
    size_t longer_len = 0;
    bool found_diff = false;

    if (abs(s1_len - s2_len) > 1) {
        return false;
    }

    if (s1_len > s2_len) {
        longer = s1;
        longer_len = s1_len;
        shorter = s2;
        shorter_len = s2_len;
    } else {
        longer = s2;
        longer_len = s2_len;
        shorter = s1;
        shorter_len = s1_len;
    }

    while ((shorter_index < shorter_len) && (longer_index < longer_len)) {
        if (shorter[shorter_index] != longer[longer_index]) {
            if (found_diff) {
                return false; /* Looks like we have two replaces */
            }

            found_diff = true;

            if (shorter_len == longer_len) {
                /* This is replace case, move shorter index as well */
                shorter_index++;
            }
        } else {
            shorter_index++;
        }
        longer_index++;
    }

    return true;
}

int main(int argc, char** argv) {
    const char* test_data[] = {
        "pale", "ple",
        "pales", "pale",
        "pale", "bale",
        "pale", "bake",
        "pale", "pl",
        "pale", "palele"
    };
    size_t i = 0;

    while (i != (sizeof(test_data) / sizeof(*test_data))) {
        printf("%s, %s -> %s\n", test_data[i], test_data[i+1],
               one_edit_check(test_data[i], test_data[i+1]) ? "true" : "false");
        i += 2;
    }

    return 0;
}


