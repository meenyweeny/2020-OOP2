#include<iostream>
using namespace std;



//����ü �迭
/*
struct Student {
	//����ü �� ��?
	//����� �κ��� ��� �ڷ� �����Ϸ���
	//�迭�� type�� ���ƾ��ϴµ� ����ü�� �ƴ�
	int id; //4byte
	char name[20]; //20byte
	float grade[2]; //1,2�б� ���� //8byte

	//32byte ������ ����ü
	//os���� 40byte ������ �� �� ŭ��ŭ���ϰ�??
};

int main() {

	Student sInfos[4] = {
		{202001,"Lee",{4.3f,4.1f}},
		{202010,"Choi",{3.3f,3.1f}},
		{202107,"Park",{3.5f,4.1f}},
		{202101,"Kim",{4.2f,3.7f}}
	};

	for (auto i = 0; i < 4; i++) {
		cout << sInfos[i].id << endl;
		cout << sInfos[i].name << endl;
		cout << sInfos[i].grade[0] << endl; //1�б� ����
		cout << sInfos[i].grade[1] << endl;
		cout << endl;
	}
}
*/


//����ü�� ������
/*
#include<iostream>
using namespace std;

//����ü�� ���� �����ϰ� �����͸� �ۼ��ؼ� ����ü�� ������

struct Rectangle {
	//�������
	int x, y; //��ǥ x,y
	int w, h; //width,height

};

int main(){

	Rectangle r = { 15,10,50,70 };
	Rectangle * pr = &r; //����ü r�� ����Ű�� ������

	cout << r.x << endl;
	cout << (*pr).x << endl;
	//������ �켱������ * ���� ó���ϴϱ� ��ȣ�� �� ��� ������ x���� ���

	cout << endl;

	cout << (*pr).y << endl; // (,),*,. �װ��� ������ �ʿ�
	cout << pr->y << endl; //�ϳ��� ȭ��ǥ ������
	//�ؿ� ����� �ξ� �����ϰ� �������� �پ�� �Ǽ����ϵ� ��� �� ���� ��

	cout << endl;

	cout << (*pr).h << "\n" << pr->h << endl;
	cout << endl;

	pr->h = 40; //�簢���� ���̸� �ٲ㺸��

	cout << (*pr).h << "\n" << pr->h << endl;

	cout << endl;

	(*pr).w = 100;
	cout << r.w << "\n" << pr->w << endl;
}
*/

//����ü�� �����͸� �̿��� ��ũ�帮��Ʈ ����
//����ü�� ������ ���¿��߰ڴ�
#include<iostream>
using namespace std;

struct LinkedList {
	int data;
	LinkedList * p; //���� ����ų ��� ����ü �����ϱ�
	//���� ��带 ����ų ������ ����
};

int main() {
	LinkedList a, b, c;
	a.data = 99;
	a.p = &b; //setup
	b.data = 93;
	b.p = &c;
	c.data = 94;
	c.p = &a;

	//a�� �̿��ؼ� b�� data ���
	cout << b.data << endl;
	cout << a.p->data << endl;
	//a.p�� b�� �ּҴϱ�
	//ȭ��ǥ �����ڷ� �� data������

	cout << endl;

	//c�� data ���
	cout << c.data << endl;

	//b�� �̿��ؼ� c�� data ���
	cout << b.p->data << endl;
	cout << (*b.p).data << endl; //���������������

	//a�� �̿��ؼ� c�� data ���
	cout << a.p->p->data << endl;

	//c�� �ڱ��ڽ��� �ѹ��� ���ƿͼ� ���
	cout << c.p->p->p->data << endl;
}
