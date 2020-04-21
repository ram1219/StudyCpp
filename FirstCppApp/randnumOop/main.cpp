#include <stdio.h>			// ǥ�� ���̺귯��
#include "cursor.h"			// ���� �������

class RandNum
{
private:
	int num;

public:
	RandNum() { randomize(); }
	void Generate() { num = random(100) + 1; }		// ������ �������� ����
	BOOL Compare(int input) {
		if (input == num) {
			printf("������ϴ�.\n");
			return TRUE;
		}
		else if (input > num) {
			printf("�Է��� ���ں��� �� �۽��ϴ�.\n");
		}
		else {
			printf("�Է��� ���ں��� �� Ů�ϴ�.\n");
		}
		return FALSE;
	}
};

class Ask
{
private:
	int input;

public:
	void Prompt() { printf("\n���� ���� ���ڸ� ���� ������.\n"); }
	BOOL AskNumber() {
		printf("���ڸ� �Է��ϼ���(���� ���� 999) : ");
		scanf("%d", &input);
		if (input == 999) {
			return TRUE;
		}
		return FALSE;
	}
	int GetInput() { return input; }
};

int main()
{
	// Ŭ���� ����
	RandNum R;		// main�Լ����� ��� �� RandNum Ŭ������ ��Ī�� R�� ����
	Ask A;

	// ���ѷ���
	for (;;) {
		R.Generate();   // Ŭ���� RandNum ���� Generate �޼��� ��� --> ���� ���� ����
		A.Prompt();		// Ŭ���� Ask ���� Prompt �޼��� ��� --> ���ڸ� ���� ������ ���

		// ���� ����
		for (;;) {
			if (A.AskNumber()) {	// 999�� �Է¹��� ���
				exit(0);
			}
			if (R.Compare(A.GetInput())) { // �Է¹��� ���� ���� ���� ���� ���
				break;
			}
		}
	}
}


