#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

int main() {

    const size_t matrixSize = 100;
    int A1[matrixSize][matrixSize];
    int A2[matrixSize][matrixSize];
    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            A1[i][j] = rand() % 50 + 1;
            A2[i][j] = rand() % 50 + 1;
        }
    }
    ofstream matrixOutput1("matrix1.txt");

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            matrixOutput1 << A1[i][j] << ' ';
        }
        matrixOutput1 << '\n';
    }
    matrixOutput1.close();

    ofstream matrixOutput2("matrix2.txt");

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            matrixOutput2 << A2[i][j] << ' ';
        }
        matrixOutput2 << '\n';
    }


    matrixOutput2.close();
    size_t matrixInput[matrixSize][matrixSize];
    size_t matrixInput2[matrixSize][matrixSize];
    ifstream matrixData1("matrix1.txt");
    size_t position = 0;
    size_t number = 0;
    size_t  a = 0;
    size_t b = 0;
    size_t d = 0;
    while (matrixData1 >> number) {

        const size_t matrixNumber = size_t(floor(position / (matrixSize * matrixSize)));
        const size_t row = size_t(floor(position / matrixSize)) % matrixSize;
        matrixInput[row][position % matrixSize] = number;
        position++;
    }

    matrixData1.close();
    ifstream matrixData2("matrix2.txt");

    position = 0;
    number = 0;

    while (matrixData2 >> number) {

        const size_t matrixNumber = size_t(floor(position / (matrixSize * matrixSize)));
        const size_t row = size_t(floor(position / matrixSize)) % matrixSize;
        matrixInput2[row][position % matrixSize] = number;
        position++;
    }

    matrixData2.close();
    cout << "Matrices: " << endl;

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            cout << matrixInput[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            cout << matrixInput2[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    int C[matrixSize][matrixSize];

    ofstream matrixOutput3("matrix3.txt");
    cout << "Matrices multiplication: " << endl;
    unsigned int start_time = clock();
#pragma omp parallel for shared (matrixInput , matrixInput2, C) private (a,b,d)   
    for (int a = 0; a < matrixSize; a++) {
        for (int b = 0; b < matrixSize; b++) {
            C[a][b] = 0;
            for (int d = 0; d < matrixSize; d++) {
                C[a][b] += matrixInput[a][d] * matrixInput2[d][b];
            }
        }
    }
    unsigned int end_time = clock();
    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            matrixOutput3 << C[i][j] << ' ';
        }
        matrixOutput3 << '\n';
    }
    matrixOutput3.close();


    unsigned int search_time = end_time - start_time;
    cout << search_time << endl;
    time = fopen("time.txt", "w");
    fprintf(time, "%d ms", _time);
    return 0;
}