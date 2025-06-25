#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Sleep(), system("cls") 등의 함수 사용
#include <time.h>
#include "anime.h"
#include "util.h"
#include "common.h"
#define MAX_SKILLS 100
#define MAX_JOB_TYPES 3
#define MAX_SAVE_SLOTS 3


void showIntroAnime(void) {//인트로 장면을 연출

	system("cls");
	const int fast = 15;// 일반 텍스트 속도
	const int medium = 30;// 보통 텍스트 속도
	const int slow = 50; // 강조 텍스트 속도

	Sleep(1000); // 1초간 아무것도 보여주지 않아 집중을 유도

	printf("\n\n\n\n\n\n"); // 텍스트를 화면 중앙쯤에 위치시키기 위한 개행
	printWithDelay("                                      세상은 한때, 별빛으로 가득했다.\n", medium);
	Sleep(2000);
	printWithDelay("                                사람들은 번영을 노래했고, 희망을 이야기했다.\n", medium);
	Sleep(3000);
	printWithDelay("                                      그 찬란했던 시절은 그러나...\n", slow);
	Sleep(2500);
	printWithDelay("                                         기억 속에만 존재할 뿐.", slow);
	Sleep(4000);


	system("cls");
	Sleep(1000);
	printf("\n\n\n\n\n\n\n\n");
	printWithDelay("                                                어느 날,\n", slow);
	Sleep(2000);
	printWithDelay("                                            하늘이 찢어졌다.\n", slow);
	Sleep(2500);
	system("cls");


	printf("\n\n\n\n\n\n\n\n");
	Sleep(1000);
	printf("                                                     .\n");
	Sleep(500);
	printf("                                                     |\n");
	Sleep(500);
	printf("                                                    [ ]\n");
	Sleep(500);
	printf("                    .--.____________.              [| |]\n");
	Sleep(500);
	printf("        .--.___.   (________________)             [|   |]\n");
	Sleep(500);
	printf("       (________)                                [|     |]     .____________.--.\n");
	Sleep(500);
	printf("                                  .______.--.    [|     |]     (________________)\n");
	Sleep(500);
	printf("                                 (__________)    [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(500);
	printf("                                                 [|     |]\n");
	Sleep(2000);

	system("cls");


	printf("\n\n\n\n\n\n");
	printWithDelay("                      대지 위에 솟아난 '모험의 탑'은 끝없는 악몽을 토해냈다.\n", medium);
	Sleep(2500);
	printWithDelay("                                 왕국은 무너졌고, 빛은 스러져갔다.\n", medium);
	Sleep(2500);
	printWithDelay("                                     희망이... 사라져갈 때쯤...\n", medium);
	Sleep(4000);


	system("cls");
	printf("\n\n\n\n\n");
	printWithDelay("                                 \"탑이 열릴 때, 별의 조각을 품은 영웅이 나타나\n", fast);
	printWithDelay("                              탑의 심장을 멈추고 세계에 다시 빛을 가져올 것이다.\"\n\n", fast);
	Sleep(3000);
	printWithDelay("                                       - 잊혀진 왕국의 마지막 예언 -\n", fast);
	Sleep(4000);
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printWithDelay("                                         그리고 그 예언은...\n", medium);
	Sleep(2500);
	printWithDelay("                                    바로 당신을 가리키고 있었다.\n", medium);
	Sleep(4000);


	system("cls");
	printf("\n\n");
	printf("                                                 [|     |]\n");
	printf("                                                 [|     |]\n");
	printf("                                                 [|     |]\n");
	printf("                                                 [|_____|]\n");
	printf("                                                 /       \\\n");
	printf("                                                /   ___   \\\n");
	printf("                                             __|   |   |   |__\n");
	printf("                                            /  |   |   |   |  \\\n");
	printf("                                           /   '___|___|___'   \\\n");
	printf("                                          /                     \\\n");
	printf("                                         /_______________________\\\n");
	printf("\n\n");
	printWithDelay("                              이제, 모든 것을 끝내기 위해 탑의 문 앞에 섰다.\n", medium);
	Sleep(3000);
	printf("\n\n");
	printWithDelay("                                   (1을 입력하여 계속...)\n", fast);
	getChoice(1, 1); // 사용자가 1을 입력할 때까지 대기
}

