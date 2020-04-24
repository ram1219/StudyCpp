#include <stdio.h>

class Time {
	friend const Time operator+(const Time& me, const Time& other);
private:
	int hour, min, sec;
public:
	Time() { ; }
	Time(int h, int m, int s) :hour(h), min(m), sec(s) { ; }

	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}

};

// 전역 연산자 오버로딩
const Time operator +(const Time& me, const Time& other) {
	Time t;
	t.sec = me.sec + other.sec;
	t.min = me.min + other.min;
	t.hour = me.hour + other.hour;

	t.min += t.sec / 60;	// 위에서 sec + other.sec의 값이 60초가 넘을 경우
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;

	return t;
}

int main() {
	Time t1(1, 40, 32), t2(2, 21, 33);
	Time t3;
	t1.OutTime();
	t2.OutTime();

	// 연산자 오버로딩 사용, +가 위 함수형식으로 사용된다. 
	t3 = t1 + t2;
	t3.OutTime();
}