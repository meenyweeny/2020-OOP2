//memory 라이브러리의 unique_ptr을 사용하여 문제를 해결할 수 있을 것 같습니다

#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Hero {
public:
	Hero(int m) {
		cout << "생성자 호출" << endl;
		id = new int;
		*id = m;
		name = "미정";
	}
	int GetId() const { return *id; }
	void SetId(int m) {
		cout << "접근자 호출 SetId" << endl;
		*id = m;
	}
	string GetName() const { return name; }
	void SetName(const string& _name) {
		cout << "접근자 호출 SetName " << endl;
		name = _name;
	}
	void PrintHero() {
		cout << name << " : " << *id << endl;
	}
	~Hero() {
		cout << "소멸자 호출" << endl;
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

		h2->SetName("리퍼");
		h2->PrintHero();

		h1->SetName("라인하르트");
		cout << endl;
		h1->SetId(2);
		h1->PrintHero();
		h2->PrintHero();
		cout << h2->GetName() << endl;
	}
	catch (...) {
		cout << "예외!" << endl;
	}

	return 0;
}