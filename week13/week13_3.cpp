//그동안 명시적인 형변환을 할 때 괄호를 써왔었는데,
//이를 대체할수있는 네가지 연산자가 추가됐음


//1.const_cast : const, volatile 등의 속성을 변경
//volatile->변수 정의할 때 이걸로 지정하면 컴퓨터가 가끔 자기 혼자
//변수를 상수로 만들어버리는 작업에서 예외가 됨

/*
#include<iostream>
using namespace std;

int main() {
	char univ[] = "Inha";
	const char * c1 = univ;
	char * c2;
	//c2 = c1; //const char * 를 그냥 char * 에 넣으려해서 오류
	//상수가 아닌 대상체에 상수를 넣으려고 하니까 오류 발생

	//univ배열은 상수가 아니므로 c2가 이 번지를 가져도 문제가 없다
	c2 = univ; //가능
	c2 = const_cast<char*>(c1); //상수성을 제거
	//포인터의 상수성만 바꾸는거지 내가 가리키는 대상의 타입을 바꾼다거나
	//기본타입을 포인터타입으로 바꾼다거나 할 순 없다

	//int * pi = const_cast<int*>(c1); //포인터의 상수성을 바꿀순 있지만
	//대상체의 타입을 char에서 int로 바꿀라고 하니까 오류

	float f;
	//f = const_cast<float>(c1); //얘도 오류

	c2[0] = 'i'; //상수성을 제거했으니까 가능
	//c1[0] = 'i'; //상수라 불가능
	cout << c2 << endl;
}
*/

//======================================================

//2.dynamic_cast : 서로 상속관계에 있는 class의 포인터 및 레퍼런스 타입 형변환
//만약 형변환에 문제가 있는 경우면 해당 cast 연산자는 null값을 반환하거나
//bad cast예외를 던진다

/*
#include<iostream>
using namespace std;

class A {
public:
	virtual void Func() {}
};
class B : public A {};
class C :public B {};

int main() {
	A * pa1 = new C; //상속관계에서 아무런 문제 x
	A * pa2 = new A; //자기 클래스니까 문제 x
	C * pc1 = dynamic_cast<C*>(pa1); //정상적으로 캐스팅
	C * pc2 = dynamic_cast<C*>(pa2); //캐스팅 실패 //A객체의 주소를 갖고있으므로
	//캐스팅 실패하면 NULL 리턴하여 문제상황을 알림 (포인터니까 NULL리턴이 가능)

	cout << pa1 << endl;
	cout << pa2 << endl;
	cout << pc1 << endl; //pa1과 같은 주소값
	cout << pc2 << endl; //00000000출력됨

	try {
		C& rc1 = dynamic_cast<C&>(*pa2); //부모가 자식에 대입되는 캐스팅
		//당연히 오류
		//이런 경우엔 bad_cast 예외가 발생을 함
		//레퍼런스의 경우엔 NULL 리턴이 불가능하니까 (특정값 반환이 불가능하니까)
		//bad_cast 예외를 던지는 것임
	}
	catch (bad_cast & e) {
		cout << "bad_cast~~" << endl;
	}
}
*/

//3.static_cast : 논리적으로 변환 가능한 타입만 변환
//그 외의 변환은 에러로 처리

//4.reinterpret_cast : 포인터끼리, 포인터와 수치형 간의 변환
//즉 위험한 변환도 가능해진 것

//내가 만든 클래스를 다른 타입으로 형변환,
//다른 타입으로 되어있는 클래스를 내가 만든 타입으로 형변환

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
	operator int() {
		return this->real;
	}
	int Real() const { return real; }
	int Imaginary() const { return imaginary; }
private:
	int real, imaginary;
};

int main() {
	Complex c1(1, 1);
	Complex c2(7, 2);
	Complex c3(0, 0);

	int i;
	i = c2.operator int(); //i = c2; //같은 의미
	cout << i << endl;
}