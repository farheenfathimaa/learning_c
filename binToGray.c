/*Converting binary numbers to gray numbers and vice versa*/
#include <stdio.h>

void binaryToGray(int in[], int out[]) {
    int i;
    out[0] = in[0];
    for (i = 1; i < 4; i++) {
        out[i] = in[i] ^ in[i - 1];
    }
}

void grayToBinary(int in[], int out[]) {
    int i;
    out[0] = in[0];
    for (i = 1; i < 4; i++) {
        out[i] = out[i - 1] ^ in[i];
    }
}

int main() {
    int i, in[10], out[10], n, j;
    
    printf("Enter the number: ");
    for (i = 0; i < 4; i++) {
        scanf("%d", &in[i]);
    }

    printf("Options: enter '1' to convert binary number to gray or enter '2' to convert gray to binary\n");
    scanf("%d", &n);

    if (n == 1) {
        binaryToGray(in, out);
    } else if (n == 2) {
        grayToBinary(in, out);
    }

    printf("Converted number: ");
    for (j = 0; j < 4; j++) {
        printf(" %d", out[j]);
    }

    return 0;
}