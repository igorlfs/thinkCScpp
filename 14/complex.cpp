
#include "complex.hpp"

#include <assert.h>
#include <math.h>

#include <iostream>

void Complex::calculateCartesian() {
    assert(polar);
    real = mag * cos(theta);
    imag = mag * sin(theta);
    cartesian = true;
    assert(polar && cartesian);
}
double Complex::getReal() {
    if (cartesian == false) calculateCartesian();
    return real;
}
double Complex::getImag() {
    if (cartesian == false) calculateCartesian();
    return imag;
}
void Complex::calculatePolar() {
    assert(cartesian);
    theta = atan(imag / real);
    mag = sqrt(real * real + imag * imag);
    assert(cartesian && polar);
}
double Complex::getMag() {
    if (polar == false) calculatePolar();
    return mag;
}
double Complex::getTheta() {
    if (polar == false) calculatePolar();
    return theta;
}
void Complex::printCartesian() {
    std::cout << getReal() << " + " << getImag() << "i" << std::endl;
}
void Complex::printPolar() {
    std::cout << getMag() << " e^ " << getTheta() << "i" << std::endl;
}
void Complex::setPolar(double m, double t) {
    mag = m;
    theta = t;
    cartesian = false;
    polar = true;
}
void Complex::setCartesian(double r, double i) {
    real = r;
    imag = i;
    cartesian = true;
    polar = false;
}
