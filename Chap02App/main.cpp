#include <stdio.h>
#include "Time.h"
#include "Date.h"


int main() {

	Date d;
	Time now;

	d.SetDate(2020, 04, 20);
	d.OutDate();

	printf("Size of Date = %d\n", sizeof(d));  // Ŭ������ ������ �ִ� ������ ũ�� 
											   // int�� 3������ ������ �����Ƿ� ������� 12�� �ȴ�.

	now.SetTime(15, 54, 20);
	now.outTime();

	printf("Size of Time = %d\n", sizeof(now));

	return 0;
}