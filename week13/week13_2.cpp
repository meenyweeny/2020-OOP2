//멤버함수로만 오버로딩 할 수 있는 케이스
/*
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
	int Real() const { return real; }
	int Imaginary() const { return imaginary; }
private:
	int real, imaginary;
};

//일반함수
ostream& operator << (ostream& o, const Complex & right) {
	//출력포맷 지정
	o << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return o;
}

int main() {
	Complex c1(1, 1);
	Complex c2(7, 2);
	Complex c3(0, 0);

	c3 = c1.operator+(c2); //c3 = c1 + c2; //둘이 같음
	//얘네는 c1,c2가 모두 Complex 타입의 객체였기 때문에
	//연산자 오버로딩이 멤버함수로 가능했음

	cout << c3.Real() << ", " << c3.Imaginary() << endl;
	//cout << c2 << endl; //오류 (어떻게 처리하는지 컴퓨터가 모름)
	//원래 int나 char 등은 cout이라는 outputstream의 객체가 알아서 해줬는데
	//Complex 클래스 객체 타입은 어떻게 하는지 모름
	//어떻게 출력하고싶은지 연산자 오버로딩으로 디자인해야함
	//왼쪽은 출력객체고 오른쪽 피연산자만 Complex 객체이므로
	//멤버함수를 사용해서 구현할 수 없음->일반함수를 써야만함
	cout << c2 << endl;
}
*/