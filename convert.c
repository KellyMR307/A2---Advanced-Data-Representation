#include <stdint.h> // for unit32_t
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//convert to any base using division/remainder algorithm
void oct_to_bin (const char *oct, char *out){
    //conver octal to binary 

    //first convert octal to bin 
    //Octal only uses digits 0-7 (8 digits in total)
    //go through each digit and convert it to binary using a while loop 
    while (*oct !=  '\0'){ 
        //use a switch case of the numbers 0-7 to convert it into binary 
        switch (*oct){
            //if number is _ then add the 3 binary digits to the output
            case '0': 
                strcat(out, "000");
                break;
            case '1': 
                strcat(out, "001");
                break;
            case '2': 
                strcat(out, "010");
                break;
            case '3': 
                strcat(out, "011");
                break;
            case '4': 
                strcat(out, "100");
                break;
            case '5': 
                strcat(out, "101");
                break;
            case '6':
                strcat(out, "110");
                break;
            case '7': 
                strcat(out, "111");
                break;
            default:
                strcat(out, "Invalid");
                break;
        } //switch 
        //move to the next char
        oct++;
    }//while 
} //oct_to_bin function

void oct_to_hex (const char *oct, char *out){
    //use the oct_to_bin function to first convert oct to binary
    //store this into a variable
    char bin[100] = "";
    oct_to_bin(oct, bin);

    int lengthOfBin = strlen(bin);

    //first check to see if the binary is divisible by 4 if it insn't you will need to add 0's in front of it
    //calculate the amount of zero's needed to add in front 
    int amountToAdd = 0;
    if (lengthOfBin %4 != 0){
        amountToAdd = 4 - (lengthOfBin % 4);
    }

    //create a var to store the zero's that will then be concatenated with the binary digits 
    char new_bin[100] = "";
    for (int i = 0; i<amountToAdd; i++){
        strcat(new_bin, "0");
    }
    //add the binary digits to the 0's in new_bin
    strcat(new_bin, bin); 

    //get the length of the new binary 
    int newBinLength = strlen(new_bin);

    //then using 4 of the binary digits each time convert it to hexadecimal -- use a for loop
    //increments of 4 to group the binary into 4 digits

    for (int i = 0; i < newBinLength; i+=4){
        //store the 4 digits into a char[]
        char group [5];
        //add the 4 digits to the group 
        for (int j = 0; j < 4; j++){
            //i = 0 j = 0 then new_bin digit at index at 0 stores it in group[0]
            //i = 0 j = 1 then new_bin  gets digit at index 1 store it in group [1]
            //i = 0 j = 2 then new_bin  gets digit at index 2 stores it in group [2]
            //i = 0; j = 3 then new_bin gets digit at index 3 stores it in group [3]
            //finished with one iteration of the outer loop 
            //i = 4; j = 0 then new_bin gets digit at index 4 store it in group 
            group[j] = new_bin[i+j];
        }
        //add "\0" to know where it ends
        group[4] = '\0';

        //for each group convert it to an int first 
        //0001 = 1  0010 = 2 0100 = 4 1000 - 8 
        int integerValue = 0;

        if (group[0] == '1'){
            integerValue += 8;
        }
        if(group[1] == '1'){
            integerValue += 4;
        }
        if(group[2] == '1'){
            integerValue += 2;
        }
        if(group[3] == '1'){
            integerValue += 1;
        }

        //convert int to hex for the current group and add that to the output 
        // A - 10 B - 11 C - 12 D - 13 E - 14 F - 15
        char HexDigit[2];

        //if int is less then 10 keep it like that but if it's greater than convert it to a char
        if (integerValue < 10){
            HexDigit[0] = '0' + integerValue;
        }
        else{
            HexDigit[0] = 'A' + (integerValue - 10);
        }
        HexDigit[1] = '\0';
        strcat(out, HexDigit);


    }//for loop 

}//oct_to_hex function

