#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "cursor.h"

#define PI 3.141592

class Sun {
private:
	const int x, y;
	const char ch;			// ���ڸ� ȭ�鿡 ���
public:
	Sun(int ax, int ay, char ach) : x(ax), y(ay), ch(ach) {}
	// x, y�� ��ġ�� �̵��ؼ� ���� ���
	void Show() {
		gotoxy(x, y); putch(ch);
	}
	// x, y�� ��ġ�� �̵��ؼ� ���� ����
	void Hide() {
		gotoxy(x, y); putch(' ');
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};

class Earth {
private:
	const int r;
	int x, y;
	const char ch;			// ���ڸ� ȭ�鿡 ���
	const Sun* pSun;
public:
	Earth(int ar, char ach, Sun* apSun) :r(ar), ch(ach), pSun(apSun) { ; }

	void Revolve(double angle) {
		Hide();
		x = int(cos(angle * PI / 180) * r * 2);
		y = int(sin(angle * PI / 180) * r);
		Show();
	}
	// x, y�� ��ġ�� �̵��ؼ� ���� ���
	void Show() {
		gotoxy(pSun->GetX() + x, pSun->GetY() + y); 
		putch(ch);
	}
	// x, y�� ��ġ�� �̵��ؼ� ���� ����
	void Hide() {
		gotoxy(pSun->GetX() + x, pSun->GetY() + y);
		putch(' ');
	}
	int GetX() { return x; }
	int GetY() { return y; }
};

int main() {
	Sun S(40, 12, 'S');
	Earth E(10, 'E', &S);

	clrscr();
	showcursor(0);
	S.Show();

	// kbhit() --> Ű���� �Է� �Լ�
	for (double angle = 0; !kbhit(); angle += 10) {
		E.Revolve(angle);
		delay(100);
	}

	showcursor(1);
}