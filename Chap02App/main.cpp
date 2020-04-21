#include <stdio.h>
#include "Time.h"
#include "Date.h"


int main() {

	Date d;
	Time now;

	d.SetDate(2020, 04, 20);
	d.OutDate();

	printf("Size of Date = %d\n", sizeof(d));  // 클래스가 가지고 있는 변수의 크기 
											   // int형 3가지의 변수를 가지므로 사이즈는 12가 된다.

	now.SetTime(15, 54, 20);
	now.outTime();

	printf("Size of Time = %d\n", sizeof(now));

	return 0;
}