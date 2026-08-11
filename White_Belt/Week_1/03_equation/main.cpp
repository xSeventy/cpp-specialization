#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double A,B,C;

    cin >> A >> B >> C;

    if(A != 0) // Проверяем является ли уравнение квадратным
    {
        double Dis = pow(B,2) - 4 * A * C; // Создаем переменную для дискриминанта

        if(Dis >= 0) { // Проверяем дискриминант на равенство 0
            if(Dis == 0) {
                double x{-B / (2.0 * A)}; // Дискриминант равен 0? Находим единственный корень
                cout << x;
            }
            else { // Дискриминант не равен нулю? Находим два корня
                double x1{(-B + sqrt(Dis)) / (2 * A)};
                double x2{(-B - sqrt(Dis)) / (2 * A)};
                cout << x1 << ' ' << x2;
            }
        }
    }
    else { // Уравнение не квадратное
        if(B != 0) { // Проверяем является ли уравнение линейным
            cout << (-C / B);
        }
    }
    
    return 0;
}