#include "circle.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Создаем три объекта окружности, задавая их параметры с клавиатуры
    float r1, x1, y1;
    cout << "Введите параметры первой окружности (радиус, координаты центра): ";
    cin >> r1 >> x1 >> y1;
    Circle okr1(r1, x1, y1);

    float r2, x2, y2;
    cout << "Введите параметры второй окружности (радиус, координаты центра): ";
    cin >> r2 >> x2 >> y2;
    Circle okr2(r2, x2, y2);

    float r3, x3, y3;
    cout << "Введите параметры третьей окружности (радиус, координаты центра): ";
    cin >> r3 >> x3 >> y3;
    Circle okr3(r3, x3, y3);

    // Выводим параметры каждой окружности и ее площадь
    cout << "\nОкружность №1:" << endl;
    cout << "Радиус: " << r1 << endl;
    cout << "Координаты центра: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Площадь: " << okr1.square() << endl;

    cout << "\nОкружность №2:" << endl;
    cout << "Радиус: " << r2 << endl;
    cout << "Координаты центра: (" << x2 << ", " << y2 << ")" << endl;
    cout << "Площадь: " << okr2.square() << endl;

    cout << "\nОкружность №3:" << endl;
    cout << "Радиус: " << r3 << endl;
    cout << "Координаты центра: (" << x3 << ", " << y3 << ")" << endl;
    cout << "Площадь: " << okr3.square() << endl;

    //Проверка пересечения окружностей
    cout << "\nПересекаются ли окружности 1 и 3? " << boolalpha << okr1.check_circle(r3, x3, y3) << endl;
    cout << "Пересекаются ли окружности 1 и 2? " << boolalpha << okr1.check_circle(r2, x2, y2) << endl;
    cout << "Пересекаются ли окружности 2 и 3? " << boolalpha << okr2.check_circle(r3, x3, y3) << endl;

    //Вводим стороны треугольника для проверки описанной окружности
    float a, b, c;
    cout << "\nВведите стороны треугольника для проверки, можно ли вокруг него описать каждую окружность:" << endl;
    cout << "Сторона a: ";
    cin >> a;
    cout << "Сторона b: ";
    cin >> b;
    cout << "Сторона c: ";
    cin >> c;

    //Проверка
    cout << "\nМожно ли окружность 1 описать вокруг треугольника? " << boolalpha << okr1.triangle_around(a, b, c) << endl;
    cout << "Можно ли окружность 2 описать вокруг треугольника? " << boolalpha << okr2.triangle_around(a, b, c) << endl;
    cout << "Можно ли окружность 3 описать вокруг треугольника? " << boolalpha << okr3.triangle_around(a, b, c) << endl;

    //Вводим стороны треугольника для проверки вписанной окружности
    cout << "\nВведите стороны треугольника для проверки, можно ли вписать в него каждую окружность:" << endl;
    cout << "Сторона a: ";
    cin >> a;
    cout << "Сторона b: ";
    cin >> b;
    cout << "Сторона c: ";
    cin >> c;

    //Проверка
    cout << "\nМожно ли окружность 1 вписать в треугольник? " << boolalpha << okr1.triangle_in(a, b, c) << endl;
    cout << "Можно ли окружность 2 вписать в треугольник? " << boolalpha << okr2.triangle_in(a, b, c) << endl;
    cout << "Можно ли окружность 3 вписать в треугольник? " << boolalpha << okr3.triangle_in(a, b, c) << endl;
    return 0;
}