#include <iostream> 
#include <windows.h> 

using namespace std;

const int width = 20;
const int height = 20;
int shipX, score;
bool gameOver;

struct Asteroid
{
    int x;
    int y;
};

void Setup()
{
    gameOver = false;
    shipX = width / 2;
    score = 0;
}

void Draw(const Asteroid& asteroid)
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
                cout << "#";
            else if (i == height - 1 && j == shipX)
                cout << "^";
            else if (i == asteroid.y && j == asteroid.x)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{
    if (GetAsyncKeyState('A') & 0x8000)
        shipX--;
    else if (GetAsyncKeyState('D') & 0x8000)
        shipX++;
    else if (GetAsyncKeyState('X') & 0x8000)
        gameOver = true;
}

void Logic(Asteroid& asteroid)
{
    // Падение астероида 
    asteroid.y++;

    // Если астероид падает на корабль, игра заканчивается 
    if (asteroid.x == shipX && asteroid.y == height - 1)
        gameOver = true;

    // Подсчет очков при успешном уклонении от астероида 
    if (asteroid.y == height - 1)
    {
        score++;
        // Создание нового астероида 
        asteroid.x = rand() % width;
        asteroid.y = 0;
    }

    // Задержка перед следующим шагом 
    Sleep(200);
}

int main()
{
    Setup();
    Asteroid asteroid;
    asteroid.x = rand() % width;
    asteroid.y = 0;

    while (!gameOver)
    {
        Draw(asteroid);
        Input();
        Logic(asteroid);
    }

    cout << "Game Over!" << endl;
    cout << "Your score: " << score << endl;
    return 0;
}