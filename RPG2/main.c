#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "util.h"
#include "skill.h"
#include "rune.h"
#include "monster.h"
#include "map.h"
#include "item.h"
#include "game_state.h"
#include "entity.h"
#include "anime.h"
#include "common.h"


//추후 함수 분류할것 리스트, 각 함수들을 헤더파일과 소스파일등으로 분할 예정 
//기타
//맵 관련
//전투 관련
//속성 관련
//상점 관련
//몬스터의 AI관련
//구조체 데이터 관련
//세이브 및 로드 관련
//게임 시스템 구조 관련
//몬스터 도감 관련
//아이템 관련
//무기, 방어구등 장비 관련

//플레이어의 정보를 담고있는 구조체도 추가 예정




int main(void) {
	SetConsoleTitle(L"Tower of Adventure, RPG"); // 콘솔 타이틀 설정
	srand(time(NULL));

	// 세이브 데이터 준비
	Player playerSlots[MAX_SAVE_SLOTS] = { {0} }; // 모든 슬롯을 0으로 초기화
	Player* players[MAX_SAVE_SLOTS];
	for (int i = 0; i < MAX_SAVE_SLOTS; i++) {
		players[i] = &playerSlots[i];
	}
	playerSlots[0].accountDetect = 1; // 테스트용으로 캐릭터가 있다고 가정할 때 사용

	Player* currentPlayer = NULL; // 현재 플레이 중인 캐릭터를 가리킬 포인터
	GameState currentState = STATE_MAIN_MENU; // 게임 시작은 메인 메뉴에서

	// 게임의 메인 루프. currentState가 STATE_EXIT가 되면 종료됩니다.
	while (currentState != STATE_EXIT) {
		switch (currentState) {
		case STATE_MAIN_MENU:
			currentState = handleMainMenu();
			break;

		case STATE_NEW_GAME_SLOTS:
			currentState = handleNewGameSlots(players, &currentPlayer);
			break;

		case STATE_LOAD_GAME_SLOTS:
			printf("이어하기는 아직 구현되지 않았습니다.\n");
			system("pause");
			currentState = STATE_MAIN_MENU;
			break;

		case STATE_IN_GAME:
			// 실제 게임 플레이를 처리하는 함수 호출.
			// 어떤 캐릭터로 플레이할지 정보가 필요하므로 currentPlayer를 넘겨줍니다.
			currentState = handleInGame(currentPlayer);
			break;
		}
	}
	system("cls");
	printf("\n\n\n    게임을 종료합니다. 이용해주셔서 감사합니다.\n\n\n");
	Sleep(1500);

	return 0;
}




