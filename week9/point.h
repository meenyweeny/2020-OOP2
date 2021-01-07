#pragma once
class Point {
public:
	typedef int COOR_T;

	void Print() const; //�б� ����
	Point();
	Point(COOR_T _x, COOR_T _y);
	Point(const Point& pt);

	void setX(COOR_T value) { //������ �ٲ� �� �ִ� ������
		if (value < 0)
			x = 0;
		else if (value > 100)
			x = 100;
		else
			x = value;
	} //class �ȿ��� �����ȰŴϱ� �ڵ����� inline �Լ�

	//private���� ����� ������� ������ �Լ��� ���� �ٲ� �� �ְ� ����
	//�� �޼������ ĸ��ȭ�� �����鿡 �����ϴ� �뵵�� ����
	void setY(COOR_T value);


	COOR_T getX() const { return x; } //���� ������ �뵵
	//�� �Լ� �ȿ����� �������� ������ ���ٴ°� const ���ؼ� �˷���


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

//inline Ű����� �Լ� ȣ��ÿ� �ش� �޼���� �̵��ϴ°� �ƴ϶�
//�� �ڵ带 ���� �����ϰ��ִ� �Լ������� �����´�
//����->���� �ӵ� ó��
//�Լ� ȣ���� �ϰ� ȣ��ÿ� ������ �̿��ϴ� �׷� �������� �� ���� �� �ִ�
//��, �ݴ�� ���Խÿ� ���� ���������� ����⶧����
//�׷��͵��� �ڵ尡 �ʹ� ��� ������ ������ ���� �ִ�

//ª�� �ڵ��� ����� ������ ���� �� ����ϸ� ����
