#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "common.h"



GameState handleMainMenu(void); //게임의 시작을 관리, 게임 시스템 구조
GameState handleNewGameSlots(Player* players[], Player** currentPlayer); // 세이브 슬롯들을 배열로 한 번에 관리
GameState handleInGame(Player* currentPlayer); // 실제 게임 플레이를 담당할 함수
void createNewPlayer(Player* ptrPlayer);

#endif
