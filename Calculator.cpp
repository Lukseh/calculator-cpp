#include <iostream>
#include <print>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

void pauseWin() {
    #ifdef _WIN32
        pauseWin();
    #endif
}

bool isSecondNeeded(char operant) {
    if (operant == '~') {
        return false;
    }
    if (operant == '^') {
        return false;
    }
    return true;
}

int inputToInt() {
    string Input;
    getline(cin, Input);
    try {
        return stoi(Input);
    }
    catch (const invalid_argument&) {
        cerr << "Error: invalid number" << endl;
        pauseWin();
        exit(1);
    }
    catch (const out_of_range&) {
        cerr << "Error: number out of range" << endl;
        pauseWin();
        exit(1);
    }
}

int inputOperant() {
    string Input;
    getline(cin, Input);
    if (Input.size() == 1 && (Input[0] == '+' || Input[0] == '-' || Input[0] == '*' || Input[0] == '/' || Input[0] == '~' || Input[0] == '^')) {
        return Input[0];
    }
    else {
        cerr << "Error: invalid operator" << endl;
        pauseWin();
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
            pauseWin();
            exit(3);
        }
        return (float)first / (float)second;
    case '~': return sqrt(first);
    case '^': return first * first;
    default:
        cerr << "Error: unsupported operator" << endl;
        pauseWin();
        exit(4);
    }
}

int main() {
    println("Please enter first number.");
    int first = inputToInt();
    println("Please enter operation sign.");
    int operant = inputOperant();
    float result = 0;
    bool useSecond = isSecondNeeded(operant);
        if (useSecond) {
            println("Please enter second number.");
            int second = inputToInt();
            result = operationRunner(first, second, operant);
        }
        else {
            result = operationRunner(first, 0 ,operant);
        }
    println("Result of operation is: {}", result);
    pauseWin();
    return 0;
}