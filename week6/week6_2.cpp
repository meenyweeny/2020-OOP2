//문자열

/*
//복사와 길이
#include<iostream>
#include<string>
using namespace std;

int main() {
	char srcs[] = "Inha Univ"; //c언어에선 문자열을 표현하려면 이방법뿐이었음
	string src = "Inha Univ";
	string dest;

	//modern style
	cout << src.size() << endl; //method 형태로
	//더 편하고 가독성도 good
	dest = src; //일반 변수 대입하듯이 대입가능
	//c style보다 훨씬 간단
	cout << src << endl;
	cout << dest << endl;

	//수행속도는 근본자체가 다른게 아니라 modern style(c++ style)과
	//old style(c style)에 비해 큰 이점은 없다
	//그냥 더 편리할 뿐
}
*/

//결합과 비교
/*
//Old Style
#include<iostream>
#include<string>
#include<cstring>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	char str1[] = "Inha Univ";
	char str2[] = "Harvard Univ";
	strcat(str1, str2); //(str1뒤에 str2를) 두 문자열의 결합
	cout << str1 << endl;
	cout << str2 << endl;

	return 0;
	//사용자가 설정한 배열보다 더 큰 데이터를 넣으려고 할때
	//나타나는 오류가 나타남

}
*/


//문자열 비교

//Old Style
/*
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	char str1[10] = "Inha";
	char str2[] = "Harvard";
	char str3[] = "Inha";
	if (strcmp(str1, str2) == 0)
		cout << "같다" << endl;
	else {
		cout << "다르다" << endl;
	}

	if (strcmp(str1, str3) == 0)
		cout << "같다" << endl;
	else
		cout << "다르다" << endl;

	char a[10] = "I";
	char b[] = "H";
	char c[] = "J";

	if (strcmp(a, b) == 0)
		cout << "같다" << endl;
	else {
		cout << "다르다" << endl;
		cout << strcmp(a, b) << endl;
	}
	//얜 1이 출력됨
	//I랑 H비교
	//알파벳 순서대로 했을 때 뒤에꺼가 더 크기때문에 1을 리턴

	if (strcmp(a, c) == 0)
		cout << "같다" << endl;
	else {
		cout << "다르다" << endl;
		cout << strcmp(a, c) << endl;
	}
	//얜 -1이 출력됨
	//알파벳 순서에서 I가 더 앞이므로 -1이 나옴

	//아스키코드값을 비교하는 것
	//str1<str2 : -1 return
	//str1>str2 : +1 return

	//같은값이면 0이 나옴
}
*/

//Modern style
/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	//이어붙이기
	
	string str5 = "Inha";
	string str6 = "Univ";

	str5 = str5 +str6;
	cout << str5 << endl;
	cout << str6 << endl;
	

	//비교
	string str1 = "Inha";
	string str2 = "Inha";

	if (str1 == str2) {
		cout << "같다" << endl;
		cout << (str1 == str2) << endl; //같으면 1을 return //tf형태의 return
		cout << typeid((str1 == str2)).name() << endl; //bool 출력(비교연산자이므로)
	}
	else {
		cout << "다르다" << endl;
		cout << (str1 == str2) << endl; //다르면 0을 return
	}


}
*/


//find method
//내가 찾고자하는 특정 문자열 찾아서 위치값 정수형태로 return

#include<iostream>
#include<string>
using namespace std;

int main() {
	string str = "Hi, Inha Univ.";
	cout << str.find("Inha") << endl; //I의 위치 인덱스값 return
	cout << str.find("Univ") << endl; //U의 위치 인덱스값 return
	//cout << str.find("univ") << endl; //제대로 된 결과값을 얻을 수 없다

	//특정 문자열의 길이

	string capture = str.substr(4, 4); //인덱스 4부터 4개 (시작 인덱스와 갯수를 파라미터로)
	cout << capture << endl;
}