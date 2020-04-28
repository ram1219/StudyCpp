#include <stdio.h>

template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

template <typename T>
T Add(T& a, T& b) {
	return a + b;
}

int main() {
	int a = max(1, 2);
	double b = max(1.1, 2.2);

	// 템플릿에서 변수의 자료형으로 T(T a, T b)를 선언했기 때문에 max 함수의 두 변수의 자료형은 같아야 한다.
	//int c = max(2, 3.14);
	double c = max(double(2), 3.14);			// 자료형 변환을 사용하여 두 자료형이 같게 만든다.
	printf("c = %d\n", c);

	int d = max(2, int(3.14));
}