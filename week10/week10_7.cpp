//예외처리
//예외->우리가 당연하다고 가정한 상황이 거짓이 될 때
//어느 상황에 발생?
//1.컴퓨터에 사용 가능한 메모리가 부족한 경우
//2.보조기억장치에 남은 용량이 부족한 경우
//3.사용자가 입력한 범위 밖의 값을 입력하는 경우나 존재하지 않는 파일의 이름을 입력하는 경우

//버그나 오류같이 개발자의 실수로 일어나는 경우와 예외는 다름
//예외는 프로그램을 잘못짜서 생기는게 아니라
//프로그램 외적인 요인에서 발생
//이를 적절하게 대처하는 처리가 중요함

#include<iostream>
using namespace std;

class DynamicArray {
public:
	DynamicArray(int arraySize) {
		arr = new int[arraySize];
		size = arraySize;
	}
	~DynamicArray() {}
	/*
	void SetAt(int index, int value) {
		arr[index] = value; //여기서 예외 발생 가능
		//잘못된 인덱스를 받았을 때
	}
	*/
	bool SetAt(int index, int value) {
		if (index<0 || index > GetSize())
			return false;
		arr[index] = value;
		return true;
	}

	int GetAt(int index) const { return arr[index]; }
	int GetSize() const { return size; }

protected:
	int * arr;
	int size;
};

int main() {
	/*
	DynamicArray arr(10);
	for (auto i = 0; i < 11; i++) 
		arr.SetAt(i, (i + 1) * 10); //i가 범위 벗어난 값을 받게됨


	cout << "Size of arr = " << arr.GetSize() << "\n";


	for (auto i = 9; i >= 0; i--)
		cout << "arr[" << i << "] = " << arr.GetAt(i) << "\n";
		*/

	//=================================================
	/*
	//SetAt을 bool 타입으로 바꿔서 오류 해결해보고
	//이런 오류 해결방식이 어떤 문제점을 갖고있는지 살펴보자

	DynamicArray arr2(10);
	bool b;
	b = arr2.SetAt(20, 0);
	if (!b)
		cout << "인덱스 오류 발생!" << endl;

	//문제점 - > 매번 리턴이 참인지 거짓인지 받는 코드를 받아야 함
	//1.매번 반환값을 비교해야함
	//2.함수가 이미 다른 용도로 반환값을 사용하고 있음
	//본연의 소스코드와 예외처리코드가 뒤엉켜서 지저분하고
	//원래 반환값들을 원래 용도로 사용할 수도 없게 되기도 함
	*/

	//->이러한 문제를 구조적 예외처리를 통해서 해결할 수 있음


}