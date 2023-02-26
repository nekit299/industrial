#include <iostream>
#include "triangle.h"

int main() {
    Triangle triangles[3];
    for (int i = 0; i < 3; i++) {
        double a, b, c;
        std::cout << "Enter sides of triangle " << i + 1 << ": ";
        std::cin >> a >> b >> c;
        while (!triangles[i].exst_tr()) {
            triangles[i].set(a, b, c);
            if (!triangles[i].exst_tr()) {
                std::cout << "Invalid triangle, enter sides again: ";
                std::cin >> a >> b >> c;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        std::cout << "Triangle " << i + 1 << std::endl;
        triangles[i].show();
        std::cout << "Perimeter: " << triangles[i].perimetr() << std::endl;
        std::cout << "Square: " << triangles[i].square() << std::endl;
    }

    return 0;
}