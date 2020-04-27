#include <stdio.h>
#include <conio.h>

class Date {
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d/%d/%d", year, month, day); }
};

class Time {
protected:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() { printf("%d:%d:%d", hour, min, sec); }
};

// Date와 Time을 다중 상속 받는 클래스 생성
class DateTime : public Date, public Time {
private:
	bool bEngMessage;
	int millisec;
public:
	// DateTime 생성자 초기화
	DateTime(int y, int M, int d, int h, int m, int s, int ms, bool b = false) :
		Date(y, M, d), Time(h, m, s), millisec(ms), bEngMessage(b) { ; }
	void OutNow() {
		printf(bEngMessage ? "Now is " : "지금은 ");
		OutDate();
		putch(' ');
		OutTime();
		printf(".%d", millisec);
		puts(bEngMessage ? "." : "입니다.");
	}
};

int main() {
	DateTime now(2020, 4, 24, 14, 6, 23, 184, true);	// 영문출력
	DateTime Know(2020, 4, 24, 14, 6, 23, 184, false);	// 한글출력
	now.OutNow();
	Know.OutNow();

	return 0;
}