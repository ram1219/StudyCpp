#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "cursor.h"

class Point {
protected:
	int x, y;
	char ch;
public:
	Point(int ax, int ay, char ach) { x = ax; y = ay; ch = ach; }
	virtual void show() { gotoxy(x, y); putch(ch); }
	virtual void hide() { gotoxy(x, y); putch(' '); }
	void move(int nx, int ny){
		hide();
		x = nx;
		y = ny;
		show();
	}
};

class Circle : public Point {
protected:
	int radius;
public:
	Circle(int ax, int ay, char ach, int aradius) : Point(ax, ay, ach) {
		radius = aradius;
	}
	void show() { gotoxy(radius * x, radius * y); putch(ch); }
	void hide() { gotoxy(radius * x, radius * y); putch(' '); }
};

int main() {
	Point p(1, 1, 'P');					// P의 위치 : (1, 1)
	Circle c(5, 5, 'C', 2);

	p.show();
	c.show();

	getch();							// 키보드 입력 받기(아무키)
	p.move(40, 1);						// P의 위치 : (40, 1,)
	c.move(6, 6);
	getch();
}