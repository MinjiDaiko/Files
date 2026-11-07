#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("file1.txt");
    string word;

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    while (file >> word) {
        cout << word << endl;
    }

    file.close();

    return 0;
}
