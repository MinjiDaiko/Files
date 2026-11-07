#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("in.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int rows, cols;
    file >> rows >> cols;

    if (!file || rows <= 0 || cols <= 0) {
        cout << "Неверные размеры массива!" << endl;
        return 1;
    }

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> arr[i][j])) {
                cout << "Ошибка чтения массива!" << endl;

                for (int k = 0; k < rows; k++) {
                    delete[] arr[k];
                }
                delete[] arr;

                return 1;
            }
        }
    }

    file.close();

    for (int i = 0; i < rows; i++) {
        for (int j = cols - 1; j >= 0; j--) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
