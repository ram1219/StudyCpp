#include <stdio.h>


class Util {
public:
	template<typename T>
	void Swap(T& a, T& b) {
		T t;
		t = a; a = b; b = t;
	}
};

/*template <typename T>
void Swap(T& a, T& b) {
	int t;
	t = a; a = b; b = t;
}*/

//void Swap(double& a, double& b) {
//	double t;
//	t = a; a = b; b = t;
//}

int main() {
	Util u;

	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	u.Swap(a, b);
	u.Swap(c, d);
	u.Swap(e, f);

	printf("a = %d, b = %d\n", a, b);
	printf("c = %.1lf, d = %.1lf\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}