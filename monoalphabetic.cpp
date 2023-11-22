#include <stdio.h>
#include <ctype.h>

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main() {
    char message[100];
    char key[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; 

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = toupper(message[i]);
    }

    printf("\nOriginal Message: %s\n", message);

    printf("\nEncrypted Message: ");
    encrypt(message, key);

    printf("\nDecrypted Message: ");
    decrypt(message, key);

    return 0;
}

void encrypt(char *message, char *key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            
            ch = key[ch - 'A'];
        }

        printf("%c", ch);
    }
}

void decrypt(char *message, char *key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            
            for (int j = 0; j < 26; j++) {
                if (key[j] == ch) {
                    ch = 'A' + j;
                    break;
                }
            }
        }

        printf("%c", ch);
    }
}
