#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * Assume you have a method isSubstring which checks if one word is a substring
 * of another. Given two strings, s1 and s2, write code to check if s2 is a
 * rotation of s1 using only one call to isSubstring (e.g., "waterbottle"
 * is a rotation of"erbottlewat").
 */

/**
 * Time Complexity: depending on strstr complexity
 * Space Complexity: O(n) + depending on strstr complexity
 */

bool is_rotation(const char* s1, const char* s2) {
    bool answer = false;
    char* s1s1 = NULL;
    size_t s1_size = strlen(s1);
    size_t s2_size = strlen(s2);

    if (s1_size != s2_size) {
        return false;
    }

    s1s1 = malloc(2*s1_size + 1);
    memset(s1s1, 0, 2*s1_size + 1);

    memcpy(s1s1, s1, s1_size);
    memcpy(s1s1 + s1_size, s1, s1_size);

    answer = (strstr(s1s1, s2) != NULL);

    return answer;
}

int main(int argc, char** argv) {
    const char* s1 = "waterbottle";
    const char* s2 = "erbottlewat";
    const char* s3 = "erbottlewate";
    const char* s4 = "erbottlewae";

    printf("s1 = %s, s2 = %s, is_rotation = %s\n",
           s1, s2, is_rotation(s1, s2) ? "TRUE" : "FALSE");
    printf("s1 = %s, s3 = %s, is_rotation = %s\n",
           s1, s3, is_rotation(s1, s3) ? "TRUE" : "FALSE");
    printf("s1 = %s, s4 = %s, is_rotation = %s\n",
           s1, s4, is_rotation(s1, s4) ? "TRUE" : "FALSE");

    return 0;
}

