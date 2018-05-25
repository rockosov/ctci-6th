#include <stdio.h>
#include <stdbool.h>

bool is_unique(char* str) {
    bool bitmap[256] = { false };
    int i = 0;

    if (str == NULL) {
        return false;
    }

    while(str[i] != '\0' && (i < 256)) {
        if (bitmap[str[i]] == true) {
            return false;
        }

        bitmap[str[i]] = true;
        ++i;
    }

    return (i < 256) ? true : false;
}

int main(int argc, char** argv) {
    char test_str[] = "abdcAa";

    printf("We have test string: %s\n", test_str);
    printf("It's unique: %s\n", is_unique(test_str) ? "true" : "false");
}

