#pragma once
#ifndef COMMON_H
#define COMMON_H

#define MAX_SKILLS 100
#define MAX_JOB_TYPES 3
#define MAX_SAVE_SLOTS 3

typedef enum {
	STATE_MAIN_MENU,// 메인 메뉴 화면
	STATE_NEW_GAME_SLOTS, // '새 게임' 선택 후 슬롯 선택 화면
	STATE_LOAD_GAME_SLOTS,// '이어하기' 선택 후 슬롯 선택 화면 (미래 기능)
	STATE_IN_GAME,// 실제 게임 플레이 중 (마을, 필드, 던전 등)
	STATE_EXIT// 게임 종료
} GameState;

typedef enum { //속성 정의, 추후 활용 예정
	NONE = 0,
	FIRE,
	WATER,
	GRASS
} Element;

typedef enum { //플레이어 캐릭터의 직업 분류
	WARRIOR = 1,
	MAGE,
	ARCHER
} CharacterClass;

typedef enum { // skill_ids.h 또는 common.h 같은 공용 헤더 파일에 정의할 예정
	// 플레이어가 배울 수 있는 모든 스킬의 목록
	SKILL_NONE = 0, // 0번은 빈 슬롯으로 사용
	SKILL_FIREBALL,
	SKILL_ICESTORM,
	SKILL_HEAL,
	SKILL_THUNDERBOLT,
	SKILL_QUICK_SLASH
	// ... 앞으로 추가될 스킬들
} SkillID;
typedef struct { // 스킬에 장착할 룬 정보를 담을 간단한 구조체 (미리 만들어두기)
	int rune_id; // 룬의 종류를 구별하는 ID
	char rune_name[30];
	// ... 룬의 효과를 나타내는 다른 변수들
} Rune;

// 플레이어가 '실제로 소유한' 스킬 하나의 정보를 담는 구조체
typedef struct {
	SkillID id;// 어떤 스킬인가? (enum 값: SKILL_FIREBALL 등)
	int level;// 이 스킬의 레벨은 몇인가?
	int maxLevel;
	int current_exp;// 스킬 숙련도 (레벨업을 위해)
	int requiredSkillExp;
	Rune equipped_runes[3];// 이 스킬에 장착된 룬 목록
	Element element;
	int costMp;
	int coolDown;
	int skillPower;//스킬의 화력, 공격스킬이면 공격력, 회복스킬이면 회복력
	CharacterClass learnableJob[MAX_JOB_TYPES];//스킬을 배울수 있는 직업
} PlayerSkill;

typedef struct {
	char name[50];
	int level;
	Element element; //캐릭터의 메인 속성, 캐릭터의 메인 속성과 동일한 속성의 마법을 사용할경우 효과에 가중치 부여 예정
	int hp;
	int maxHp;
	int mp;
	int maxMp;
	int Strength;//물리 공격력
	int Intelligence;//마법 공격력
	int Defense;//물리 방어력
	int MagicDefense;//마법 방어력
	PlayerSkill learnedSkills[MAX_SKILLS]; //어떤 스킬을 가지고있는지를 배열형태로 감지
	//구현된 스킬수가 많아지면 배열 크기를 늘리는 식으로 활용
} entityStats; //몬스터와 플레이어가 공유하는 스탯, 몬스터는 엔티티스탯 하나만 가짐

typedef struct {
	int accountDetect;//계정이 생성되었는지 감지하는 값, 1일때 생성됨. 0이면 생성되지 않은걸로 간주, 이어하기를 눌러도 표시되지 않음
	entityStats playerStats;
	CharacterClass job;
	int gold;
	int exp;//플레이어의 현재 경험치
	int requiredExp; //레벨업을 위해 요구되는 경험치, 레벨마다 바뀜(각 레벨마다 요구되는 경험치를 계산식으로 정할지, 리터럴로 정할지는 고민중)
} Player;


#endif
