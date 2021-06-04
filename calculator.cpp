// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May June 4, 2021
// This program gets the operator, and two numbers, then uses them to
// calculate the sum, or product, or whatever of those 2 numbers

#include <iostream>
#include <cmath>

// greet the user
void Greet() {
    std::cout << "This program gets an operator and two numbers" <<
    " then calculates an answer using that input";
}

// does the calculation depending on the oerator and the numbers inputed
double Calculate(char oper, float num1Func, float num2Func) {
    float result;
    if (oper == '+') {
        result = num1Func + num2Func;
    } else if (oper == '-') {
        result = num1Func - num2Func;
    } else if (oper == '*') {
        result = num1Func * num2Func;
    } else if (oper == '/') {
        result = num1Func / num2Func;
    } else if (oper == '%') {
        result = fmod(num1Func, num2Func);
    } else {
        result = 0;
        std::cout << "Invalid operator";
    }
    // return the result back to main()
    return result;
}

int main() {
    Greet();
    // define answer and get sign from user
    float answer;
    char sign;
    std::cout << "What is your operator (+, -, *, /, %): ";
    std::cin >> sign;

    // make string versions of the num_vars for error checking
    std::string num1Str;
    std::string num2Str;

    // get the num vars
    float num1;
    std::cout << "What is your first number: ";
    std::cin >> num1Str;

    float num2;
    std::cout << "What is your second number: ";
    std::cin >> num2Str;

    try {
        // turn the nums into floats
        num1 = std::stof(num1Str);
        num2 = std::stof(num2Str);

        // call the function with the parameters then pring the result
        answer = Calculate(sign, num1, num2);
        
        if(answer != 0) {
        std::cout << "Your answer is " << answer << "\n";
        }
    // catch the invalid cases
    } catch (std::invalid_argument) {
        std::cout << "This is not a valid number";
    }
}
