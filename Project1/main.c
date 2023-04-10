#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Player {
	int hp;
	int atk;
	int is_sand;
}Player;

int RandomNumber(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

int luffy_turn(Player* luffy, Player* crocodile) {
	int action;

	printf("==========루피 차례==========\n");
	while (1) {
		printf("1. 공격 !\n2. 기 모으기\n=========================\n");
		printf("\n루피가 할 행동을 선택하세요(1 or 2) >>>> ");
		if (scanf("%d", &action) != 1 || (action != 1 && action != 2)) { // 입력값 예외 처리
			printf("\n");
			while (getchar() != '\n'); // 입력 버퍼 비우기
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
			continue;
		}
		break;

		switch (action) {
		case 1:
			printf("\n루피의 공격 : '고무고무 총!'\n");
			if (crocodile->is_sand == 1) {
				crocodile->hp -= luffy->atk / 2;
			}
			else {
				crocodile->hp -= luffy->atk;
			}
			break;
		case 2:
			printf("\n루피가 기를 모으고 있습니다.....\n");
			break;
		}
	}
}

	int crocodile_turn(Player * luffy, Player * crocodile) {
		int action = RandomNumber(1, 3);

		printf("\n==========크로커다일 차례==========\n");
		switch (action) {
		case 1:
			printf("크로커다일의 공격: '사막의 폭풍!'\n\n");
			luffy->hp -= crocodile->atk;
			break;
		case 2:

			printf("크로커다일이 몸을 모래로 바꿉니다.'\n\n");
			crocodile->is_sand = 1;
			break;
		case 3:
			printf("크로커다일은 여유를 부립니다:'니가 칠무해가 뭔지 알어?!'\n\n");
			break;
		}
	}

int game(int turn, Player* luffy, Player* crocodile) {
	while (1) {
		if (turn == 1) {
			luffy_turn(luffy, crocodile);
			
		}
	}
}

int main(void) {
	// intro
	printf("===============한피스 시작===============\n");
	printf("해적왕이 될 사나이 루피는 \n고잉 메리호를 타고 길을 떠난다.\n\n바다를 떠돌던 중\n칠무해 크로커다일을 만나 전투가 벌어지는데...\n강적을 만난 루피!\n과연 이길 수 있을 것인가?\n두둥!\n\n");
	
	printf("Press <Enter> to continue...\n\n");
	getchar();

	srand(time(NULL));

	Player luffy = { RandomNumber(20, 40), RandomNumber(5,15) };
	Player crocodile = { RandomNumber(30, 50), RandomNumber(15,25) };

	printf("Luffy      HP: %d, 공격력: %d\n", luffy.hp, luffy.atk);
	printf("Crocodile  HP: %d, 공격력: %d\n", crocodile.hp, crocodile.atk);
	
	int turn = 1;
	
	game(turn, &luffy, &crocodile);

	return 0;
}