#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN 100

void encrypt(char *plaintext, int key[][MAX_LEN], int size);
void decrypt(char *ciphertext, int key[][MAX_LEN], int size);

int main() {
    char input[MAX_LEN];
    int size;
    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LEN, stdin);
    printf("Enter the size of the key matrix: ");
    scanf("%d", &size);
    int key[size][MAX_LEN];
    printf("Enter the key matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &key[i][j]);
        }
    }
    encrypt(input, key, size);
    printf("Encrypted string: %s\n", input);
    decrypt(input, key, size);
    printf("Decrypted string: %s\n", input);
    return 0;
}

void encrypt(char *plaintext, int key[][MAX_LEN], int size) {
    int len = strlen(plaintext);
    char ciphertext[MAX_LEN];
    int padding = size - (len % size);
    for (int i = 0; i < padding; i++) {
        plaintext[len+i] = ' ';
    }
    plaintext[len+padding] = '\0';
    for (int i = 0; i < len+padding; i += size) {
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++) {
                sum += key[j][k] * (plaintext[i+k] - 'A');
            }
            ciphertext[i+j] = (sum % 26) + 'A';
        }
    }
    strcpy(plaintext, ciphertext);
}

void decrypt(char *ciphertext, int key[][MAX_LEN], int size) {
    int len = strlen(ciphertext);
    char plaintext[MAX_LEN];
    for (int i = 0; i < len; i += size) {
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++) {
                sum += key[k][j] * (ciphertext[i+k] - 'A');
            }
            plaintext[i+j] = (sum % 26) + 'A';
        }
    }
    int padding = 0;
    for (int i = len-1; i >= 0; i--) {
        if (plaintext[i] == ' ') {
            padding++;
        } else {
            break;
        }
    }
    plaintext[len-padding] = '\0';
    strcpy(ciphertext, plaintext);
}