#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string& str);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}

double extractNumeric(const string& str) {
    // Check if the string length is greater than 20
    if (str.length() > 20) {
        return -999999.99; // Invalid input
    }

    // Initialize all values
    bool hasDecimal = false;
    double result = 0.0;
    double decimalPlace = 0.1;
    bool isDecimal = false;
    bool isNegative = false;

    // Loop through the string for its length
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];

        // Check if there is a '+' or a '-' at the start of the string
        if ((c == '+' || c == '-') && i == 0) {
            if (c == '-') {
                isNegative = true; // If negative, return result as negative
            }
        } else if (c >= '0' && c <= '9') { // Check if the character is a digit
            if (isDecimal) {
                result += (c - '0') * decimalPlace; // Add the digit to the decimal part
                decimalPlace /= 10; // Move decimal place up
            } else {
                result = result * 10 + (c - '0'); // Add the digit to the integer part
            }
        }
        // Checks for a decimal '.' and makes sure there is only one
        else if (c == '.' && !hasDecimal) {
            hasDecimal = true;
            isDecimal = true;
        }
        // If something is wrong
        else {
            return -999999.99;
        }
    }
    // Convert to negative if needed
    if (isNegative) {
        result = -result;
    }

    return result; // Return the numeric result
}
