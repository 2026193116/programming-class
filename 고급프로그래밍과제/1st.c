#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 8

// 가위바위보 결과 판정
int judge(int p1, int p2) {
    if (p1 == p2) return 0; // 비김
    if ((p1 == 1 && p2 == 3) || (p1 == 2 && p2 == 1) || (p1 == 3 && p2 == 2))
        return 1; // p1 승
    return 2; // p2 승
}

// 랜덤 선택
int random_choice() {
    return rand() % 3 + 1;
}

// 경기 진행 (비기면 재경기)
// isUser가 1이면 플레이어 입력, 0이면 자동 계산
int play_match(const char *name1, const char *name2, int isUser) {
    int choice1, choice2, result;
    do {
        if (isUser) {
            printf("\n상대 : %s\n", name2);
            printf("1: 가위  2: 바위  3: 보\n선택 > ");
            scanf("%d", &choice1);
            while (choice1 < 1 || choice1 > 3) {
                printf("1, 2, 3 중에서 입력하세요 > ");
                scanf("%d", &choice1);
            }
            choice2 = random_choice();
            printf("나 : %d   %s : %d\n", choice1, name2, choice2);
        } else {
            choice1 = random_choice();
            choice2 = random_choice();
        }

        result = judge(choice1, choice2);
        if (result == 0 && isUser) {
            printf("=> 비겼습니다! 재경기!\n");
        }
    } while (result == 0);

    if (isUser) {
        if (result == 1) {
            printf("=> 이겼습니다!\n");
            return 1;
        } else {
            printf("=> 졌습니다...\n");
            return 2;
        }
    } else {
        return (result == 1) ? 1 : 2; // 결과만 반환
    }
}

int main() {
    srand(time(NULL));

    const char *players[NUM_PLAYERS] = {"플레이어", "철수", "영희", "민준", "지아", "현우", "수빈", "태양"};

    printf("## 가위바위보 토너먼트 ##\n");
    printf("당신은 [1] 플레이어입니다.\n");

    // 8강
    printf("8강");
    int qf_winners[4];
    qf_winners[0] = (play_match(players[0], players[1], 1) == 1) ? 0 : 1;
    qf_winners[1] = (play_match(players[2], players[3], 0) == 1) ? 2 : 3;
    qf_winners[2] = (play_match(players[4], players[5], 0) == 1) ? 4 : 5;
    qf_winners[3] = (play_match(players[6], players[7], 0) == 1) ? 6 : 7;

    // 4강
    printf("4강");
    int sf_winners[2];
    sf_winners[0] = (play_match(players[qf_winners[0]], players[qf_winners[1]], qf_winners[0] == 0) == 1) ? qf_winners[0] : qf_winners[1];
    sf_winners[1] = (play_match(players[qf_winners[2]], players[qf_winners[3]], qf_winners[2] == 0) == 1) ? qf_winners[2] : qf_winners[3];

    // 결승
    printf("결승");
    int champion = (play_match(players[sf_winners[0]], players[sf_winners[1]], sf_winners[0] == 0) == 1) ? sf_winners[0] : sf_winners[1];

    printf("\n축하합니다! 우승자는 %s 입니다!\n", players[champion]);

    return 0;
}