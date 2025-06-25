#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include "util.h"
#include "common.h"
void printTitleDisplay(void) {//타이틀 아스키 아트를 그림
	printf("  _______                              __               _                 _                        _____  _____   _____ \n");
	printf(" |__   __|                            / _|     /\\      | |               | |                      |  __ \\|  __ \\ / ____|\n");
	printf("    | | _____      _____ _ __    ___ | |_     /  \\   __| |_   _____ _ __ | |_ _   _ _ __ ___      | |__) | |__) | |  __ \n");
	printf("    | |/ _ \\ \\ /\\ / / _ \\ '__|  / _ \\|  _|   / /\\ \\ / _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\     |  _  /|  ___/| | |_ |\n");
	printf("    | | (_) \\ V  V /  __/ |    | (_) | |    / ____ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/  _  | | \\ \\| |    | |__| |\n");
	printf("    |_|\\___/ \\_/\\_/ \\___|_|     \\___/|_|   /_/    \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___| ( ) |_|  \\_\\_|     \\_____|\n");
	printf("                                                                                              |/                        \n");

}

int getChoice(int min, int max) { //숫자 입력을 통해 입력된 값을 반환, 유효하지 않은 값을 받으면 값을 반환하지않고 재입력을 시킴
	int num, detect, c;
	while (1) {
		detect = scanf(" %d", &num);
		if (detect == 1 && num >= min && num <= max) {
			while ((c = getchar()) != '\n' && c != EOF);
			break;
		}
		while ((c = getchar()) != '\n' && c != EOF);
	}
	return num;
}

void printWithDelay(const char* text, int ms) { //글자를 한글자씩 느리게 출력, ms값을 통해 출력 속도 조정 가능
	int i;
	for (i = 0; text[i] != '\0'; i++) {
		putchar(text[i]);
		fflush(stdout);
		Sleep(ms);
	}
}