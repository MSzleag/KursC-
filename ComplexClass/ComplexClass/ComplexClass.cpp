#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    // Konstruktor
    Complex() : real(1), imaginary(1) {}

    // Konstruktor parametryczny
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Konstruktor kopiuj¹cy
    Complex(const Complex& other)  {
        cout << "Liczba skopiowana." << endl;
        real = other.real;
        imaginary = other.imaginary;
    }

    // Destruktor
    ~Complex() {}

    // Operator =
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }

    // Operator +
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Operator -
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Operator *
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
        );
    }

    // Operator /
    Complex operator/(const Complex& other) const {
        double divider = other.real * other.real + other.imaginary * other.imaginary;
        if (divider == 0) {
            cout << "Dzielenie przez zero, niedozwolone dzia³anie" << endl;
            return Complex(0,0);
        }
        return Complex(
            (real * other.real + imaginary * other.imaginary) / divider,
            (imaginary * other.real - real * other.imaginary) / divider
        );
    }

    // Funkcja do wypisania
    void print() const {
        cout << real << (imaginary >= 0 ? " + " : " - ") << abs(imaginary) << "i" << endl;
    }
};

int main() {
    Complex number1;
    Complex number2(3, 5);
    Complex copiedNumber(number2);

    cout << endl;
    cout << "Liczba 1 = "; number1.print();
    cout << "Liczba 2 = "; number2.print();
    cout << "Liczba kopiowana = "; copiedNumber.print();
    cout << endl;
    
    Complex sum = number1 + number2;
    cout << "Suma = "; sum.print();

    Complex subtraction = number1 - number2;
    cout << "Roznica = "; subtraction.print();

    Complex multiply = number1 * number2;
    cout << "Iloczyn = "; multiply.print();

    Complex divide = number1 / number2;
    cout << "Iloraz = "; divide.print();
    cout << endl;

    Complex equation = number1 = number2;
    cout << "Liczba 1 po równaniu = "; number1.print();

    return 0;
}