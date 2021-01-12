//������ �����ε�
#include<iostream>
using namespace std;

class Complex { //���Ҽ� class, �Ǽ��� ����θ� ���� ����
public:
	Complex(int r, int i)
		:real(r), imaginary(i) { //�ʱ�ȭ ����Ʈ
	}
	Complex add(const Complex& right) {
		//����Ÿ���� Complex��, Complex ��ü�� �μ��� �޴� �Ϲ� �޼���
		//����->�Ǽ��γ��� ����γ��� ��������

		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag); //��ü type���� ����
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

	c3 = c1.add(c2); //��ü ���簡 ��
	//c3=c1+c2; //�̷� ����� �ϰ�ʹ�
	//�׷��� �� +�� ���� �������� �˾Ƽ� �� �� �־
	//���� Ŭ���� ���� �����ڵ��� �����Ӱ� ������ �� �� �� �ְ� ����
	//��� �ұ�?
	cout << c3.Real() <<", "<<c3.Imaginary() << endl;
}