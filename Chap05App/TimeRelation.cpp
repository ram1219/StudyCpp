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
	bool operator ==(const Time& other) const {
		return (hour == other.hour && min == other.min && sec == other.sec);
	}
	bool operator !=(const Time& other) const {
		return !(*this == other);
	}
	bool operator >(const Time& other) const {
		/*Time t = *this;
		int left, right;
		left = t.hour * 3600 + t.min * 60 + t.sec;
		right = other.hour * 3600 + other.min * 60 + other.sec;

		if (left > right) { return true; }
		else return false;*/

		if (hour > other.hour)return true;
		if (hour < other.hour)return false;
		if (min > other.min)return true;
		if (min < other.min)return false;
		if (sec > other.sec)return true;
		if (sec < other.sec)return false;
	}
	bool operator <(const Time& other)const {
		return !(*this > other);
	}
	bool operator >=(const Time& other)const {
		return (*this == other || *this > other);
	}
	bool operator <=(const Time& other)const {
		return !(*this >= other);
	}
};

int main() {
	Time t1(15, 16, 56);
	Time t2(!5, 16, 56);
	Time t3(17, 30, 0);

	(t1 != t2) ? printf("두 시간은 다르다.\n") : printf("두 시간은 같다.\n");
}