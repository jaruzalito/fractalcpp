// lab2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include<stdlib.h>
#include <iostream>

using namespace std;

const int xS = 51;
const int yS = 41;
const int zS = 28;

void generate(float tab[xS][yS][zS]) {
    //(rand()%8)+18 liczby z zakresu calkoweite
    //float randomFloat = 18.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 7.0));
    //liCzby z zakresu zmienno przecinkowe
    for (int x = 0;x < xS;x++) {
        for (int y = 0;y < yS;y++) {
            for (int z = 0; z < zS;z++) {
                tab[x][y][z] = (rand() % 8) + 18;
            }
        }
    }
}

int highestSectionTemp(float tab[xS][yS][zS]) {
    float maxAvg = 0;
    int bestAvgIndex = 0;

    for (int x = 0;x < xS;x++) {
        float tempSum = 0;
        for (int y = 0;y < yS;y++) {
            for (int z = 0; z < zS;z++) {
                tempSum += tab[x][y][z];
            }
        }
        float sumAvg = tempSum / (yS * zS);

        if (sumAvg > maxAvg) {
            maxAvg = sumAvg;
            bestAvgIndex = x;
        }
    }

    return bestAvgIndex;
}


int main()
{
    srand(time(NULL));
    float arr[xS][yS][zS];

    generate(arr);

    int index = highestSectionTemp(arr);

    cout << "Przekroj pokoju o najwyzszej temperaturze znajduje sie w X = " << index;
    return 0;

}

