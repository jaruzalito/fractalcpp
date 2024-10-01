/*
Wybieramy losowo dwie próbki wysokości. 
Następnie losowo wybieramy drogę drogę pomiędzy tymi punktami.
Droga jest losowana w taki sposób, że kolejny odcinek oznacza ruch do jednego z 8 punktów sąsiednich na siatce próbek.
Powroty na jakimkolwiek fragmencie drogi są niedopuszczalne.
Oblicz średnie nachylenie tej drogi badając nachylenia poszczególnych jej odcinków. Wynik wyraź w stopniach.*/

#include <stack>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
const int xS = 5;
const int yS = 4;
const int minH = 1;
const int maxH = 3;//dopisac po 3 zera i smiga
#define PI 3.1415

using namespace std;
int** generate() {
    int** tab = new int* [xS];
    for (int i = 0; i < xS; i++) {
        tab[i] = new int[yS];
    }

    for (int i = 0; i < xS; i++) {
        for (int j = 0; j < yS; j++) {
            tab[i][j] = minH + static_cast<float>(rand()) / (RAND_MAX / (maxH - minH));
        }
    }
    return tab;
}

struct Point {
    short x;
    short y;

    // Operator porównania musi być const, aby działał z set
    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

Point randompoint() {
    short px = rand() % xS;  // Wylosowanie x i y punktu
    short py = rand() % yS;
    Point p = { px, py };
    return p;
}

int main() {
    srand(time(NULL));  

    int** terrain = generate();

    // Wylosowanie dwóch punktów startowych
    Point p1 = randompoint();
    Point p2 = randompoint();

    cout << "P1 = (" << p1.x << "," << p1.y << ")\t P2 = (" << p2.x << "," << p2.y << ")" << endl;

    // Definicja 8 kierunków sąsiadujących punktów
    short dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
    short dy[8] = { 1, -1, 0, -1, 1, 1, -1, 0 };

    stack<Point> stackset;
    stack<double> angles;
    set<Point> visited;  // Zbiór odwiedzonych punktów

    Point current = p1;
    stackset.push(current);
    visited.insert(current);

    bool reached = false;
    double totalAngle = 0.0;
    int segmentsCount = 0;

    // Pętla, która szuka drogi do punktu P2
    while (!reached) {
        bool validMove = false;
        while (!validMove) {
            // Wybieranie losowego sąsiada
            short step = rand() % 8;
            short newX = current.x + dx[step];
            short newY = current.y + dy[step];

            // Sprawdzamy, czy nowy punkt jest w zakresie i nie został odwiedzony
            if (newX >= 0 && newX < xS && newY >= 0 && newY < yS) {
                Point newP = { newX, newY };
                if (visited.find(newP) == visited.end()) {
                    // Obliczamy różnicę wysokości i odległość w płaszczyźnie
                    double d_xy = sqrt(pow(newX - current.x, 2) + pow(newY - current.y, 2));
                    double d_z = abs(terrain[newX][newY] - terrain[current.x][current.y]);

                    // Obliczamy kąt nachylenia
                    double angle = atan2(d_z, d_xy) * 180 / PI;
                    angles.push(angle);
                    totalAngle += angle;
                    segmentsCount++;

                    // Aktualizacja pozycji
                    stackset.push(newP);
                    visited.insert(newP);
                    current = newP;
                    validMove = true;

                    // Sprawdzenie, czy osiągnęliśmy punkt docelowy
                    if (newX == p2.x && newY == p2.y) {
                        reached = true;
                        break;
                    }
                }
            }
        }
    }

    // Obliczamy średnie nachylenie trasy
    if (segmentsCount > 0) {
        double averageAngle = totalAngle / segmentsCount;
        cout << "Średnie nachylenie drogi: " << averageAngle << " stopni" << endl;
    }

    // Zwolnienie pamięci
    for (int i = 0; i < xS; i++) {
        delete[] terrain[i];
    }
    delete[] terrain;

    return 0;
}
/* zle przemyslane
    bool pointFound = false;
    while (!pointFound) {
        short step = rand() % 8;
        short newX = p1.x + dx[step];
        short newY = p1.y + dy[step];

        Point newP = { newX,newY };
        if (stackset.empty()==true) {
            stackset.push(newP);
        }
        else if (stackset.top().x != newX || stackset.top().y != newY) {
            stackset.push(newP);
        }
        else {
            cout << endl << "Nie mozna wracac do tego samego punktu!";
        }
        short currX = stackset.top().x;
        short currY = stackset.top().y;
        cout <<"\nP("<<currX<<","<<currY<<")";

        double d_xy = sqrt(abs(dx[step]) + abs(dy[step]));
        double d_z = abs(terrain[newX][newY] - terrain[currX][currY]);

        angles.push(abs(atan2(d_z, d_xy) * 180 / PI));

        if (newX == p2.x && newY == p2.y) {//sprawdza czy juzd dotarlo do celu
            break;
        }
        //if(stackset.top != )
        //Point newP = { newX,newY };
        pointFound = true;

    }



    for (int i = 0;i < xS;i++) {
        delete[] terrain[i];
    }
    delete[] terrain;
}
*/

