#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double computeFunction(double x, double precision) {
    if (x < 0.5) {
        throw std::invalid_argument("x must be >= 0.5");
    }


    double ln_x = log(10);
    double sum = -log(1 / x);

    return (1.0 / ln_x) * sum;
}

int main() {
    const double START = 0.5;
    const double END = 2.0;
    const double STEP = 0.05;
    const double B = 0.0;
    const double controlPoint = 1.5;
    const double expectedValue = 0.176091;

    cout << fixed << setprecision(6);


    for (double x = START; x <= END; x += STEP) {
        double y = computeFunction(x, B);
        cout << "x = " << x << ", y = " << y << endl;
    }

    return 0;
}