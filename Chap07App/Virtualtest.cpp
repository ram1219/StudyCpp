#include <stdio.h>					// C
#include <string.h>
#include <iostream>					// C++ 
using namespace std;

// Human Ŭ���� ����
class Human {
// private --> �ڽ� Ŭ�������� ��� �Ұ���, protected --> �ڽ� Ŭ�������� ��Ӱ��� 
protected:
	char name[12];		// �̸�
	int age;			// ����
public:
	// Human Ŭ���� ������
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	// ����Լ�
	// virtual�� ������ intro() �Լ��� �ٸ��� ������ �Ǿ� ����� �����ϴ�. 
	virtual void intro() { printf("%s��(��) %d���Դϴ�.\n", name, age); }
};

// HumanŬ������ ��ӹ��� Student Ŭ���� ����
class Student : public Human {
protected:
	int stunum;			// �й�
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {	 // Human Ŭ�������� ��ӹ��� �Ӽ��鿡 �� �ٷ� �Է�
		stunum = astunum;														 // stunum �� �Է�
	}
	void intro() { printf("%d��, %s�Դϴ�.\n", stunum, name); }					 // intro()�Լ� ������
};

int main() {
	Human h("������", 25);						// Human Ŭ���� ���� �� �ʱ�ȭ
	Student s("���Ͽ�", 28, 20130427);
	
	// �������̵� --> ������ : �θ� Ŭ�������� �ڽ� Ŭ������ �Լ��� ����ϰ� ���� ���
	Human* pH;
	Student* pS;

	printf("Human Size : %d, Student Size : %d\n", sizeof(h), sizeof(s));

	pH = &h;									// ������ �����̹Ƿ� Ŭ������ �ּҰ�(�ּ��� ���� ó���κ�)�� ����
	pH->intro();

	// �θ� �����Ϳ� �ڽ� Ŭ������ �ּҸ� �� ���, �ڽ��� ������ �� ���� �ڽ��� intro() �Լ��� �ƴ� �θ��� intro()�Լ��� ����Ѵ�.
	// �θ� Ŭ������ �Լ��� virtual�� ���� --> �ڽ��� �����Ǵ� ������ ��� ���� �ִ��� �ڽ��� �Լ��� ����� �� �ִ�. 
	pH = &s;									
	pH->intro();

	// pS = &h;									// �ݴ��� ���� �����̵��� �ʴ´�.

	int sel = 0;								// �Է¹��� ���� ������ ���� ���� �� �ʱ�ȭ
	while (true) {
		cout << "���ϴ� ���� ������(1:Human, 2:Student, 9:exit) ";
		cin >> sel;

		if (sel == 1) { pH = &h; pH->intro(); }
		else if (sel == 2) { pH = &s; pH->intro(); }
		else if (sel == 9) { printf("�����մϴ�\n");  exit(-1); }		// ���α׷� ����
		else { printf("�ٸ� ���� �Է����ּ���\n"); }
	}
}