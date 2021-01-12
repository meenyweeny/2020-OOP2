/*
#include<iostream>
#include<memory>
using namespace std;

//<<<unique_ptr�� ���ؼ�>>>
//c++11 (������ auto_ptr�� ���� ��ü)
//smart ������ (unique ptr) -> memory ���̺귯�� �ʿ�
//���� Ư¡ �����ֳ�? �츮�� �ѹ� � ��ü�� �����ϰ� �� ��ü�� ����Ű��
//�����͸� �޸� ������ ��, �����Ͱ� �ΰ��ִٰ� �����ϸ�
//������ �����Ͱ� �Ѱ��� ����Ű�� �־��µ� ���� �����Ͱ� delete�ؼ� �����ƴµ�
//�� �ٸ� �����Ͱ� �����ּҴϱ� �װ� �� �����Ϸ����ϸ� �Ҹ�Ȱ�ü�� �ٽ� �Ҹ���Ѽ�
//���װ� �߻��� ->������� ��ü�� ���� �������� ��Ȯ���� �ʾƼ� �̷� ���� �߻�
//�̸� �ذ��ϱ� ���� ��ü���� ������ �������� �ο��ϰ�, �� ������ ����� ��ü��
//�Ҹ��ų�� ���ٴ� ������ �����Ų ��

class Test {
	int * data;
public:
	Test() {
		cout << "������!" << endl;
		data = new int[100]; //400byte
	}
	~Test() { //������ �Ǹ� data�� ���� delete ���ִ� ����
		cout << "�Ҹ���!" << endl;
		delete[] data;
	}
	void t() { cout << "�׽�Ʈ ��..." << endl; }
};

void testing() {
	unique_ptr<Test> up(new Test());
	//unique_ptr ������ ��ü up�� ���� (Test Ÿ���� ��ü�� ����ų �� �ִ� ��)
	//new Test() ������ �����ڰ� ���ư���, 400����Ʈ �Ҵ�� ���޸� ������ �����ּҸ�
	//Ŭ������ data ���� �����ϴ� ��, �׷� Ŭ�������� �� data�� ���� �ڿ��� ���

	//up�� Test ��ü�� ���������� �� ���� ���ҳ� ����� ���� ����

	up->t();
} //�� �Լ��� ������ �������� �� �ȿ��� ������ Test ��ü�� �Ҹ��ϰ� �ȴ�
//�׷� �� ���ʿ��� ������ ���� ������ �Ҹ��ڰ� �����ϰ� �ȴ�

int main() {
	testing();
}
*/


//=================================

//���� �����Ѻ���

#include<iostream>
#include<memory>
using namespace std;

class Test {
	int * data;
public:
	Test() {
		cout << "������!" << endl;
		data = new int[100];
	}
	~Test() { 
		cout << "�Ҹ���!" << endl;
		delete[] data;
	}
	void t() { cout << "�׽�Ʈ ��..." << endl; }
};

void testing() {
	/*
	Test * t1 = new Test();
	Test * t2 = t1; //�����ǿ� ���� ���� ����

	delete t1;
	delete t2; //��ü�� �ϳ��� �Ҹ��� �ι� �Ǵ� ������ ����
	*/

	unique_ptr<Test> up1(new Test()); //Test * up1=new Test(); �� ���� �ǹ�

	//unique_ptr<Test> up2 = up1; //������ �ּҷ� �����Ŵϱ� ������ ��
	//Test * up3 = up1; //�굵 ����

	//unique_ptr�� delete���� �� ���ִϱ� ���� delete ���� �ʿ䵵 ����
	//�����ϰ� �޸� ������ �ذ��ϸ鼭 �� �� ����
}

int main() {
	testing();
}