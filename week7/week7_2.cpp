#include<iostream>
using namespace std;

/*
class Point {
public:
	int x, y;
	Point() {
		x = y = 0;
	}
	Point(int _x, int _y) { //������ �����ε�
		x = _x;
		y = _y;
	}
	Point(const Point& pt); //��������� Point(Point& pt); �ε� ����
	//��������ڶ�?
	//�ڽŰ� ������ Ÿ���� ��ü�� ���� ���۷���(����)�� ���ڷ� �޴� ������

	void Print();
};

Point::Point(const Point& pt) {
	cout << "Copy constructor!" << endl;
	x = pt.x;
	y = pt.y;
}
void Point::Print() {
	cout << x << ", " << y << endl;
}

int main() {
	Point p1, p2, p4, p5(200, 150);
	p1.x = 10;
	p1.y = 10;
	p2.x = 20, p2.y = 20;

	Point p6(p1); //��������ڰ� ������

	p5.Print();
	p4.Print();


	Point p3 = p2; //Point(const Point& pt) �����ڰ� �� �������� ����
	//(��������ڰ� ����) (default �����ڴ� ���� x)
	p3.Print();

	p3.y = 500;
	cout << p2.y << endl; //20
	cout << p3.y << endl; //500

	p2.y = 200;
	cout << p2.y << endl; //200
	cout << p3.y << endl; //500


	p3 = p1; //����

	p3.Print();
	p1.Print();
	p2.Print();

}
*/


//=================================

//�ݵ�� �����ڰ� �����ؾ��ϴ� ���
//ex ��������� const �Ӽ� ������ �ְų� ���۷��� Ÿ���� �ִٸ�

/*
class NeedConstructor {
public:
	const int max;
	int & ref;
	//const�� ���۷����� �ݵ�� �ʱ�ȭ�� �Ǿ���Ѵٴ� Ư¡�� �ִ�
	//�׷��� �����ڰ� �ʿ�
	int temp;

	NeedConstructor()
		:max(100),ref(temp) {
		temp = 10;
		//max = 100;
		//ref = temp;
		//��״� �����ڰ� �ҷ����� ������ �ʱ�ȭ�Ǿ����
	}
	NeedConstructor(int cnt, int & number)
		:max(cnt), ref(number) {
		temp = 10;
	}
};

int main() {
	NeedConstructor cr;
	int num = 400;
	NeedConstructor crr(500, num);
	//cr.max = 1000; //����� ���� �Ұ�
	cout << cr.max << endl;
	cout << cr.ref << endl;
	cout << &cr.ref << endl; //ref�� �ּ� (==temp�� �ּ�)
	cout << &cr.temp << endl;

	cout << crr.max << endl;
	cout << crr.ref << endl;
	cout << &crr.ref << endl; //ref�� �ּ� (==num�� �ּ�)
	cout << crr.temp << endl;
	cout << &crr.temp << endl;
	//�ʱ�ȭ�� �޶����ϱ� ref�� temp���� �ּ� ���������
	cout << num << endl;
	cout << &num << endl; //ref�� �ּҰ� ����
}
*/

//=================================

//�Ҹ���
//��ü�� ����� �ڿ��� ���� ����

class DynamicArray {
public:
	int * arr;
	DynamicArray(int arraySize) {
		arr = new int[arraySize]; //���� �޸� �Ҵ�
	}
	~DynamicArray() { //�Ҹ���
		cout << "�Ҹ��� ����" << endl;
		delete[] arr; //�����ؼ� �޸� ���� ����
		arr = NULL; //�Ϻ��ϰ� �ƹ����� ����Ű�� �ʰ� ���� ����
	}
};

int main() {
	int size;
	cout << "�� ���� ���� �Է�? ";
	cin >> size;

	DynamicArray da(size);

	for (int i = 0; i < size; i++)
		cin >> da.arr[i];

	for (int i = size - 1; i >= 0; i--) {
		cout << da.arr[i] << " ";
	}

	cout << endl;

	//main���� ������ ��ü�� �Ҹ��ڴ�
	//main�Լ��� ������ �������� ����ȴ�
	//������ ��ü�� �ش� �Լ��� ����Ǵ� ���ÿ� �Ҹ�ȴ�
	//(�Ҹ��� ���� Ÿ�̹�)

	//�׷��� �Ҹ��ڴ� ����� �ڿ��� �����ϱ⿡ ���� ������ ���
}