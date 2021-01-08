//�������� �����Լ�

#include<iostream>
using namespace std;

class Shape {
public:
	Shape() {
		_x = _y = 0.0;
	}
	Shape(double x, double y) {
		_x = x;
		_y = y;
	}
	void Move(double x, double y) {
		_x = x;
		_y = y;
	}
	virtual void Draw() const { //�б� ���� const method
						//_x,_y ���� �Ժη� �ٲ� �� ����
		cout << "[Shape] Position = ( " << _x << ", " << _y << " )\n";
	}

protected:
	double _x, _y;
};

class Rectangle : public Shape {
public:
	Rectangle() {
		_width = _height = 100.0f;
	}
	Rectangle(double x, double y, double width, double height)
		: Shape(x, y) { //�ʱ�ȭ ����Ʈ ���, �θ�Ŭ������ ������ ȣ��
		Resize(width, height);
	}
	void Draw() const { //�޼��� �������̵�
		cout << "[Rectangle] Position = ( " << _x << ", " << _y << " ) ";
		cout << "Size = ( " << _width << ", " << _height << " ) \n";
	}
	void Resize(double width, double height) {
		_width = width;
		_height = height;
	}

protected:
	double _width;
	double _height;
};

class Circle : public Shape {
public:
	Circle() {
		_radius = 100.0f;
	}
	Circle(double x, double y, double radius)
		: Shape(x, y) { //�θ�Ŭ������ Shape �����ڸ� �����Ŵ (�ʱ�ȭ ����Ʈ)
		SetRadius(radius); //Circle class ���� �޼���
	}
	void Draw() const {
		cout << "[Circle] Position = ( " << _x << ", " << _y << " ) ";
		cout << "Radius = " << _radius << "\n";
	}
	void SetRadius(double radius) {
		_radius = radius;
	}

protected:
	double _radius;
};

int main() {

	//������ �Ǵ� �ڵ�

	Shape * shapes[5] = { NULL }; //ũ�� 5�� ������ �迭�� ����

	//�����Ҵ�
	//�θ�Ŭ������ �����ͷ� ��Ӱ����� �ڽ� Ŭ�������� Ÿ������ ���� �Ҵ�
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);


	for (auto i = 0; i < 5; i++)
		shapes[i]->Draw();
	//���� Circle,Rectangle ��� �����Ҵ��� ����µ� Shape�� Draw�� �������
	//�θ������ͷ� �ڽ��� �ּҸ� �޾��� �� �θ� ���� �޼��尡 �������
	//���� Circle, Rectangle�� Draw�� ��������� ���ڴµ� ��� �ذ��ұ�?

	//�� �ϳ��� Ű����� �ذ� ����
	//������ Shape class�� Draw �Լ� �տ� virtual Ű���� ������ �ȴ�
	//�� Ű����� ������ �ڽ�Ŭ������ �´� Draw�� �����ϰ� �ȴ�

	for (auto i = 0; i < 5; i++) {
		delete shapes[i];
		shapes[i] = NULL;
	}
}