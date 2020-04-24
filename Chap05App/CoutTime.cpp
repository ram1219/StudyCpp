#include <iostream>
using namespace std;

class Time {
	friend ostream& operator << (ostream& c, const Time& T);
	friend ostream& operator << (ostream& c, const Time* pT);
private:
	int hour, min, sec;
public:
	Time();
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() const {
		printf("%d:%d:%d\n", hour, min, sec);
	}
};

// 연산자 오버로딩 --> << 연산자를 사용한 경우 실행되는 함수
// ostream 은 입출력을 위한 자료형이다.
ostream& operator << (ostream& c, const Time& T) {
	c << T.hour << ":" << T.min << ":" << T.sec;
	return c;
}
// 포인터를 사용한 경우 
ostream& operator << (ostream& c, const Time* pT) {
	c << pT->hour << ":" << pT->min << ":" << pT->sec;
	//c << *pT;	// 위 함수의 내용을 가져온다.
	return c;
}

int main() {
	Time now(10, 22, 5);
	Time* pLunchTime = new Time(12, 30, 0);

	cout << "현재 시간은" << now << "입니다" << endl;
	cout << "점심 시간은" << pLunchTime << "입니다" << endl;

	delete pLunchTime;
}