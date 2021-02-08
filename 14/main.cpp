#include <iostream>

#include "complex.hpp"
using namespace std;
Complex add(Complex& a, Complex& b) {
    double real = a.getReal() + b.getReal();
    double imag = a.getImag() + b.getImag();
    Complex sum(real, imag);
    return sum;
}
Complex mult(Complex& a, Complex& b) {
    double mag = a.getMag() * b.getMag();
    double theta = a.getTheta() + b.getTheta();
    Complex product;
    product.setPolar(mag, theta);
    return product;
}
int main() {
    /* Printing Test */
    /* Complex c1(2.0, 3.0); */
    /* c1.printCartesian(); */
    /* c1.printPolar(); */

    /* Sum Test */
    /* Complex c1(2.0, 3.0); */
    /* Complex c2(3.0, 4.0); */
    /* Complex sum = add(c1, c2); */
    /* sum.printCartesian(); */

    /* Mult Test */
    Complex c1(2.0, 3.0);
    Complex c2(3.0, 4.0);
    Complex product = mult(c1, c2);
    product.printCartesian();
}
