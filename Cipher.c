#include <stdio.h>
#include <ctype.h>

char encrypt(char plaintext[], int KEY);
char decrypt(char ciphertext[], int KEY);

int main() {

    char inputText[800];
    int  KEY;

        printf("Input Plain Text: ");
        fgets(inputText, sizeof(inputText), stdin);

        printf("Enter your Private Key value: ");
        scanf("%d", & KEY);

            encrypt(inputText,  KEY);
            printf("Encrypted: %s", inputText);

            decrypt(inputText,  KEY);
            printf("Decrypted: %s", inputText);

    return 0;
}

char encrypt(char plaintext[], int  KEY) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char currentChar = plaintext[i];

        if (isalpha(currentChar)) {
            char base = isupper(currentChar) ? 'A' : 'a';
            char encryptedChar = (char)((currentChar - base +  KEY) % 26 + base);
            if (encryptedChar < base) {
                encryptedChar += 26;
            }
            plaintext[i] = encryptedChar;
        }
    }
}

char decrypt(char ciphertext[], int  KEY) {
    return encrypt(ciphertext, 26 - ( KEY % 26));
}
