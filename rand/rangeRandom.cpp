#include <cstdlib>
#include <iostream>
using namespace std;
static const int upperBound = 200;
static const int lowerBound = 100;
int main() {
    srand((unsigned)time(0));
    int x;
    double y;
    x = random();
    y = x % upperBound;
    while (y < lowerBound) {
        srand((unsigned)time(0));
        x = random();
        y = x % upperBound;
    }
    x = random();
    y += (double)x / RAND_MAX;
    cout << y << endl;
    return 0;
}
