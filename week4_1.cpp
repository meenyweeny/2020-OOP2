//����ü
/* ����ü ��� ��
#include<iostream>
using namespace std;

struct Character {
	int jobType; // 0:���ɼ���, 1:�߸����, 2:������
};

int main() {
	Character c;
	c.jobType =2;

	if (c.jobType ==2) {
		cout << "�����ݷ�!" << endl;
	}
	//���� 2�� � ĳ�������� �ڵ带 ������ ��Ȯ�ϰ� �� �� ����
	//�� ������ ����ü�� �̿��ؼ� �ذ��� �� �ִ�

}
*/

/*
#include<iostream>
using namespace std;

//enum { JOB_NECROMANCER, JOB_BARBARIAN, JOB_WIZARD };
//���� ��ü�� ��ġ�� �ǹ̸� ���� 0,1,2,...

//enum {JOB_NECROMANCER,JOB_BARBARIAN=2, JOB_WIZARD};
//���� 0,2,3,.. �̷��� �� (�ε��� �� ��������)

//����ü�� struct,unionó�� �ϳ��� Ÿ��
//�׷��� �̸��� ���� �� ����
enum JOB_KINDS {JOB_NECROMANCER,JOB_BARBARIAN,JOB_WIZARD};

struct Character {
	//int jobType; // 0:���ɼ���, 1:�߸����, 2:������
	JOB_KINDS jobType; //int ��� enum type���� ����ü ������ ������
};

int main() {
	Character c;
	c.jobType = JOB_WIZARD;

	if (c.jobType == JOB_WIZARD) {
		cout << "�����ݷ�!" << endl;
	}
	//��Ȯ�ϰ� �� �� �ִ�

}
*/

#include<iostream>
using namespace std;

enum Color {RED,GREEN,BLUE,YELLOW};
//�⺻������ int Ÿ������ ���������� (0,1,2,...������ó��)
//������ �⺻���� ������ �������� �ʴ� (ex: GREEN+BLUE �Ұ�)

//enum�� ���� ū ������ ������������ ���������� ��ȯ�Ǵ�
//weak type ����
//�׻� ������ ���̽��� �ϰ� �ְ� ���� ������� ������ ����Ǹ�
//������ ����ų ������ �׻� ���� �ִ�

/*
enum Java{PASS,FAIL};
enum Python{PASS,FAIL};
*/

//�ٸ� ����ü�ӿ��� �ұ��ϰ� ���� �̸��� ������ �� �� ���� ������ �ִ�

int main() {
	Color c1 = RED;
	Color c2;

	//����� Casting �� ���� ����
	//��������� ���� 2�� Casting�Ͽ� �Ҵ�
	Color c3 = (Color)2; //BLUE�� ����Ǵ� ȿ���� ���´�
	cout << c3 << endl;

	//������ range�� �߿�
	Color c4 = (Color)1000;
	//�̷��� �ع����� ������ �ȳ����ϴµ�
	//Color ����ü�� ���� �Ŵϱ� ���� �˼��� ���� �ȴ�
	//1000�� �ش��ϴ� ��ȣ�� ��� ��� ���� �Ұ�

	//�ݴ��� ��� ���԰� ��� ������ ����
	//����:������ Casting
	int n = BLUE; //int���� ���� ���� �ִ� ���� ����
	int o = GREEN + BLUE; //int���� ������ �ֱ� ����
	//�� �޴� ���� ������ ����ü ������ �ƴ϶� int�� ���� �� �ִ�
	//����ü�� symbol���� ���������� int Ÿ������ casting �ǰ� ����

	cout << n << endl;
	cout << o << endl;

	//������� �Ұ�
	//c1 = GREEN + BLUE; //error
	//c1 = c1 + 2;

	//�������� �Ұ�
	//c2 = 3;
}