#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <fstream>


class Utils
{
public:
    Utils();

    void readFiles(std::string file1);
    double celsiusToFahrenheit(double celsius);
};

#endif // UTILS_H
