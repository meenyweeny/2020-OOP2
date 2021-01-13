#include<iostream>
using namespace std;

class Complex {
public:
	Complex(int r, int i)
		:real(r), imaginary(i) {}
	Complex operator+(const Complex& right) {
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag);
	}
	operator int() { return this->real; }
	int Real() const { return real; }
	int Imaginary() const { return imaginary; }
private:
	int real;
	int imaginary;
};

ostream& operator << (ostream& o, const Complex& right) {
	o << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return o;
}

istream& operator>>(istream& i, Complex& right) {
	int real, imag;
	cout << "실수부 : ";
	i >> real;
	cout << "허수부 : ";
	i >> imag;
	right = Complex(real, imag);
	return i;
}
int main() {
	Complex c1(0, 0);
	cin >> c1;
	cout << c1 << endl;
}