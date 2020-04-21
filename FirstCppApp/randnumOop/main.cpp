#include <stdio.h>			// 표준 라이브러리
#include "cursor.h"			// 생성 헤더파일

class RandNum
{
private:
	int num;

public:
	RandNum() { randomize(); }
	void Generate() { num = random(100) + 1; }		// 임의의 랜덤변수 생성
	BOOL Compare(int input) {
		if (input == num) {
			printf("맞췄습니다.\n");
			return TRUE;
		}
		else if (input > num) {
			printf("입력한 숫자보다 더 작습니다.\n");
		}
		else {
			printf("입력한 숫자보다 더 큽니다.\n");
		}
		return FALSE;
	}
};

class Ask
{
private:
	int input;

public:
	void Prompt() { printf("\n제가 만든 숫자를 맞춰 보세요.\n"); }
	BOOL AskNumber() {
		printf("숫자를 입력하세요(끝낼 때는 999) : ");
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
	// 클래스 선언
	RandNum R;		// main함수에서 사용 할 RandNum 클래스의 명칭을 R로 지정
	Ask A;

	// 무한루프
	for (;;) {
		R.Generate();   // 클래스 RandNum 안의 Generate 메서드 사용 --> 랜덤 변수 생성
		A.Prompt();		// 클래스 Ask 안의 Prompt 메서드 사용 --> 숫자를 맞춰 보세요 출력

		// 무한 루프
		for (;;) {
			if (A.AskNumber()) {	// 999를 입력받은 경우
				exit(0);
			}
			if (R.Compare(A.GetInput())) { // 입력받은 값이 랜덤 수와 같은 경우
				break;
			}
		}
	}
}


