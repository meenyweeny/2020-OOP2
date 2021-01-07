#pragma once
class Point {
public:
	typedef int COOR_T;

	void Print() const; //읽기 전용
	Point();
	Point(COOR_T _x, COOR_T _y);
	Point(const Point& pt);

	void setX(COOR_T value) { //점값을 바꿀 수 있는 접근자
		if (value < 0)
			x = 0;
		else if (value > 100)
			x = 100;
		else
			x = value;
	} //class 안에서 구현된거니까 자동으로 inline 함수

	//private으로 선언된 멤버변수 값들을 함수를 통해 바꿀 수 있게 해줌
	//이 메서드들은 캡슐화된 변수들에 접근하는 용도로 사용됨
	void setY(COOR_T value);


	COOR_T getX() const { return x; } //값을 꺼내는 용도
	//이 함수 안에서는 값에대한 변경이 없다는걸 const 통해서 알려줌


	COOR_T getY() const { return y; }

private:
	COOR_T x, y;
};

inline void Point::setY(COOR_T value) {
	if (value < 0)
		y = 0;
	else if (value > 100)
		y = 100;
	else
		y = value;
}

//inline 키워드는 함수 호출시에 해당 메서드로 이동하는게 아니라
//그 코드를 현재 실행하고있는 함수쪽으로 가져온다
//장점->빠른 속도 처리
//함수 호출을 하고 호출시에 스택을 이용하는 그런 과정들을 좀 줄일 수 있다
//단, 반대로 삽입시에 들어가는 오버헤드들이 생기기때문에
//그런것들이 코드가 너무 길면 오히려 안좋을 수도 있다

//짧은 코드의 빈번한 삽입이 있을 때 사용하면 좋음
