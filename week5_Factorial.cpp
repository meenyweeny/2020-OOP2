#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "���丮�� ���� ����(1~10) : ";
	cin >> n;

	int * arr = new int[n]; //array �����Ҵ� ����

	for (int i = 0; i < n; i++) { //array�� n���� ���丮�� ������ �� �ֱ�
		cin >> *(arr + i);
	}
	for (int i = 0; i < n; i++) {
		int tmp = arr[i];

		[](int tmp)->void { //�����Լ�
			int result=1;
			for (int i = 1; i <= tmp; i++) {
				result *=i;
			}
			cout << result << endl;
		}(tmp); //�μ��� tmp �༭ �ٷ� �����Ŵ
		//return type�� void�� ���丮�� �� ��±��� ���⼭ �ѹ���
	}

	delete[] arr; //�޸� ���� ����
}