#include <iostream>
#include <cmath>

using namespace std;

void solveQuadraticEquation(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "delta: " << delta << "\nx1: " << x1 << "\nx2: " << x2;
    }
    else if (delta == 0) {
        double x = -b / (2 * a);
        cout << "delta: " << delta << "\n Jedno miejsce zerowe - x: " << x;
    }
    else if (delta < 0) {
        cout <<"delta: "<<delta<<"\nBrak miejsc zerowych";
    }
}

int main() {
    double a, b, c;

    cout << "Podaj wspolczynnik a: ";
    cin >> a;

    cout << "Podaj wspolczynnik b: ";
    cin >> b;

    cout << "Podaj wspolczynnik c: ";
    cin >> c;

    solveQuadraticEquation(a, b, c);

    return 0;
}