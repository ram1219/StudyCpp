#include <stdio.h>
#include <string.h>

class Human {
private:
	char name[12];
	int age;
public:
	Human(const char* aname,int aage){
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("이름 %s, 나이 %d\n", name, age);
	}
};

// Student 클래스가 Human 클래스를 상속받음
class Student : public Human {
private:
	int stunum;
public:
	// 상속받은 Human의 생성자를 원래 값 그대로 초기화한다.
	Student(const char* aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}

	// 위와 같다.
	// Student(const char* aname, int aage, int astunum) : Human(aname, aage), stunum(astumun){}
	
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
	void report() {
		printf("%d학번 레포트 제출\n", stunum);
	}
};

class Graduate :public Student {
protected:
	char thesis[40];
public:
	Graduate(const char* aname, int aage, int astunum, const char* athesis) :
		Student(aname, aage, astunum) {
		strcpy(thesis, athesis);
	}
	void research() {
		printf("%s를 연구하고 논문을 쓴다\n", thesis);
	}
};

int main() {
	Human Kim("김가람", 25);
	Kim.intro();

	Student Yeo("여예지", 25, 10);
	Yeo.intro();
	Yeo.study();
	Yeo.report();
}