void hex_to_bin(const char *hex, char *out){
    while (*hex != '\0'){
        //convert hex to lowercase so that it handles both uppercase and lowercase 
        char lowerCaseHex = tolower(*hex);

        switch (lowerCaseHex){
            case '0': 
                strcat(out, "0000");
                break;
            case '1': 
                strcat(out, "0001");
                break;
            case '2': 
                strcat(out, "0010");
                break;
            case '3': 
                strcat(out, "0011");
                break;
            case '4': 
                strcat(out, "0100");
                break;
            case '5': 
                strcat(out, "0101");
                break;
            case '6': 
                strcat(out, "0110");
                break;
            case '7': 
                strcat(out, "0111");
                break;
            case '8': 
                strcat(out, "1000");
                break;
            case '9': 
                strcat(out, "1001");
                break;
            case 'a': 
                strcat(out, "1010");
                break;
            case 'b': 
                strcat(out, "1011");
                break;
            case 'c': 
                strcat(out, "1100");
                break;
            case 'd': 
                strcat(out, "1101");
                break;
            case 'e': 
                strcat(out, "1110");
                break;
            case 'f': 
                strcat(out, "1111");
                break;
            default:
                strcat(out, "invalid hex digit");
                break;
        }//switch
        hex++;
    }//while loop
}

void to_sign_magnitude (int n, char *out){
    uint32_t result;
    // For positive: output as-is with leading zeros
    // For negative: set bit 31 to 1, keep magnitude in bits 0-30
    if (n >= 0) {
     // Regular binary with 32 bits
      result = (uint32_t) n;
    } 
    else {
     // Set sign bit + magnitude of absolute value
     //get the positive magnitude of n and store it 
     uint32_t magnitude = (uint32_t)(-n);
     //get the unsigned int 1 and shift the bit 1 to the left by 31 places to set bit 31 to 1 
     //10000000000000000000000000000000
     uint32_t signBit = 1U << 31;
     //store the positive value of n in bits 0-30
     uint32_t magnitudeBits = magnitude;
     result = signBit + magnitudeBits;
     
    }

    for (int i = 31; i >= 0; i--){
        //place 1 at position 31 (highest bit) and the rest 0
        uint32_t bitValue = 1U << i;
        if (bitValue & result){
            out[31-i] = '1';
        }
        else{
            out[31-i] = '0';
        }
    }
    out[32] = '\0';
} //to_sign_magnitude

void to_ones_complement (int n, char *out){
    // For positive: output as-is with leading zeros
    // For negative: flip ALL bits
    uint32_t result = 0;

     if (n >= 0) {
     // Regular binary with 32 bits
        result = (uint32_t) n;
     } 

     else {
     // Get positive representation, then flip every bit
        uint32_t magnitude = (uint32_t) (-n);
        uint32_t flip = 0;

        //flip 1s to 0 and 0s to 1s
        for (int i = 0; i < 32; i++){
            int bit = (magnitude >> i) & 1;
            int flipOfBit = 0;

            if (bit == 0){
                flipOfBit = 1;
            }
            else{
                flipOfBit = 0;
            }

            if (flipOfBit == 1){
                flip = flip + (1 << i);
            }
        }//for loop

        result = flip;
     }//else

     for (int i  = 31; i >= 0; i--){
        int bit = (result >> i) & 1;
        if (bit == 1){
            out [31-i] = '1';
        }
        else{
            out[31 - i] = '0';
        }
     }

     out[32] = '\0';

} //to_ones_complement 


void to_twos_complement (int n, char *out){

    uint32_t result = 0;
    if (n >= 0) {
         result = (uint32_t) n;
    }

    else{
        //call one's complement function first then add 1 to it
        //store the one's complement to a temporary char[]
        char temp [100];
        to_ones_complement (n, temp);

        for (int i = 0; i < 32; i++){
            if (temp[i] == '1'){
                result = result + (1U << (31-i));
            }
        }
        result = result + 1;
    }

    for (int i  = 31; i >= 0; i--){
        int bit = (result >> i) & 1;
    if (bit == 1){
        out [31-i] = '1';
    }
    else{
        out[31 - i] = '0';
    }

    }

     out[32] = '\0';
}

//int main(){
  //  const char *octalInput = "1234";
    //const char *hexInput = "CAFE";
   // char binaryConversion[100] = "";  
//    char hexaConversion [100] = "";
//    char hexToBin [100] = "";

  //  oct_to_bin(octalInput, binaryConversion);
   // oct_to_hex(octalInput, hexaConversion);
   // hex_to_bin(hexInput,  hexToBin);

    //printf("Octal: %s\n", octalInput);
    //printf("Binary: %s\n", binaryConversion);
   // printf("Hexadecimal: %s\n", hexaConversion);
   // printf("Hexadecimal: %s\n", hexInput);
   // printf("Binary: %s\n", hexToBin);
    
    //char result[33];
    
    //to_twos_complement(-5, result);
    //printf("Two's complement of -5:  %s\n", result);

    //to_twos_complement(5, result);
    //printf("Two's complement of 5:   %s\n", result);

    //return 0;
//} 

