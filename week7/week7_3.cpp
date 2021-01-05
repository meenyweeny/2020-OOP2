//접근제어

#include<iostream>
using namespace std;

class AccessControl {
	//아무것도 지정안해주면 기본적으로 private
public:
	char publicData;
	void publicFunc() {};
protected:
	int protectedData;
	void protectedFunc() {};
private:
	float privateData;
	void privateFunc() {};
public:
	void AccessAllMembers();
};

void AccessControl::AccessAllMembers() {
	//class 안에서는 접근 자유롭게 가능
	publicData = 'A';
	publicFunc();
	protectedData = 100;
	protectedFunc();
	privateData = 4.5f;
	privateFunc();
}


int main() {
	AccessControl ac;
	/*
	//가능
	ac.publicData = 'A';
	ac.publicFunc();

	//불가능
	//외부에선 접근 불가
	ac.protectedData = 100;
	ac.protectedFunc();
	ac.privateData = 4.5f;
	ac.privateFunc();
	*/


	ac.AccessAllMembers();

}
