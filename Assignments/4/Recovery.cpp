#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Complex
{
public:
    double real;
    double img;
};

Complex constructComplex(double a, double b)
{
    Complex tmp;
    tmp.real = a;
    tmp.img = b;
    return tmp;
}

Complex conjugate(Complex in)
{
    Complex tmp;
    tmp.real = in.real;
    tmp.img = -1 * in.img;
    return tmp;
}

Complex add(Complex a, Complex b)
{
    Complex tmp;
    tmp.real = a.real + b.real;
    tmp.img = a.img + b.img;
    return tmp;
}

Complex sub(Complex a, Complex b)
{
    Complex tmp;
    tmp.real = a.real - b.real;
    tmp.img = a.img - b.img;
    return tmp;
}

Complex mul(Complex a, Complex b)
{
    Complex tmp;
    tmp.real = a.real * b.real - a.img * b.img;
    tmp.img = a.real * b.img + a.img * b.real;
    return tmp;
}

void printPolarForm(Complex in)
{
    printf("%.2f", sqrt(pow(in.img, 2) + pow(in.real, 2)));
    cout << "e^(i";
    printf("%.2f", (atan2(in.img, in.real) * 180 / 3.14));
    cout << ")";
}

int main()
{
    cout << fixed << setprecision(2);
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Complex c = constructComplex(x1, y1);
    Complex c2 = constructComplex(x2, y2);
    Complex c3 = conjugate(c);
    cout << c3.real << ' ' << c3.img << '\n';
    Complex c4 = add(c, c2);
    cout << c4.real << ' ' << c4.img << '\n';
    Complex c5 = sub(c, c2);
    cout << c5.real << ' ' << c5.img << '\n';
    Complex c6 = mul(c, c2);
    cout << c6.real << ' ' << c6.img << '\n';
    printPolarForm(c);
    return 0;
}