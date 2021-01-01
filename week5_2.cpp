#include<iostream>
#include<functional>
using namespace std;

//람다함수 정리
//익명함수다
//함수 객체를 생성한다
//함수 포인터와 함수 객체의 장점을 지닌다
//캡쳐 기능을 통해 함수 밖의 변수에 접근할 수 있고
// &같은 기호를 통해 람다함수 안에서도 외부 변수의 값을 변경할 수 있다 (참조하기 때문)
//재귀 호출도 가능하다.
//이외에도 몇몇 기능이 더 있음



int k = 1;
int main() {
	short c = 5, d = 7;
	auto inha = [c, d](float a, int b)->int { 
		//c = -11; //에러->외부 변수는 수정할 수 없음
		//그 이유는 '값으로서' 복제해서 (캡쳐해서) 사용하기 때문
		k = 2; //전역변수는 수정도 되고 캡쳐블록에 따로 선언도 안해도 됨
		return a + b + c + d+k; };
	cout << inha(1.9f, 2) << endl;

	//값을 정 바꾸고 싶다면 앰퍼샌드 기호로 캡쳐해오자 (즉 참조 형태로 캡쳐하자)
	auto inha2 = [&c, d](float a, int b)->int {
		c = -11; //이제 가능해짐
		return a + b + c + d + k; };
	cout << inha2(1.9f, 2) << endl;
	cout << c << endl; //updated

	short x = 5, y = 7;
	//내부에서 값을 둘 다 변경하고 싶다면

	//1.둘 다 앰퍼샌드 기호 쓰기
	auto inha3 = [&x, &y](float a, int b)->int {
		x = -11; //이제 가능해짐
		y = 8;
		return a + b + x + y; };
	cout << inha3(1.9f, 2) << endl;

	//2.앰퍼샌드 기호 하나만 딱 쓰기
	//전제 모든 메인함수에있는 변수에 대한 참조로서 쓰이는 것
	auto inha4 = [&](float a, int b)->int {
		x = -11; //이제 가능해짐
		y = 8;
		return a + b + x + y; };
	cout << inha4(1.9f, 2) << endl;

	x = 5, y = 7;

	//=를 넣으면 변화는 못시키고 그냥 전체 변수 참조한다는 것
	//전체 변수를 값으로서 캡쳐
	auto inha5 = [=](float a, int b)->int {
		//x = -11; //변화가 불가능
		return a + b + x + y; };
	cout << inha5(1.9f, 2) << endl;


	
	
	
	//반환타입에 대한 것


	auto inha6 = [=](float a, int b)->int {
		return a + b + x + y; }(1.9f, 2);
	cout << inha6 << endl;
	cout << typeid(inha6).name() << endl;
	//int라고 출력된다
	//auto로 선언한 inha6이 일반 정수형 변수임을 알 수 있다


	auto inha7 = [=](float a, int b)->int {
		//x = -11; //변화가 불가능
		return a + b + x + y; };
	cout << typeid(inha7).name() << endl;
	//int라고 안나오고 클래스람다어쩌고나옴
	//이건 int 일반변수 아니고 클래스 객체임
	cout << inha7(1.9f, 2) << endl;






	//거듭제곱을 구하는 람다함수(power)
	auto power = [](int base, int e)->int {
		int result = 1; //함수 안의 지역변수
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	}(2,8);
	cout << power << endl;

	//return 값 명확하니까 auto 말고 함수형태 명시해준 상황
	int power2 = [](int base, int e)->int {
		int result = 1; //함수 안의 지역변수
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	}(2, 8);
	cout << power2 << endl;

	//return 타입 지정안해줬는데 그냥 auto 말고 함수형태 명시해준 상황
	int power3 = [](int base, int e) {
		int result = 1; //함수 안의 지역변수
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	}(2, 8);
	cout << power3 << endl;

	

	//이건 오류남
	//왜?
	//람다함수 객체인데 power4가 람다함수의 번지주소를 받아야 하는 변수인데
	//그게 int 타입이라고 선언을 해놨으니까 안된다
	/*
	int power4 = [](int base, int e){
		int result = 1;
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	};
	cout << power4(2,8) << endl;
	*/

	//이렇게 auto로 고쳐주면 바로 됨
	auto power5 = [](int base, int e) {
		int result = 1;
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	};
	//power5는 변수인데 함수 쓰듯이 해당 주소를 참조해서 함수처럼 쓸 수 있는 거
	cout << power5(2, 8) << endl;
	cout << power5(4, 2) << endl;




	//======================================================


	//재귀함수 구현해보기
	//람다는 굳이 외부에 함수 만들 필요가 없음
	/*
	auto fact = [&fact](int n)->int {
		if (n == 1)
			return 1;
		else
			//return n * fact(n - 1); //오류
			//왜?
			//다시 호출한 fact(n-1)의 입장에선 밖에서 fact 함수를 찾을 수 없음
			//캡쳐블록에 &fact를 넣어서 해결
			//근데 또 오류가 생김 왜?
			//auto로 지정해준 타입때문에 생김
			//왜?
			//함수가 자기 자신을 호출하는게 재귀인데 그거에 대한 리턴값을
			//추론을 할 수가 없으니까

	}
	*/

	//->여기서 functional이라고 하는 라이브러리 써야한다

	//람다에서 재귀를 구현할 때 auto 타입으로는 추론 불가
	//반드시 대입하려고 하는 함수의 타입이 명시되어야 함
	//functional library가 필요
	//재귀함수일때만 이런 부분이 적용

	//컴파일러의 auto가 추론을 하려면 넘어오는 값들을 보고 해야하는데
	//넘어오는 값들을 보기도 전에 안쪽에서 자기자신을 호출하고 있음
	//auto가 그걸 알기 전단계에서 call을 하면(재귀) 알 수가 없다
	//그걸 알기 위해서는 아예 이게 어떤 식으로 리턴이 되고 있는지를
	//명시해주어야 한다
	//즉, 재귀함수에는 function 라이브러리랑 거기에 맞는 타입에 대한 구현을 해줘야 한다

	function<int(int)> fact = [&fact](int n)->int {
		if (n == 1)
			return 1;
		else
			return n * fact(n - 1);

		// return n <= 1 ? 1 : n * fact(n - 1);
	};
	cout << fact(6) << endl;



}