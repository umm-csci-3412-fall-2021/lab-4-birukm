#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
    char* vowels = "aeiouAEIOU";
    for (int i = 0; i < 10; ++i) {
        char current = vowels[i];
        if(c == current) return true;
    }
    return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
    int num = 0;
    for (int i= 0; i < num_chars; ++i) {
        char current = in_buf[i];
        if(!is_vowel(current)){
            out_buf[num] = current;
            num++;
        }
    }
    return num;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    int numOfBytes = 1;
    int nonvowels;

    char* input = calloc(BUF_SIZE, sizeof(char));
    char* output = calloc(BUF_SIZE, sizeof(char));

    while (numOfBytes != 0) {
        numOfBytes = fread(input, sizeof(char), BUF_SIZE, inputFile);
        nonvowels = copy_non_vowels(numOfBytes, input, output);
        fwrite(output, sizeof(char), nonvowels, outputFile);
    }

    free(input);
    free(output);
}

int main(int argc, char *argv[]) {
    // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;

    if (argc == 3){ // file input and output are provided as args
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    } else if (argc == 2){ // only file input is provided as arg
        inputFile = fopen(argv[1], "r");
    }

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0;
}