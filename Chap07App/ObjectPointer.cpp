#include <stdio.h>
#include <string.h>

class Human {
protected:
	char name[12];
	int age;
public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("이름 %s, 나이 %d\n", name, age);
	}
};

class Student : public Human {
protected:
	int stunum;
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int main() {
	Human Kim("김가람", 25);
	Student Yeo("여예지", 15, 20151234);
	Human* pH;
	Student* pS;

	pH = &Kim;		// name(김가람), age(25) 
	pH->intro();
	pS = &Yeo;		// name(여예지), age(15), stunum(20151234)
	pS->intro();
	pH = &Yeo;		// name(김가람), age(25) <= name(여예지), age(15), stunum(20151234)
	pH->intro();
	// pS = &Kim;	// name(여예지), age(15), stunum(20151234) <= name(김가람), age(25), stunum(????????)
}