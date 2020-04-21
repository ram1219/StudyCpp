#include <stdio.h>
#include <String.h>

class Human {
private:
    char name[12];
    int age;

public:
    // 생성자
    Human(const char* aname, int aage) {
        strcpy(name, aname);
        age = aage;
    }

    void intro() {
        printf("이름 %s, 나이 %d\n", name, age);
    }
};

int main() {
    Human h = Human("김가람", 25);
    h.intro();

    return 0;
}