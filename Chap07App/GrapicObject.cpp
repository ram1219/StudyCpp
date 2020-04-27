#include <stdio.h>

class Shape {
public:
	// draw() ���� ������ �����ϰ�, ������ �� ������ ����� �ȴ�. 
	virtual void draw() = 0; //{ puts("���� ������Ʈ�Դϴ�."); }

	// ���� �����Լ� --> ��ӹ��� �ڽĵ鸸 draw() �Լ��� ����� �� �ִ�. �θ� �Լ��� draw() �Լ��� �������̵��� ���� �ϳ��� Ʋ�� �ȴ�.
	// --> ��ӹ��� ��� Ŭ������ virtual draw()�� ���� �����Լ��� ����ؾ� �Ѵ�. 
};

class Line : public Shape {
public:
	virtual void draw() { puts("���� �߽��ϴ�."); }
};

class Circle : public Shape {
public:
	virtual void draw() { puts("���� �׸��ϴ�."); }
};

class Rect : public Shape {
public:
	virtual void draw() { puts("�簢���� �׸��ϴ�."); }
};

int main() {
	Shape* ar[] = { new Line(), new Circle(), new Rect() };
	printf("ar size : %d, ar[0] size : %d\n", sizeof(ar), sizeof(ar[0]));

	// �θ�Ŭ������ draw()�Լ��� virtual �̹Ƿ� �� �ڽ� �Լ��� ������ �� draw() �Լ��� ����� ��µȴ�. 
	// virtual�� ������� ���� ��� defalut�� �θ� Ŭ������ draw() �Լ��� ��µȴ�.
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) { ar[i]->draw(); }

	// �Ҵ� �� ���� ����
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) { delete ar[i]; }
}