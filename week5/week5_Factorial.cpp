#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "팩토리얼 숫자 갯수(1~10) : ";
	cin >> n;

	int * arr = new int[n]; //array 동적할당 받음

	for (int i = 0; i < n; i++) { //array에 n개의 팩토리얼 연산할 수 넣기
		cin >> *(arr + i);
	}
	for (int i = 0; i < n; i++) {
		int tmp = arr[i];

		[](int tmp)->void { //람다함수
			int result=1;
			for (int i = 1; i <= tmp; i++) {
				result *=i;
			}
			cout << result << endl;
		}(tmp); //인수로 tmp 줘서 바로 실행시킴
		//return type은 void로 팩토리얼 값 출력까지 여기서 한번에
	}

	delete[] arr; //메모리 공간 해제
}