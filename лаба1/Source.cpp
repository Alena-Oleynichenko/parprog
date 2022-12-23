#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

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
    cout << "Matrices multiplication: " << endl;
    unsigned int start_time = clock(); 
    ofstream matrixOutput3("matrix3.txt");
    for (int i = 0; i < matrixSize; i++) { 
        for (int j = 0; j < matrixSize; j++) {
            C[i][j] = 0;
            for (int k = 0; k < matrixSize; k++) {
                C[i][j] += matrixInput[i][k] * matrixInput2[k][j];
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
    return 0;
}