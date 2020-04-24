#include <stdio.h>

class Time {
private:
	int hour, min, sec;
public:
	Time() { ; }
	Time(int h, int m, int s) :hour(h), min(m), sec(s) { ; }

	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}

	// 전체 함수의 const --> 이 멤버함수의 변수는 함수 외부에서 변경 불가
	// const Time& --> 입력받은 값 변경 불가
	const Time AddTime(const Time& other) const {
		Time t;
		t.sec = sec + other.sec;
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;	// 위에서 sec + other.sec의 값이 60초가 넘을 경우
		t.sec %= 60;			
		t.hour += t.min / 60;
		t.min %= 60;

		return t;
	}
};

int main() {
	Time t1(1, 40, 32), t2(2, 21, 33);
	Time t3;
	t1.OutTime();
	t2.OutTime();

	t3 = t1.AddTime(t2);
	t3.OutTime();
}