#include <stdio.h>
#include <String.h>

class Human {
private:
    char name[12];
    int age;

public:
    // ������
    Human(const char* aname, int aage) {
        strcpy(name, aname);
        age = aage;
    }

    void intro() {
        printf("�̸� %s, ���� %d\n", name, age);
    }
};

int main() {
    Human h = Human("�谡��", 25);
    h.intro();

    return 0;
}