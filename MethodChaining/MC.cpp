#include <iostream>

using namespace std;

class Calculator {
private:

    double result;

public:

    Calculator() : result(0) {}

    Calculator& add(double number) {
        result += number;
        return *this;
    }

    Calculator& subtract(double number) {
        result -= number;
        return *this;
    }

    Calculator& multiply(double number) {
        result *= number;
        return *this;
    }

    Calculator& divide(double number) {
        if (number != 0) {
            result /= number;
        } else {
            cout << "Error: Division by zero!" << endl;
        }
        return *this;
    }

    double getResult() const {
        return result;
    }
};

int main() {
    Calculator calc;
    double finalResult = calc.add(5).multiply(2).subtract(3).divide(2).getResult();

    cout << "Final Result: " << finalResult << endl;

    return 0;
}