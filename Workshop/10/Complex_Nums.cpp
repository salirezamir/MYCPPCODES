#include <iostream>

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

int main()
{
    Complex n[2], tmp;
    cin >> n[0].real >> n[0].img;
    cin >> n[1].real >> n[1].img;
    tmp = add(n[0], n[1]);
    cout << tmp.real << " " << tmp.img << endl;
    tmp = sub(n[0], n[1]);
    cout << tmp.real << " " << tmp.img << endl;
    tmp = mul(n[0], n[1]);
    cout << tmp.real << " " << tmp.img;
    return 0;
}