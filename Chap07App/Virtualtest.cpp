#include <stdio.h>					// C
#include <string.h>
#include <iostream>					// C++ 
using namespace std;

// Human 클래스 생성
class Human {
// private --> 자식 클래스에서 상속 불가능, protected --> 자식 클래스에서 상속가능 
protected:
	char name[12];		// 이름
	int age;			// 나이
public:
	// Human 클래스 생성자
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	// 출력함수
	// virtual로 지정된 intro() 함수는 다르게 재정의 되어 사용이 가능하다. 
	virtual void intro() { printf("%s은(는) %d살입니다.\n", name, age); }
};

// Human클래스를 상속받은 Student 클래스 생성
class Student : public Human {
protected:
	int stunum;			// 학번
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {	 // Human 클래스에서 상속받은 속성들에 값 바로 입력
		stunum = astunum;														 // stunum 값 입력
	}
	void intro() { printf("%d번, %s입니다.\n", stunum, name); }					 // intro()함수 재정의
};

int main() {
	Human h("여예지", 25);						// Human 클래스 선언 및 초기화
	Student s("이하영", 28, 20130427);
	
	// 오버라이딩 --> 재정의 : 부모 클래스에서 자식 클래스의 함수를 사용하고 싶을 경우
	Human* pH;
	Student* pS;

	printf("Human Size : %d, Student Size : %d\n", sizeof(h), sizeof(s));

	pH = &h;									// 포인터 변수이므로 클래스의 주소값(주소의 제일 처음부분)을 전달
	pH->intro();

	// 부모 포인터에 자식 클래스의 주소를 준 경우, 자식은 재정의 해 놓은 자신의 intro() 함수가 아닌 부모의 intro()함수를 사용한다.
	// 부모 클래스의 함수를 virtual로 지정 --> 자식은 참조되는 공간이 어느 곳에 있던지 자신의 함수를 사용할 수 있다. 
	pH = &s;									
	pH->intro();

	// pS = &h;									// 반대인 경우는 실행이되지 않는다.

	int sel = 0;								// 입력받은 수를 저장할 변수 선언 및 초기화
	while (true) {
		cout << "원하는 수를 고르세요(1:Human, 2:Student, 9:exit) ";
		cin >> sel;

		if (sel == 1) { pH = &h; pH->intro(); }
		else if (sel == 2) { pH = &s; pH->intro(); }
		else if (sel == 9) { printf("종료합니다\n");  exit(-1); }		// 프로그램 종료
		else { printf("다른 수를 입력해주세요\n"); }
	}
}