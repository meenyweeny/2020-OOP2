
//���Ͽ� (����ü)
//���� ū �������� ������� �������� ����

#include<iostream>
using namespace std;


union JobUnion {
	//����ü�� ���� ū ��� ������ ũ��� �޸� �Ҵ�
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
}sJob2; //������ ���ÿ� 8byte�� ������ ������


int main() {
	uJob.salary = 1.1f;
	uJob.workerId = 1234;
	sJob.salary = 2.1f;
	sJob.workerId = 44434;

	cout << uJob.salary << endl; //�̻��� ������� ����
	//��������?
	//salary�� float Ÿ���̹Ƿ�
	//���Ͽ¿��� �Ѵ� 4����Ʈ�ϱ� ���������� �����Ѵٰ� �ߴµ�
	//1234�� 1.1f �ִ� ���� ���
	//�ٵ� 1234��� ���� ���� float Ÿ�Կ� ���� �Ǹ� ����� ������ �߻��Ѱ���

	cout << uJob.workerId << endl;

	cout << endl;

	cout << sJob.salary << endl;
	cout << sJob.workerId << endl;

	cout << endl;

	cout << sizeof(uJob) << endl; //���� ū ĳ���� �迭�� 32byte�ϱ� 32����
	cout << sizeof(sJob) << endl; //�ȿ� ����ִ� ����Ʈ�� �պ��� ���ų� ũ�� ����

	cout << endl;

	uJob2.salary = 11; //�ڷ����� �� �ٸ��� loss�� �� ����
	uJob2.workerId = 1234;

	sJob2.salary = 21;
	sJob2.workerId = 44434;

	cout << uJob2.salary << endl; //11�� �ȳ����� ���� �����̶� 1234�� override�� �Ȱ�
	cout << uJob2.workerId << endl;
	//�� ���� ��°��� �ٸ�
	//(�ڷ����� ũ�Ⱑ long�� int�� ���Ƽ� �޸� ������ �ϳ���)

	cout << endl;

	cout << sJob2.salary << endl;
	cout << sJob2.workerId << endl;
}