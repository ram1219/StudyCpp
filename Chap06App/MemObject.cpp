#include <stdio.h>
#include <string.h>

class Date {
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d/%d/%d", year, month, day); }
};

class Product {
private:
	char name[64];
	char company[32];
	Date validto;
	int price;
public:
	// 입력받은 y, m, d의 값을 바로 validto(Date 클래스)에서 사용
	Product(const char* aname, const char* acompany,
		int y, int m, int d, int aprice) :validto(y, m, d) {
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct() {
		printf("이름 : %s\n", name);
		printf("제조사 : %s\n", company);
		printf("유효기간 : ");
		validto.OutDate();				// Date의 함수를 가져와서 사용
		printf("\n");
		printf("가격 : %d\n", price);
	}
};

int main() {
	Product shrimp("새우깡", "농심", 2020, 8, 15, 1200);
	shrimp.OutProduct();
	return 0;
}