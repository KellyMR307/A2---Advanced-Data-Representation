#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>


void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int32_t n, char *out);
void to_ones_complement (int32_t n, char *out);
void to_twos_complement(int32_t n, char *out);

int main(){
     FILE *file = fopen("a2_test.txt", "r");
    if (file == NULL) {
    printf("Error: Could not open file\n");
    return 1;
    }
 
    char line[256];
    int testNum = 1;
    int passedTests = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
    // Process each line
    line[strcspn(line, "\n")] = '\0';
    if (line[0] == '#' || strlen(line) == 0){
        continue;
    }
    char function[50];
    char input[100];
    char expected [100];
    printf("Read Line: %s\n", line);
    if (sscanf(line, "%s %s %s", function, input, expected) != 3){
        printf("Incorrect format for test case");
    }
    
    char output[100] = "";

    if (strcmp(function, "oct_to_bin") == 0){
        oct_to_bin(input, output);
    }
    else if(strcmp(function, "oct_to_hex") == 0){
        oct_to_hex (input, output);
    }
    else if (strcmp(function, "hex_to_bin") == 0){
        hex_to_bin(input, output);
    }
    else if (strcmp(function, "to_sign_magnitude") == 0){
        int n = atoi(input);
        to_sign_magnitude(n, output);
    }
    else if (strcmp(function, "to_ones_complement") == 0){
        int n = atoi(input);
        to_ones_complement (n, output);
    }
    else if (strcmp(function, "to_twos_complement") == 0){
        int n = atoi(input);
        to_twos_complement(n, output);
    }
    else{
        printf("Unable to get function: %s\n", function);
        continue;
    }

    if(strcmp(expected, output) == 0){
        printf("Test %d: %s(\"%s\") -> Expected: \"%s\", Got: \"%s\" [PASS]\n", testNum, function,input, expected, output);
        passedTests++;
    }
    else{
        printf("Test %d: %s(\"%s\") -> Expected: \"%s\", Got: \"%s\" [FAIL]\n", testNum, function,input, expected, output);
    }

    testNum++;

    }
    fclose(file);

    printf("Summary: %d/%d tests passed\n", passedTests, testNum);

    return 0;
}