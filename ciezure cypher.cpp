#include <stdio.h>
#include <ctype.h>

void encrypt(char *message, int shift);
void decrypt(char *message, int shift);

int main() {
    char message[100];
    int choice, shift;

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    printf("Enter a message: ");
    getchar(); 
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Exiting...\n");
        return 1;
    }

    if (choice == 1) {
        printf("\nEncrypted message: ");
        encrypt(message, shift);
    } else {
        printf("\nDecrypted message: ");
        decrypt(message, shift);
    }

    return 0;
}

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            
            ch = (ch - base + shift) % 26 + base;
        }

        printf("%c", ch);
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            
            ch = (ch - base - shift + 26) % 26 + base;
        }

        printf("%c", ch);
    }
}
