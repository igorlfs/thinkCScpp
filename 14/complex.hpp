#ifndef COMPLEX
#define COMPLEX
class Complex {
   private:
    double real, imag;
    double mag, theta;
    bool cartesian, polar;
    void calculateCartesian();
    void calculatePolar();

   public:
    Complex() {
        cartesian = false;
        polar = false;
    }
    Complex(double r, double i) {
        real = r;
        imag = i;
        cartesian = true;
        polar = false;
    }
    void printPolar();
    void printCartesian();

    double getReal();
    double getImag();
    double getMag();
    double getTheta();

    void setPolar(double m, double t);
    void setCartesian(double r, double i);
};
#endif
