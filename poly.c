#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    char pt[MAX_LEN] = {'\0'}, ct[MAX_LEN] = {'\0'}, key[MAX_LEN] = {'\0'}, rt[MAX_LEN] = {'\0'};
    int i, j;

    printf("\nEnter the plain text: ");
    fgets(pt, MAX_LEN, stdin);
    printf("Enter the key: ");
    fgets(key, MAX_LEN, stdin);

    // Remove newline characters from inputs
    pt[strcspn(pt, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Ensure key is not empty
    if (strlen(key) == 0) {
        printf("Key cannot be empty.\n");
        return 1;
    }

    // Convert to lowercase for uniform processing
    toLowerCase(pt);
    toLowerCase(key);

    // Generate new key of the same length as plaintext
    int pt_len = strlen(pt);
    int key_len = strlen(key);
    for (i = key_len; i < pt_len; i++) {
        key[i] = key[i % key_len];
    }
    key[pt_len] = '\0';

    printf("\nNew key is: %s\n", key);

    // Encrypt plaintext
    for (i = 0; i < pt_len; i++) {
        if (pt[i] >= 'a' && pt[i] <= 'z') {
            ct[i] = (((pt[i] - 'a') + (key[i] - 'a')) % 26) + 'a';
        } else {
            ct[i] = pt[i]; // Non-alphabetic characters remain unchanged
        }
    }
    ct[pt_len] = '\0';

    printf("\nCipher text is: %s\n", ct);

    // Decrypt ciphertext
    for (i = 0; i < pt_len; i++) {
        if (ct[i] >= 'a' && ct[i] <= 'z') {
            rt[i] = (((ct[i] - 'a') - (key[i] - 'a') + 26) % 26) + 'a';
        } else {
            rt[i] = ct[i]; // Non-alphabetic characters remain unchanged
        }
    }
    rt[pt_len] = '\0';

    printf("\nPlain text is: %s\n", rt);

    return 0;
}
