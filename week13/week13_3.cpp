//�׵��� ������� ����ȯ�� �� �� ��ȣ�� ��Ծ��µ�,
//�̸� ��ü�Ҽ��ִ� �װ��� �����ڰ� �߰�����


//1.const_cast : const, volatile ���� �Ӽ��� ����
//volatile->���� ������ �� �̰ɷ� �����ϸ� ��ǻ�Ͱ� ���� �ڱ� ȥ��
//������ ����� ���������� �۾����� ���ܰ� ��

/*
#include<iostream>
using namespace std;

int main() {
	char univ[] = "Inha";
	const char * c1 = univ;
	char * c2;
	//c2 = c1; //const char * �� �׳� char * �� �������ؼ� ����
	//����� �ƴ� ���ü�� ����� �������� �ϴϱ� ���� �߻�

	//univ�迭�� ����� �ƴϹǷ� c2�� �� ������ ������ ������ ����
	c2 = univ; //����
	c2 = const_cast<char*>(c1); //������� ����
	//�������� ������� �ٲٴ°��� ���� ����Ű�� ����� Ÿ���� �ٲ۴ٰų�
	//�⺻Ÿ���� ������Ÿ������ �ٲ۴ٰų� �� �� ����

	//int * pi = const_cast<int*>(c1); //�������� ������� �ٲܼ� ������
	//���ü�� Ÿ���� char���� int�� �ٲܶ�� �ϴϱ� ����

	float f;
	//f = const_cast<float>(c1); //�굵 ����

	c2[0] = 'i'; //������� ���������ϱ� ����
	//c1[0] = 'i'; //����� �Ұ���
	cout << c2 << endl;
}
*/

//======================================================

//2.dynamic_cast : ���� ��Ӱ��迡 �ִ� class�� ������ �� ���۷��� Ÿ�� ����ȯ
//���� ����ȯ�� ������ �ִ� ���� �ش� cast �����ڴ� null���� ��ȯ�ϰų�
//bad cast���ܸ� ������

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
	A * pa1 = new C; //��Ӱ��迡�� �ƹ��� ���� x
	A * pa2 = new A; //�ڱ� Ŭ�����ϱ� ���� x
	C * pc1 = dynamic_cast<C*>(pa1); //���������� ĳ����
	C * pc2 = dynamic_cast<C*>(pa2); //ĳ���� ���� //A��ü�� �ּҸ� ���������Ƿ�
	//ĳ���� �����ϸ� NULL �����Ͽ� ������Ȳ�� �˸� (�����ʹϱ� NULL������ ����)

	cout << pa1 << endl;
	cout << pa2 << endl;
	cout << pc1 << endl; //pa1�� ���� �ּҰ�
	cout << pc2 << endl; //00000000��µ�

	try {
		C& rc1 = dynamic_cast<C&>(*pa2); //�θ� �ڽĿ� ���ԵǴ� ĳ����
		//�翬�� ����
		//�̷� ��쿣 bad_cast ���ܰ� �߻��� ��
		//���۷����� ��쿣 NULL ������ �Ұ����ϴϱ� (Ư���� ��ȯ�� �Ұ����ϴϱ�)
		//bad_cast ���ܸ� ������ ����
	}
	catch (bad_cast & e) {
		cout << "bad_cast~~" << endl;
	}
}
*/

//3.static_cast : �������� ��ȯ ������ Ÿ�Ը� ��ȯ
//�� ���� ��ȯ�� ������ ó��

//4.reinterpret_cast : �����ͳ���, �����Ϳ� ��ġ�� ���� ��ȯ
//�� ������ ��ȯ�� �������� ��

//���� ���� Ŭ������ �ٸ� Ÿ������ ����ȯ,
//�ٸ� Ÿ������ �Ǿ��ִ� Ŭ������ ���� ���� Ÿ������ ����ȯ

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
	i = c2.operator int(); //i = c2; //���� �ǹ�
	cout << i << endl;
}