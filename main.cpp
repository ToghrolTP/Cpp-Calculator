#include <iostream>
#include <sstream>
#include <ostream>
using namespace std;


bool tryParseInt(const std::string& str, int& result);
bool tryParseDouble(const std::string& str, double& result);
string getNumber(string prompt);
double doubleValidation(string prompt);
void calculator(char option, double number1, double number2);
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double division(double num1, double num2);

int main() {
    double number1;
    double number2;
    char option;

    number1 = doubleValidation("Enter number1: ");
    number2 = doubleValidation("Enter number2: ");

    calculator(option, number1, number2);

    return 0;
}

bool tryParseInt(const std::string& str, int& result) {
    stringstream ss(str);
    ss >> result;

    return !ss.fail() && ss.eof();
}
bool tryParseDouble(const std::string& str, double& result) {
    stringstream ss(str);
    ss >> result;

    return !ss.fail() && ss.eof();
}

void calculator(char option, double number1, double number2) {
    bool isInLoop = true;

    cout << "Enter your choice:\n" <<
            "(+) - Add" << "\n" <<
            "(-) - Subtract" << "\n" <<
            "(*) - Multiply" << "\n" <<
            "(/) - Division" << "\n" <<
            "(q) - quite " << "\n";

    while (isInLoop) {
        cout << "> ";
        cin >> option;
        switch(option) {
            case '+':
                cout << "Result: ";
                cout << add(number1, number2) << "\n";
                break;
            case '-':
                cout << "Result: ";
                cout << subtract(number1, number2) << "\n";
                break;
            case '*':
                cout << "Result: ";
                cout << multiply(number1, number2) << "\n";
                break;
            case '/':
                cout << "Result: ";
                cout << division(number1, number2) << "\n";
                break;
            case 'q':
                isInLoop = false;
                cout << "Thanks, bye!\n";
                break;
            default:
                cout << "Invalid option!\n";
                break;
        }
    }
}

string getNumber(string prompt) {
    string input;
    cout << prompt;
    cin >> input;
    return input;
}

double doubleValidation(string prompt) {
    double number;
    while (true) {
        if (!(tryParseDouble(getNumber(prompt), number))) {
            cout << "Invalid input!" << endl;
        } else {
            break;
        }
    }

    return number;
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double division(double num1, double num2) {
    if (num2 ==  0) {
        cout << "Error! Devided by Zero!";
        return 0;
    }

    return num1 / num2;
}
