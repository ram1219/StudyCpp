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
		printf("�̸� %s, ���� %d\n", name, age);
	}
};

// Student Ŭ������ Human Ŭ������ ��ӹ���
class Student : public Human {
private:
	int stunum;
public:
	// ��ӹ��� Human�� �����ڸ� ���� �� �״�� �ʱ�ȭ�Ѵ�.
	Student(const char* aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}

	// ���� ����.
	// Student(const char* aname, int aage, int astunum) : Human(aname, aage), stunum(astumun){}
	
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
	void report() {
		printf("%d�й� ����Ʈ ����\n", stunum);
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
		printf("%s�� �����ϰ� ���� ����\n", thesis);
	}
};

int main() {
	Human Kim("�谡��", 25);
	Kim.intro();

	Student Yeo("������", 25, 10);
	Yeo.intro();
	Yeo.study();
	Yeo.report();
}