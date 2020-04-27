#include <stdio.h>

class Shape {
public:
	// draw() 값이 재정의 가능하고, 재정의 된 값으로 출력이 된다. 
	virtual void draw() = 0; //{ puts("도형 오브젝트입니다."); }

	// 순수 가상함수 --> 상속받은 자식들만 draw() 함수를 사용할 수 있다. 부모 함수의 draw() 함수는 오버라이딩을 위한 하나의 틀이 된다.
	// --> 상속받은 모든 클래스는 virtual draw()로 순수 가상함수를 사용해야 한다. 
};

class Line : public Shape {
public:
	virtual void draw() { puts("선을 긋습니다."); }
};

class Circle : public Shape {
public:
	virtual void draw() { puts("원을 그립니다."); }
};

class Rect : public Shape {
public:
	virtual void draw() { puts("사각형을 그립니다."); }
};

int main() {
	Shape* ar[] = { new Line(), new Circle(), new Rect() };
	printf("ar size : %d, ar[0] size : %d\n", sizeof(ar), sizeof(ar[0]));

	// 부모클래스의 draw()함수가 virtual 이므로 각 자식 함수의 재정의 된 draw() 함수의 결과가 출력된다. 
	// virtual을 사용하지 않을 경우 defalut로 부모 클래스의 draw() 함수가 출력된다.
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) { ar[i]->draw(); }

	// 할당 된 공간 삭제
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) { delete ar[i]; }
}