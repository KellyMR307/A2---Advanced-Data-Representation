# A2---Advanced-Data-Representation
#Author
Kelly Martinez-Ramirez

#Description
Advanced data representation functions for Owl Tech's CPU design teambinary, 
The point of this assignment was to create mappings for binary, octal, hexadecimal and signed number representations

#What's new
Direct mapping functions used to convert between octal, hexa and binary 
Signed number representations involved handling positive and negative ints
Reused test framework from A1 - Previously in Assignment 1 I was not able to complete the test framework so this time I decided to get a good understanding on how to read a file and how to parse in C

#Build Instructions
in order to use the functions is the file convert.c I had to use the following command prompt 
" gcc -o convert convert.c main.c 
./convert"

In order to build the functions oct_to_bin, oct_to_hex, hex_to_bin I used the knowledge and my notes from the textbook readings 
oct_to_bin - in this following function i decided for each digit in the oct I would use a switch case to convert the 1 digit of oct into 3 binary digits based on what I learned from the textbook I know an oct uses numbers 0-7 only I then concatenated the conversions to the output 

Before moving to the next function or finishing this function I made sure to test it and check whether it matched the test cases from the file provided 

oct_to_hex - in this function I first needed to convert oct to binary first so I called the function oct_to_bin from there I needed to see whether the total binary digits were divisible by for if it wasn't then I went to add the amount of 0's needed to make the binary number divisible by for at the front (so that it wouldn't change the value of the binary). I then grouped 4 digits together and converted the 4 digits to an int Once that was completed I needed to convert it to hexadecimal by using a if statement to check if the int was greater or less than 10 because in hexadecimal 10-15 is represented by A-F

hex_to_bin - for this function i decided it would be easier to use a switch case for 0-9 and a-f but in order to deal with lowercase and upperccase letters i would need to convert the hex to all lowercase then from there convert it to binary 

to_sign_magnitude - for this function I followed the comments/outline provided by instructions for Assignment 2 also for this function I also relied on the information in the class textbook. For this function you really need a good undestanding of sign magnitude otherwise it will be hard to build this function. first you need to check if the number is positive or negative. if it is positive you leave it like that but if it is negative you will need to get the magnitude (pos), then get the unsigned int and shift it to the left 31 places to get that sign for negative then store the positive value of the int (magnitude) in bits 0-30

to_ones_complement - if the number is positive you would leave it as it is but if it is negative you would convert all 1s to 0s and all the 0s to 1s

to_twos_complement - I used the to_ones_complement and then added 1 to the number to get twos complement for these 2 functions it had a similar process and it also requires knowledge on it to build this function

for main.c - I used  https://post.bytes.com/forum/topic/c/585817-how-to-parse-a-file-in-c to help with the parsing and storing the functionName, input, expected because on assigment 1 I did not successfully complete the file reading and parsing and I was really confused but after watching videoes and looking at references I was able to figure it out. This was pretty simple as the hardest part was parsing

#Test results 
this time I was successfully able to run the testfile on my functions but I would say this took me a long time to get to work because I kept getting many errors and needed to update my code
Most of the tests were successful I was able to get 49/52 test to succesfully pass but 3 of them failed. I also was able to store it in output.txt file this time too which shows the full result and tests ran


