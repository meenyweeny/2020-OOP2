
//유니온 (공용체)
//가장 큰 사이즈의 멤버변수 기준으로 잡힘

#include<iostream>
using namespace std;


union JobUnion {
	//공용체는 가장 큰 멤버 변수의 크기로 메모리 할당
	char name[32]; //32byte
	float salary; //4byte
	int workerId; //4byte
}uJob;

union JobUnion2 {
	//char name[32]; //32byte
	long salary; //4byte
	int workerId; //4byte
}uJob2;

struct JobStruct {
	//char name[32]; //32byte
	float salary; //4byte
	int workerId; //4byte
}sJob;

struct JobStruct2 {
	long salary; //4byte
	int workerId; //4byte
}sJob2; //생성과 동시에 8byte의 공간이 생성됨


int main() {
	uJob.salary = 1.1f;
	uJob.workerId = 1234;
	sJob.salary = 2.1f;
	sJob.workerId = 44434;

	cout << uJob.salary << endl; //이상한 결과값이 나옴
	//무슨문제?
	//salary는 float 타입이므로
	//유니온에서 둘다 4바이트니까 같은공간을 공유한다고 했는데
	//1234가 1.1f 있는 곳을 덮어씀
	//근데 1234라는 정수 값이 float 타입에 들어가게 되면 생기는 문제가 발생한거임

	cout << uJob.workerId << endl;

	cout << endl;

	cout << sJob.salary << endl;
	cout << sJob.workerId << endl;

	cout << endl;

	cout << sizeof(uJob) << endl; //제일 큰 캐릭터 배열이 32byte니까 32나옴
	cout << sizeof(sJob) << endl; //안에 들어있는 바이트의 합보다 같거나 크게 나옴

	cout << endl;

	uJob2.salary = 11; //자료형이 막 다르면 loss될 수 있음
	uJob2.workerId = 1234;

	sJob2.salary = 21;
	sJob2.workerId = 44434;

	cout << uJob2.salary << endl; //11이 안나오고 같은 공간이라 1234로 override가 된것
	cout << uJob2.workerId << endl;
	//이 둘의 출력값이 다름
	//(자료형의 크기가 long랑 int가 같아서 메모리 공간이 하나임)

	cout << endl;

	cout << sJob2.salary << endl;
	cout << sJob2.workerId << endl;
}