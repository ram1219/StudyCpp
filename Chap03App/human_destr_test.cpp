#include <stdio.h>
#include <string.h>

class Human {
private:
	char* name;
	int age;

public:
	Human(const char* name, int age) {
		// 포인터 저장공간 할당
		// 마지막 값은 null'\0' 문자가 들어가므로 +1을 한다.
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;

		printf("%s 객체 생성자가 호출되었습니다.\n", this->name);
	}

	// 파괴자 생성
	~Human() {
		printf("%s 객체가 파괴되었습니다.\n", this->name);

		// 위에서 new로 생성한 것을 파괴
		delete[] this->name;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", this->name, this->age);
	}
};

int main() {
	Human woman("김가람", 25);
	woman.intro();

	// 동적 할당
	Human* leo = new Human("레오나르도 디카프리오", 47);
	leo->intro();

	// 파괴자는 따로 입력하지 않아도 자동으로 실행된다.
	// 실행 순서의 반대로 파괴자가 실행된다.
	return 0;
}