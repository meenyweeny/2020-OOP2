//memory ���̺귯���� unique_ptr�� ����Ͽ� ������ �ذ��� �� ���� �� �����ϴ�

#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Hero {
public:
	Hero(int m) {
		cout << "������ ȣ��" << endl;
		id = new int;
		*id = m;
		name = "����";
	}
	int GetId() const { return *id; }
	void SetId(int m) {
		cout << "������ ȣ�� SetId" << endl;
		*id = m;
	}
	string GetName() const { return name; }
	void SetName(const string& _name) {
		cout << "������ ȣ�� SetName " << endl;
		name = _name;
	}
	void PrintHero() {
		cout << name << " : " << *id << endl;
	}
	~Hero() {
		cout << "�Ҹ��� ȣ��" << endl;
		delete id;
	}
private:
	int * id;
	string name;
};

int main() {
	try {
		unique_ptr<Hero> h1(new Hero(1));
		h1->PrintHero();
		unique_ptr<Hero> h2(new Hero(h1->GetId()));

		h2->SetName("����");
		h2->PrintHero();

		h1->SetName("�����ϸ�Ʈ");
		cout << endl;
		h1->SetId(2);
		h1->PrintHero();
		h2->PrintHero();
		cout << h2->GetName() << endl;
	}
	catch (...) {
		cout << "����!" << endl;
	}

	return 0;
}