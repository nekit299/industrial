#include <iostream>
#include <cmath>
#include "triangle.h"

bool Triangle::exst_tr() {
    return ((a + b > c) && (a + c > b) && (b + c > a));
}

void Triangle::set(double a1, double b1, double c1) {
    a = a1;
    b = b1;
    c = c1;
}

void Triangle::show() {
    std::cout << "Triangle sides: " << a << " " << b << " " << c << std::endl;
}

double Triangle::perimetr() {
    return a + b + c;
}

double Triangle::square() {
    double p = perimetr() / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}