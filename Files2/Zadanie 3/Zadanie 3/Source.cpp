#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Неверный размер массива!" << endl;
        return 1;
    }

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    ofstream file("out.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        delete[] arr;
        return 1;
    }

    file << size << endl;

    for (int i = size - 1; i >= 0; i--) {
        file << arr[i] << " ";
    }

    file << endl;
    file.close();

    delete[] arr;

    return 0;
}
