//����Լ��θ� �����ε� �� �� �ִ� ���̽�
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

//�Ϲ��Լ�
ostream& operator << (ostream& o, const Complex & right) {
	//������� ����
	o << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return o;
}

int main() {
	Complex c1(1, 1);
	Complex c2(7, 2);
	Complex c3(0, 0);

	c3 = c1.operator+(c2); //c3 = c1 + c2; //���� ����
	//��״� c1,c2�� ��� Complex Ÿ���� ��ü���� ������
	//������ �����ε��� ����Լ��� ��������

	cout << c3.Real() << ", " << c3.Imaginary() << endl;
	//cout << c2 << endl; //���� (��� ó���ϴ��� ��ǻ�Ͱ� ��)
	//���� int�� char ���� cout�̶�� outputstream�� ��ü�� �˾Ƽ� ����µ�
	//Complex Ŭ���� ��ü Ÿ���� ��� �ϴ��� ��
	//��� ����ϰ������ ������ �����ε����� �������ؾ���
	//������ ��°�ü�� ������ �ǿ����ڸ� Complex ��ü�̹Ƿ�
	//����Լ��� ����ؼ� ������ �� ����->�Ϲ��Լ��� ��߸���
	cout << c2 << endl;
}
*/