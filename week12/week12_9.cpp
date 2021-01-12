//연산자 오버로딩
#include<iostream>
using namespace std;

class Complex { //복소수 class, 실수와 허수부를 갖고 있음
public:
	Complex(int r, int i)
		:real(r), imaginary(i) { //초기화 리스트
	}
	Complex add(const Complex& right) {
		//리턴타입이 Complex인, Complex 객체를 인수로 받는 일반 메서드
		//역할->실수부끼리 허수부끼리 덧셈연산

		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag); //객체 type으로 리턴
	}

	int Real() const { return real; }
	int Imaginary() const { return imaginary; }

private:
	int real;
	int imaginary;
};

int main() {
	Complex c1(1, 1);
	Complex c2(7, 2);
	Complex c3(0, 0);

	c3 = c1.add(c2); //객체 복사가 됨
	//c3=c1+c2; //이런 방식을 하고싶다
	//그러면 이 +에 대한 디자인을 알아서 할 수 있어서
	//만든 클래스 간의 연산자들을 자유롭게 연산할 때 쓸 수 있게 해줌
	//어떻게 할까?
	cout << c3.Real() <<", "<<c3.Imaginary() << endl;
}