#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("file2.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int size;
    file >> size;

    if (!file || size <= 0) {
        cout << "Неверный размер массива!" << endl;
        return 1;
    }

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        if (!(file >> arr[i])) {
            cout << "Ошибка чтения массива!" << endl;
            delete[] arr;
            return 1;
        }
    }

    file.close();

    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete[] arr;

    return 0;
}
