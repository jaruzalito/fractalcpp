// poletrojkata.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

double trianglearea(double x1, double y1, double x2, double y2, double x3, double y3) {
    //(1 / 2)[x 1 (y 2 - y 3) + x 2 (y 3 - y 1) + x 3 (y 1 - y 2)]
    double area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;

    return area;
}

int main()
{
    double x1, x2, x3, y1, y2, y3;
    cout << "Podaj wspolrzędne wierzcholkow x1,y1: ";
    cin >> x1 >> y1;

    cout << "Podaj wspolrzędne wierzcholkow x2,y2: ";
    cin >> x2 >> y2;

    cout << "Podaj wspolrzędne wierzcholkow x3,y3: ";
    cin >> x3 >> y3;

    double summ = trianglearea(x1, y1, x2, y2, x3, y3);

    if (summ <= 0) {
        cout << "Z wierzochlkow o takich wspolrzednych nie powstanie trojkat!";
    }
    else {
        cout << "Pole trojkata o wspolrzednych : \nx1= " << x1 << "\ty1= " << y1 << "\nx2= " << x2 << "\t y2= " << y2 << "\nx3= " << x3 << "\ty3= " << y3 << "\n JEST ROWNE : " << summ;
    }
}

