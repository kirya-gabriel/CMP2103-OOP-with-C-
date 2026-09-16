(Financial: credit card number validation) Credit card numbers follow certain
patterns: It must have between 13 and 16 digits, and the number must start with:

- 4 for Visa cards
- 5 for MasterCard credit cards
- 37 for American Express cards
- 6 for Discover cards

In 1954, Hans Luhn of IBM proposed an algorithm for validating credit card numbers.
The algorithm is useful to determine whether a card number is entered correctly
or whether a credit card is scanned correctly by a scanner. Credit card
numbers are generated following this validity check, commonly known as the
Luhn check or the Mod 10 check, which can be described as follows (for illustration,
consider the card number 4388576018402626):

1. Double every second digit from right to left. If doubling of a digit results in a
   two-digit number, add up the two digits to get a single-digit number.

![Credit Card](./credit_card.png)

2. Now add all single-digit numbers from Step 1.
3. Add all digits in the odd places from right to left in the card number.
4. Sum the results from Steps 2 and 3.
5. If the result from Step 4 is divisible by 10, the card number is valid; otherwise,
it is invalid. For example, the number 4388576018402626 is invalid, but the
number 4388576018410707 is valid.

Write a program that prompts the user to enter a credit card number as an integer.
Display whether the number is valid or invalid. Design your program to use the
following functions:

//Return true if the card number is valid\
bool isValid(long long number);

//Get the result from Step 2\
int sumOfDoubleEvenPlace(long long number);

//Return this number if it is a single digit, otherwise, return the sum of the two digits\
int getDigit(int number);

//Return sum of odd place digits in number\
int sumOfOddPlace(long long number);

//Return true if the digit d is a prefix for number\
bool prefixMatched(long long number, int d);

//Return the number of digits in d\
int getSize(long long d);

//Return the first k number of digits from number. If the number of digits in number is less than k, return number.\
long long getPrefix(long long number, int k);


#include <iostream>

// Function prototypes as specified in the assignment
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    std::cout << "Enter a credit card number as an integer: ";
    std::cin >> cardNumber;

    if (isValid(cardNumber)) {
        std::cout << cardNumber << " is valid." << std::endl;
    } else {
        std::cout << cardNumber << " is invalid." << std::endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);
    
    // Check if the length is between 13 and 16 digits
    if (size < 13 || size > 16) {
        return false;
    }
    
    // Check if the prefix matches any valid card type
    if (!prefixMatched(number, 4) &&   // Visa
        !prefixMatched(number, 5) &&   // MasterCard
        !prefixMatched(number, 37) &&  // American Express
        !prefixMatched(number, 6)) {   // Discover
        return false;
    }
    
    // Perform Mod 10 check
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Get the result from Step 2 (sum of double even places from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Shift to the first even position from the right (2nd digit)
    
    while (number > 0) {
        int lastDigit = number % 10;
        sum += getDigit(lastDigit * 2);
        number /= 100; // Skip to the next even position (4th, 6th, etc.)
    }
    return sum;
}

// Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Return sum of odd place digits in number (1st, 3rd, 5th, etc. from right to left)
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 100; // Skip to the next odd position
    }
    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int dSize = getSize(d);
    long long prefix = getPrefix(number, dSize);
    return (prefix == d);
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;
    if (d == 0) return 1;
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    if (size < k) {
        return number;
    }
    
    // Drop digits from the right until k digits remain
    int dropCount = size - k;
    for (int i = 0; i < dropCount; i++) {
        number /= 10;
    }
    return number;
}
