#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Sleep(), system("cls") 등의 함수 사용
#include "game_state.h"
#include "common.h"
#include "util.h"
#include "anime.h"




GameState handleMainMenu(void) { //시작 메뉴
	int choice;
	system("cls");
	printTitleDisplay();
	printf("\n");
	printf("========================================================================================================================\n\n");
	printf("                                                     [1] 새 게임\n");
	printf("                                                     [2] 이어하기\n");
	printf("                                                     [3] 게임 종료\n\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
	printf("선택(1, 2, 3)-> ");

	choice = getChoice(1, 3);

	switch (choice) {
	case 1:
		return STATE_NEW_GAME_SLOTS; // '새 게임' 상태로 전환
	case 2:
		return STATE_LOAD_GAME_SLOTS; // '이어하기' 상태로 전환
	case 3:
		return STATE_EXIT;           // '게임 종료' 상태로 전환
	}
	return STATE_MAIN_MENU; // 혹시 모를 예외 발생 시 메인 메뉴로
}
GameState handleNewGameSlots(Player* players[], Player** currentPlayer) {//세이브 데이터 선택 메뉴
	int choice;

	system("cls");
	printf("========================================================================================================================\n\n");
	printf("                                                  새 게임 슬롯 선택\n\n");


	for (int i = 0; i < MAX_SAVE_SLOTS; i++) {
		printf("                                       [%d] ", i + 1);
		if (players[i]->accountDetect == 1) {
			// 캐릭터가 있다면 이름과 레벨을 보여줍니다.
			printf("슬롯 %d: %s (Lv.%d)\n", i + 1, players[i]->playerStats.name, players[i]->playerStats.level);
		}
		else {
			printf("슬롯 %d: 비어 있음\n", i + 1);
		}
	}
	printf("\n                                       [%d] 메인 메뉴로 돌아가기\n\n", MAX_SAVE_SLOTS + 1);
	printf("========================================================================================================================\n\n");
	printf("어떤 슬롯에 캐릭터를 생성하시겠습니까? -> ");

	choice = getChoice(1, MAX_SAVE_SLOTS + 1);

	if (choice == MAX_SAVE_SLOTS + 1) {
		return STATE_MAIN_MENU; // '뒤로가기' 선택
	}

	Player* selected_player = players[choice - 1]; // 선택된 슬롯의 플레이어 포인터
	*currentPlayer = selected_player;

	if (selected_player->accountDetect == 1) {
		printf("\n이미 캐릭터가 존재합니다. 덮어쓰고 새로 생성할까요? (0: 아니오, 1: 예) -> ");
		int overwrite_choice = getChoice(0, 1);
		if (overwrite_choice == 0) {
			return STATE_NEW_GAME_SLOTS; // '아니오' 선택 시, 슬롯 선택 화면으로 다시 돌아갑니다.
		}
	}

	// 캐릭터 생성 과정 진행
	showIntroAnime();
	createNewPlayer(*currentPlayer);

	return STATE_IN_GAME; // 캐릭터 생성이 완료되면 인게임 상태로 전환
}

void createNewPlayer(Player* ptrPlayer) {
	system("cls");
	printf("========================================================================================================================\n\n");
	printf("                                                 새로운 용사의 탄생\n\n");
	printf("========================================================================================================================\n\n");

	// 1. 이름 입력받기
	printf("당신의 이름은 무엇입니까? : ");
	scanf_s(" %s", ptrPlayer->playerStats.name, 49); // 버퍼 오버플로우를 막기 위해 크기 지정
	while (getchar() != '\n' && getchar() != EOF); // 입력 버퍼 비우기

	// 2. 직업 선택하기
	printf("\n어떤 운명을 따르시겠습니까?\n");
	printf("[1] 전사 (Warrior) - 강인한 체력과 힘\n");
	printf("[2] 마법사 (Mage) - 강력한 마법의 지배자\n");
	printf("[3] 궁수 (Archer) - 날렵한 몸놀림의 명사수\n");
	printf("직업 선택 -> ");
	int job_choice = getChoice(1, 3);
	ptrPlayer->job = (CharacterClass)job_choice;

	// 3. 공통 초기값 설정
	ptrPlayer->playerStats.level = 1;
	ptrPlayer->gold = 100; // 초기 자금
	ptrPlayer->exp = 0;
	ptrPlayer->requiredExp = 100; // 레벨업에 필요한 경험치 (예시)

	// 4. 직업에 따른 초기 스탯 설정
	switch (ptrPlayer->job) {
	case WARRIOR:
		ptrPlayer->playerStats.element = NONE; // 전사는 기본 무속성
		ptrPlayer->playerStats.maxHp = 150;
		ptrPlayer->playerStats.maxMp = 30;
		ptrPlayer->playerStats.Strength = 15;
		ptrPlayer->playerStats.Intelligence = 5;
		ptrPlayer->playerStats.Defense = 10;
		ptrPlayer->playerStats.MagicDefense = 5;
		break;
	case MAGE:
		ptrPlayer->playerStats.element = FIRE; // 예시로 마법사는 불 속성
		ptrPlayer->playerStats.maxHp = 80;
		ptrPlayer->playerStats.maxMp = 100;
		ptrPlayer->playerStats.Strength = 5;
		ptrPlayer->playerStats.Intelligence = 15;
		ptrPlayer->playerStats.Defense = 5;
		ptrPlayer->playerStats.MagicDefense = 10;
		break;
	case ARCHER:
		ptrPlayer->playerStats.element = GRASS; // 예시로 궁수는 풀 속성
		ptrPlayer->playerStats.maxHp = 100;
		ptrPlayer->playerStats.maxMp = 50;
		ptrPlayer->playerStats.Strength = 10;
		ptrPlayer->playerStats.Intelligence = 7;
		ptrPlayer->playerStats.Defense = 7;
		ptrPlayer->playerStats.MagicDefense = 7;
		break;
	}

	// 5. 현재 HP/MP를 최대치로 설정
	ptrPlayer->playerStats.hp = ptrPlayer->playerStats.maxHp;
	ptrPlayer->playerStats.mp = ptrPlayer->playerStats.maxMp;

	// 6. 스킬 슬롯 초기화 (모두 '스킬 없음' 상태로)
	for (int i = 0; i < MAX_SKILLS; i++) {
		ptrPlayer->playerStats.learnedSkills[i].id = SKILL_NONE;
	}

	// TODO: 직업별 기본 스킬 1~2개 지급하는 코드 추가 가능

	// 7. 계정 활성화
	ptrPlayer->accountDetect = 1;

	printf("\n\"%s\"님, 당신의 모험이 이제 시작됩니다.\n", ptrPlayer->playerStats.name);
	Sleep(2000);
}

GameState handleInGame(Player* currentPlayer) {



}