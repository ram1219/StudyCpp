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

	// ���ø����� ������ �ڷ������� T(T a, T b)�� �����߱� ������ max �Լ��� �� ������ �ڷ����� ���ƾ� �Ѵ�.
	//int c = max(2, 3.14);
	double c = max(double(2), 3.14);			// �ڷ��� ��ȯ�� ����Ͽ� �� �ڷ����� ���� �����.
	printf("c = %d\n", c);

	int d = max(2, int(3.14));
}