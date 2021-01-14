//�����
//iostream ���ο�
//ostream�� cout��ü�� �θ�, istream�� cin��ü�� �θ� ����
/*
//iostream ������� ����
//extern Ű�����ΰ����� ���� ��򰡿� ���ǰ� �Ǿ����� ���̴�
//(���� ostream, istream ��ü��)
//�ٵ� �׳� class�� �ƴ϶� template Ŭ������ �Ʒ��Ͱ��� �������� type
//typedef�� ���ǵȰ��� ���� �츮�� ����� cout ��ü��
//basic_ostream<char> �� ��ü���� �� �� �ִ�

extern ostream cout;
extern istream cin;
typedef basic_ostream<char> ostream;
typedef basic_istream<char> istream;


basic_ostream // cout ��ü�� Ÿ��
basic_istream // cin��ü�� Ÿ��

//�� ���� �θ�Ŭ���� - > basic_ios
//�� �̰��� �θ�Ŭ���� - > ios_base

//�׷��� cout�̳� cin�� ios_base�� �ִ� ��ɵ��� �� �� �ִ�
*/

//stream? ����� ���������ο� �귯���� �������� �帧
/*
#include<iostream>
using namespace std;

int main() {
	float f = 0.01234f;
	ios_base::fmtflags old;
	//����� ���˰� ���õ� ����� �����ϴ� Ŭ����
	//fmtflags type - > setf�� ����Ÿ��, int Ÿ������ ��������

	cout << f << endl;

	old = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << f << endl; //0.12340

	old = cout.setf(ios_base::scientific, ios_base::floatfield);
	//old�� setf�� ������ �޴� ������ ����� �Ǿ���

	//setf�� ������� �����ϴ� �⺻���� �Լ�
	//1.234000e-02 (e-02�� 10�� -2��)4

	//setf�� �μ��� �ΰ���
	//�ڿ� ���� ���� floatfield->�Ǽ��迭 �ٷ�Ⱑ��
	//basefield->dec,hex,oct �ٷ�� ����
	//adjustfield

	//�տ� ���� ����, �ڿ����� floatfield�� �� �ΰ����� �� �� ����
	//��������->scientific, �����Ҽ�������->fixed

	//old��� ������ ���� �� ������ ��Ʈ���� �ǹ̸� ���� �ְ� ��
	//�׷��� �� ���ڵ��� ��Ʈ�� ��������

	//���⼭�� old�� ���� ������ ����ϰ� �־���, ������ ���ο� ������ setting
	//setting�� ��� �Ʒ����� ���
	cout << f << endl;

	cout.setf(old, ios_base::floatfield);
	//�ٽ� ����ġ�� ���ư��� ���ؼ� ������ ����ص� setting���� ������

	cout << f << endl;


	int a = 10;
	cout << a << endl;
	//cout << hex; //���������� �����ڿ����ε��� �Ǿ��ִ� ��
	cout.setf(ios_base::hex, ios_base::basefield); //cout<<hex�� ����
	cout << a << endl;


	bool test = true;
	cout << test << endl;
	//cout << boolalpha; //������ �����ε��� ���� ����
	cout.setf(ios_base::boolalpha); //�μ� �ϳ��� �������� ���� ������ ��
	cout << test << endl;
	//���� oldó�� �����·� ����صа��� ������ ��� ���ư���?
	cout.unsetf(ios_base::boolalpha);
	//setf�� ���� �ϳ��� ������ ��쿣 unsetf�� ���� �ǵ�����
	cout << test << endl;

}

*/

//setf���� ��������� �������ִ� �ٸ� �Լ���
//�ʺ� �����ϴ� width()
//�Ҽ��� �ڸ� �������ִ� precision() ���

#include<iostream>
using namespace std;

int main() {
	
	int a = 11;
	//cout.width(5);
	cout << a << endl;
	
	float f = 0.01234f;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << f << endl;
	cout.precision(3); //���� �Ҽ����� ���ڸ����� �ϰڴ�
	cout << f << endl;
}