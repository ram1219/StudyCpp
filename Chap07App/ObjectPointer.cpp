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
		printf("�̸� %s, ���� %d\n", name, age);
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
		printf("%d�й� %s�Դϴ�.\n", stunum, name);
	}
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

int main() {
	Human Kim("�谡��", 25);
	Student Yeo("������", 15, 20151234);
	Human* pH;
	Student* pS;

	pH = &Kim;		// name(�谡��), age(25) 
	pH->intro();
	pS = &Yeo;		// name(������), age(15), stunum(20151234)
	pS->intro();
	pH = &Yeo;		// name(�谡��), age(25) <= name(������), age(15), stunum(20151234)
	pH->intro();
	// pS = &Kim;	// name(������), age(15), stunum(20151234) <= name(�谡��), age(25), stunum(????????)
}