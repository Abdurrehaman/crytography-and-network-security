#include <stdio.h>
#include <string.h>
#include <ctype.h>

void frequencyAnalysis(char *ciphertext, int length);

int main() {
    char ciphertext[] = "53���305))6*;4826)4�.)4�);806*;48�8�60))85;;]8*;:�8�83 (88)5�;46(;88*96*?;8)�(;485);5�2:�(;4956*2(5�4)8�8* ;4069285);)6�8)4��;1(�9;48081;8:8�1;48�85;4)485�528806*81 (�9;48;(88;4(�?34;48)4�;161;:188;�?;";

    int length = strlen(ciphertext);

    frequencyAnalysis(ciphertext, length);

    return 0;
}

void frequencyAnalysis(char *ciphertext, int length) {
    int letterFrequency[128] = {0};

    for (int i = 0; i < length; i++) {
        char currentChar = ciphertext[i];
        letterFrequency[currentChar]++;
    }

    printf("Character Frequency:\n");
    for (int i = 0; i < 128; i++) {
        if (letterFrequency[i] > 0) {
            printf("%c: %d\n", i, letterFrequency[i]);
        }
    }
}
