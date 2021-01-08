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
	
	void SetAt(int index, int value) {
		if (index<0 || index>GetSize())
			throw "Out of Range!!";
		arr[index] = value;
	}

	int GetAt(int index) const { return arr[index]; }
	int GetSize() const { return size; }

protected:
	int * arr;
	int size;
};

void useArray(DynamicArray & a) {
	//레퍼런스의 장점
	//복사를 하지 않으니까 별도의 메모리 공간도 필요하지 않고
	//복사하는데 걸리는 시간도 save 할수 있다

	try {
		a.SetAt(3, 29);
		a.SetAt(9, -17);
		a.SetAt(20, 7); //예외 발생
	}
	catch (const char * e) { //예외 문자열로 발생하니까 매개변수 문자열로
		//예외처리함
		cout << "예외 : " << e << endl;
	}
}
int main() {
	DynamicArray arr(10);
	useArray(arr);
}