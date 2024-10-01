#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include <cmath>   // sqrt

const int xS = 5000;
const int yS = 4000;

using namespace std;

// Funkcja generująca losowe wartości wysokości terenu
void generate(float** terrain) {
    for (int x = 0; x < xS; x++) {
        for (int y = 0; y < yS; y++) {
            terrain[x][y] = 1200 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (3500 - 1200)));
        }
    }
}

// Funkcja obliczająca pole powierzchni terenu
float calculateSurfaceArea(float** terrain) {
    float totalArea = 0.0f;
    float dx = 1.0f; // Odległość pozioma między punktami w osi x (1 m)
    float dy = 1.0f; // Odległość pozioma między punktami w osi y (1 m)

    // Przechodzimy po siatce i obliczamy pole dla każdego prostokąta utworzonego przez 4 punkty
    for (int x = 0; x < xS - 1; x++) {
        for (int y = 0; y < yS - 1; y++) {
            // Różnice wysokości między sąsiednimi punktami
            float dz_x = terrain[x + 1][y] - terrain[x][y];     // Różnica wysokości w osi x
            float dz_y = terrain[x][y + 1] - terrain[x][y];     // Różnica wysokości w osi y
            float dz_diag = terrain[x + 1][y + 1] - terrain[x][y]; // Różnica wysokości na przekątnej

            // Długości krawędzi na podstawie twierdzenia Pitagorasa
            float length_x = sqrt(dx * dx + dz_x * dz_x);    // Długość odcinka w osi x
            float length_y = sqrt(dy * dy + dz_y * dz_y);    // Długość odcinka w osi y
            float length_diag = sqrt(dx * dx + dy * dy + dz_diag * dz_diag); // Długość przekątnej

            // Obliczamy przybliżone pole jako suma pól dwóch trójkątów utworzonych przez przekątne
            float area = 0.5f * length_x * length_y + 0.5f * length_diag * length_diag;
            totalArea += area;
        }
    }

    return totalArea;
}

int main() {
    srand(time(0)); // Inicjalizacja generatora losowych liczb

    // Dynamiczna alokacja tablicy 2D na stercie
    float** terrain = new float*[xS];
    for (int i = 0; i < xS; i++) {
        terrain[i] = new float[yS];
    }

    // Generowanie losowych wysokości terenu
    generate(terrain);

    // Obliczanie pola powierzchni terenu
    float surfaceArea = calculateSurfaceArea(terrain);

    // Wyświetlenie wyniku
    cout << "Pole powierzchni terenu wynosi: " << surfaceArea << " metrów kwadratowych" << endl;

    // Zwolnienie pamięci
    for (int i = 0; i < xS; i++) {
        delete[] terrain[i];
    }
    delete[] terrain;

    return 0;
}
