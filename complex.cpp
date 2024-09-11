#include "complex.h"

Complex::Complex()
{

}

double Complex::getReal() const
{
    return real;
}

void Complex::setReal(double newReal)
{
    real = newReal;
}

double Complex::getImaginary() const
{
    return imaginary;
}

void Complex::setImaginary(double newImaginary)
{
    imaginary = newImaginary;
}

Complex Complex::operator+(const Complex &other)
{
    Complex result(this->real + other.real, this->imaginary + other.imaginary);
    return result;
}

Complex Complex::operator-(const Complex &other)
{

}

Complex Complex::operator*(const Complex &other)
{

}

Complex Complex::operator==(const Complex &other)
{

}
