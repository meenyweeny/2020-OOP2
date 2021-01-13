//������ �����ε�
//�ǹ̸� ��ġ�� ������ �����ε��� ��������

//����Լ��� ����� ������ �����ε�
/*
#include<iostream>
using namespace std;

class Complex {
public:
	Complex(int r, int i)
		:real(r), imaginary(i) {}
	Complex add(const Complex & right) {
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag);
	}
	Complex operator+(const Complex & right){ //�ǿ����� �ΰ��� ���
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag);
	}
	//��������
	Complex operator++() {
		this->real++;
		return *this; //�ش簴ü�� ������
	}
	
	//�������� -> ���� ���� ������ ������ �����ϴ� ���
	Complex operator++(int) {
		//�Ű������� �׳� int��� ��(������������ �˸��� ����)
		Complex prev(this->real, this->imaginary);
		this->real++;
		return prev;
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

	//�ǿ����� �ΰ��� ���(+,-,* ����)
	//c3 = c1.add(c2); ������ ���, �޼����� ���ϰ��� c3�� ����
	c3 = c1 + c2; //ComplexŸ������ ���Ϲ��� ���� c3�� �ȴ�
	cout << c3.Real() << ", " << c3.Imaginary() << endl;

	//�ǿ����� �ϳ��� ���

	Complex init(1, 1);
	Complex prefix(0, 0);
	Complex postfix(0, 0);

	prefix = ++c1; //�������� //prefix = c1 = (2, 1)
	postfix = c1++; //�������� //postfix = (2, 1), c1 = (3, 1)
	//++�� ��쿣 ��� ���������̰� ��� ������������ �� ���� ����

	cout << prefix.Real() << ", " << prefix.Imaginary() << endl;
	cout << postfix.Real() << ", " << postfix.Imaginary() << endl;
	cout << c1.Real() << ", " << c1.Imaginary() << endl;
	//�ٽ�->��������� ���������� ������ ������ ��
}
*/

//�Ϲ��Լ��� �̿��� ������ �����ε�

#include<iostream>
using namespace std;

class Complex {
	//ģ���� ������ �Լ�������  Complex Ŭ������ ��� ����� ���� ����
	friend Complex operator+(const Complex& left, const Complex & right);

public:
	Complex(int r, int i)
		:real(r), imaginary(i) {}
	Complex add(const Complex & right) {
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag);
	}
	int Real() const { return real; }
	int Imaginary() const { return imaginary; }

private:
	int real, imaginary;
};

Complex operator+(const Complex& left,const Complex & right) {
	//���ϰ��� Complex������
	//int real = left.Real() + right.Real();
	//int imag = left.Imaginary() + right.Imaginary();
	
	//friend�� ���� �ܺο����� Ŭ������ private ��������� ���� ����
	int real = left.real + right.real;
	int imag = left.imaginary + right.imaginary;
	return Complex(real, imag);
}

int main() {
	Complex c1(1, 1);
	Complex c2(7, 2);
	Complex c3(0, 0);
	c3 = operator+(c1, c2); //c3 = c1 + c2; //���� ����
	cout << c3.Real() << ", " << c3.Imaginary() << endl;
}