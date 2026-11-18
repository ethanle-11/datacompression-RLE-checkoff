
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Compress a string using Run-Length Encoding
void rle_encode(const char *input, char *output) {
    int length = strlen(input);
    int pos = 0;

    for (int i = 0; i < length; i++) {
        int count = 1;

        // Count consecutive identical characters
        while (i + 1 < length && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store count followed by character
        pos += sprintf(output + pos, "%d%c", count, input[i]);
    }

    output[pos] = '\0';
}

// Decompress an RLE-encoded string
void rle_decode(const char *input, char *output) {
    int i = 0;
    int pos = 0;

    while (input[i] != '\0') {
        int count = 0;

        // Read repetition count
        while (isdigit((unsigned char)input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        // Read character and repeat it
        char c = input[i++];

        for (int j = 0; j < count; j++) {
            output[pos++] = c;
        }
    }

    output[pos] = '\0';
}

// Calculate compression efficiency
void compression_stats(const char *original, const char *encoded) {
    int original_size = strlen(original);
    int encoded_size = strlen(encoded);

    if (original_size == 0) {
        printf("Empty input\n");
        return;
    }

    double reduction = 100.0 *
        (original_size - encoded_size) / original_size;

    printf("Original size: %d bytes\n", original_size);
    printf("Encoded size: %d bytes\n", encoded_size);
    printf("Size reduction: %.2f%%\n", reduction);
}

// Run a complete RLE demonstration
void test_rle(const char *input) {
    char encoded[1024];
    char decoded[1024];

    rle_encode(input, encoded);
    rle_decode(encoded, decoded);

    printf("Original: %s\n", input);
    printf("Encoded:  %s\n", encoded);
    printf("Decoded:  %s\n", decoded);

    compression_stats(input, encoded);

    printf("Lossless: %s\n",
           strcmp(input, decoded) == 0 ? "Yes" : "No");

    printf("-----------------------------\n");
}

int main(void) {
    printf("Run-Length Encoding (RLE) Demo\n");
    printf("=============================\n\n");

    // Example 1: Repeated characters
    test_rle("AAAAABBBCC");

    // Example 2: Highly repetitive data
    test_rle("AAAAAAAAAA");

    // Example 3: No repeated characters
    test_rle("ABCDE");

    return 0;
}
