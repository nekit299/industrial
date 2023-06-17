#include <iostream>
#include <windows.h>

using namespace std;

const int width = 20;
const int height = 20;

class Game {
private:
    int shipX;  // Координата X корабля
    int score; // Счет игры
    bool gameOver; // Флаг, указывающий на завершение игры

    struct Asteroid {
        int x; // Координата X астероида
        int y;   // Координата Y астероида

    };

    Asteroid asteroid; // Текущий астероид

public:
    Game() {
        shipX = width / 2;       // Инициализация начальной позиции корабля
        score = 0;              // Инициализация счета игры
        gameOver = false;       // Инициализация флага окончания игры
        asteroid.x = rand() % width;    // Генерация начальной позиции астероида по координате X
        asteroid.y = 0;         // Инициализация начальной позиции астероида по координате Y
    }

    void Setup() {
        gameOver = false;       // Инициализация флага окончания игры
        shipX = width / 2;       // Инициализация начальной позиции корабля
        score = 0;              // Инициализация счета игры
        asteroid.x = rand() % width;    // Генерация начальной позиции астероида по координате X
        asteroid.y = 0;         // Инициализация начальной позиции астероида по координате Y
    }

    void Draw() {
        system("cls");          // Очистка экрана консоли
        for (int i = 0; i < width + 2; i++)
            cout << "#";        // Верхняя граница игрового поля
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0 || j == width - 1)
                    cout << "#";    // Боковые границы игрового поля
                else if (i == height - 1 && j == shipX)
                    cout << "^";    // Отрисовка корабля
                else if (i == asteroid.y && j == asteroid.x)
                    cout << "*";    // Отрисовка астероида
                else
                    cout << " ";    // Пустое пространство
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";        // Нижняя граница игрового поля
        cout << endl;
        cout << "Score: " << score << endl;   // Вывод счета игры
    }
}

void Input() {
    if (GetAsyncKeyState('A') & 0x8000)
        shipX--;
    else if (GetAsyncKeyState('D') & 0x8000)
        shipX++;
    else if (GetAsyncKeyState('X') & 0x8000)
        gameOver = true;
}

void Logic() {
    asteroid.y++;   // Перемещение астероида вниз

    if (asteroid.x == shipX && asteroid.y == height - 1)
        gameOver = true;    // Проверка столкновения корабля с астероидом

    if (asteroid.y == height - 1) {
        score++;    // Увеличение счета при успешном прохождении астероида
        asteroid.x = rand() % width;    // Генерация новой позиции астероида по координате X
        asteroid.y = 0; // Установка начальной позиции астероида по координате Y
    }

    Sleep(200); // Задержка для создания анимации падения астероидов
}

void Run() {
    Setup();

    while (!gameOver) {
        Draw();     // Отрисовка игрового поля
        Input();    // Обработка ввода пользователя
        Logic();    // Обновление состояния игры
    }

    cout << "Game Over!" << endl;
    cout << "Your score: " << score << endl;
}
};

int main() {
    Game game;
    game.Run();

    return 0;
}