#include <iostream>
#include <fstream>

using namespace std;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int is_factorial(unsigned long long number) {
    int i = 0;
    unsigned long long fact;

    while ((fact = factorial(i)) <= number) {
        if (fact == number) {
            return i; 
        }
        i++;
    }
    return -1;
}

int main() {
    ifstream file("numbers.txt");
    if (!file) {
        cerr << "Не удалось открыть файл!" << endl;
        return EXIT_FAILURE;
    }

    cout << "Найденные факториалы:\n";
    unsigned long long number;

    while (file >> number) {
        int result = is_factorial(number);
        if (result != -1) {
            cout << number << " = " << result << "!" << endl;
        }
    }

    file.close();
    return EXIT_SUCCESS;
}