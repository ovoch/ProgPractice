#include <iostream>
using namespace std;

bool isDivisibleByThree(int number) {
    if (number == 0) return true;

    int remainder = number % 3;
    if (remainder == 0) return true; 

    return isDivisibleByThree(number / 10); 
}

int main() {
    int number;
    cout << "Enter the natural number :";
    cin >> number;

    bool result = isDivisibleByThree(number);

    if (result) {
        cout << "Can be divided by 3 " << endl;
    }
    else {
        cout << "Can not be divided by 3" << endl;
    }

    return 0;
}