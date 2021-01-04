//동적할당
/*
#include<iostream>
using namespace std;

char * ReverseString(const char * src, int len) { 
	char * rev = new char[len + 1];
	//+1해서 만든 이유 - > 끝에 NULL 문자 저장을 위해서
	for (auto i = 0; i < len; ++i) {
		rev[i] = src[len - i - 1];
	}
	rev[len] = NULL;
	//끝에 NULL 처리 '\0'
	return rev;
	//새로 생성된 heap 영역의 맨 앞번지의 주소를 return
}

int main() {

	char orig[] = "Inha"; //a뒤에 null문자 들어가있을 것
	char * copy = ReverseString(orig, 4);
	//함수에 첫번째 인자로 메모리 번지가 던져짐
	//파라미터 첫번째가 const니까 읽기 전용으로
	//const char * src는 orig의 맨 앞번째 즉, I
	//파라미터 len으로는 4가 copy 되지만
	//src로는 그냥 주소만 전달되는 것

	//copy는 ReverseString의 rev의 첫번째 칸의 주소값을 가지고있으면서 포인팅을 하게된다

	cout << orig << endl;
	cout << copy << endl;
	delete[] copy; //동적할당 한 부분 해제
	copy = NULL; //원래 copy에 들어있던 rev의 첫 칸의 주소를 0으로 만들어서 아예 연결을 끊는 효과

}
*/


//문자열의 길이와 복사 예제
#include<iostream>
#include<cstring>
#pragma warning (disable : 4996)
using namespace std;

int main() {
	//원본 문자열 길이
	char src[] = "Inha Univ";
	int len = strlen(src);
	cout << len << endl; //->9

	//원본 문자열 복사
	char * dest = new char[len + 1]; //null문자를 고려해서 +1
	strcpy(dest, src);
	cout << src << endl;
	cout << dest << endl;


	delete[] dest;
	dest = NULL; //변수 자체가 가리키는 주소도 완전히 삭제
}