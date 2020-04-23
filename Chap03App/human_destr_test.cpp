#include <stdio.h>
#include <string.h>

class Human {
private:
	char* name;
	int age;

public:
	Human(const char* name, int age) {
		// ������ ������� �Ҵ�
		// ������ ���� null'\0' ���ڰ� ���Ƿ� +1�� �Ѵ�.
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;

		printf("%s ��ü �����ڰ� ȣ��Ǿ����ϴ�.\n", this->name);
	}

	// �ı��� ����
	~Human() {
		printf("%s ��ü�� �ı��Ǿ����ϴ�.\n", this->name);

		// ������ new�� ������ ���� �ı�
		delete[] this->name;
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", this->name, this->age);
	}
};

int main() {
	Human woman("�谡��", 25);
	woman.intro();

	// ���� �Ҵ�
	Human* leo = new Human("���������� ��ī������", 47);
	leo->intro();

	// �ı��ڴ� ���� �Է����� �ʾƵ� �ڵ����� ����ȴ�.
	// ���� ������ �ݴ�� �ı��ڰ� ����ȴ�.
	return 0;
}