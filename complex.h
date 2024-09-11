#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
private:
    double real;
    double imaginary;
public:
    Complex();
    Complex(double real, double imaginary): real(real), imaginary(imaginary){}
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator==(const Complex& other) const;
    double getReal() const;
    void setReal(double newReal);
    double getImaginary() const;
    void setImaginary(double newImaginary);
};

#endif // COMPLEX_H
