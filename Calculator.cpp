#include <iostream>
#include <print>
#include <string>
#include <cstdlib>

using namespace std;

int inputToInt() {
    string Input;
    getline(cin, Input);
    try {
        return stoi(Input);
    }
    catch (const invalid_argument&) {
        cerr << "Error: invalid number" << endl;
        system("pause");
        exit(1);
    }
    catch (const out_of_range&) {
        cerr << "Error: number out of range" << endl;
        system("pause");
        exit(1);
    }
}

int inputOperant() {
    string Input;
    getline(cin, Input);
    if (Input.size() == 1 && (Input[0] == '+' || Input[0] == '-' || Input[0] == '*' || Input[0] == '/')) {
        return Input[0];
    }
    else {
        cerr << "Error: invalid operator" << endl;
        system("pause");
        exit(2);
    }
}

float operationRunner(int first, int second, int operant) {
    switch (operant) {
    case '+': return first + second;
    case '-': return first - second;
    case '*': return first * second;
    case '/':
        if (second == 0) {
            cerr << "Error: cannot divide by zero" << endl;
            system("pause");
            exit(3);
        }
        return (float)first / (float)second;
    default:
        cerr << "Error: unsupported operator" << endl;
        system("pause");
        exit(4);
    }
}

int main() {
    println("Please enter first number.");
    int first = inputToInt();
    println("Please enter second number.");
    int second = inputToInt();
    println("Please enter operation sign.");
    int operant = inputOperant();
    float result = operationRunner(first, second, operant);
    println("Result of operation is: {}", result);
    system("pause");
    return 0;
}
