#include <iostream>
#include <cmath>

int bin2dec(bool binary_string[]);

int bin2dec(bool binary_string[]) {
    int decimal{};
    bool negative{}, one{};
    //Checks if the binary is negative
    if (binary_string[0] == 1) {
        negative = true;
        //Converts the binary from 2's complement to standard binary representation
        for (int i = 15; i >= 0; --i) {
            if (one) {
                if (binary_string[i]) {
                    binary_string[i] = 0;
                } else {
                    binary_string[i] = 1;
                }
            }
            if (binary_string[i]) {
                one = true;
            }
        }
    }
    //Calculates the value of the binary in decimal
    for (int i = 15; i > 0; --i) {
        decimal += binary_string[i] * pow(2, 15 - i);
    }
    //Makes the decimal negative if the binary is negative
    if (negative) {
        decimal *= -1;
    }
    return decimal;
}

int main() {
    bool binary[16] = {0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0};
    std::cout << bin2dec(binary);
    return 0;
}