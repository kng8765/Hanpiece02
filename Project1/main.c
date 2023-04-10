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

	printf("==========���� ����==========\n");
	while (1) {
		printf("1. ���� !\n2. �� ������\n=========================\n");
		printf("\n���ǰ� �� �ൿ�� �����ϼ���(1 or 2) >>>> ");
		if (scanf("%d", &action) != 1 || (action != 1 && action != 2)) { // �Է°� ���� ó��
			printf("\n");
			while (getchar() != '\n'); // �Է� ���� ����
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			continue;
		}
		break;

		switch (action) {
		case 1:
			printf("\n������ ���� : '���� ��!'\n");
			if (crocodile->is_sand == 1) {
				crocodile->hp -= luffy->atk / 2;
			}
			else {
				crocodile->hp -= luffy->atk;
			}
			break;
		case 2:
			printf("\n���ǰ� �⸦ ������ �ֽ��ϴ�.....\n");
			break;
		}
	}
}

	int crocodile_turn(Player * luffy, Player * crocodile) {
		int action = RandomNumber(1, 3);

		printf("\n==========ũ��Ŀ���� ����==========\n");
		switch (action) {
		case 1:
			printf("ũ��Ŀ������ ����: '�縷�� ��ǳ!'\n\n");
			luffy->hp -= crocodile->atk;
			break;
		case 2:

			printf("ũ��Ŀ������ ���� �𷡷� �ٲߴϴ�.'\n\n");
			crocodile->is_sand = 1;
			break;
		case 3:
			printf("ũ��Ŀ������ ������ �θ��ϴ�:'�ϰ� ĥ���ذ� ���� �˾�?!'\n\n");
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
	printf("===============���ǽ� ����===============\n");
	printf("�������� �� �糪�� ���Ǵ� \n���� �޸�ȣ�� Ÿ�� ���� ������.\n\n�ٴٸ� ������ ��\nĥ���� ũ��Ŀ������ ���� ������ �������µ�...\n������ ���� ����!\n���� �̱� �� ���� ���ΰ�?\n�ε�!\n\n");
	
	printf("Press <Enter> to continue...\n\n");
	getchar();

	srand(time(NULL));

	Player luffy = { RandomNumber(20, 40), RandomNumber(5,15) };
	Player crocodile = { RandomNumber(30, 50), RandomNumber(15,25) };

	printf("Luffy      HP: %d, ���ݷ�: %d\n", luffy.hp, luffy.atk);
	printf("Crocodile  HP: %d, ���ݷ�: %d\n", crocodile.hp, crocodile.atk);
	
	int turn = 1;
	
	game(turn, &luffy, &crocodile);

	return 0;
}