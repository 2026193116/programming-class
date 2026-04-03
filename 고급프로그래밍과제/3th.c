//대결 상대 랜덤 + 나와 대결하지 않는 플레이어들의 경기도 출력
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* choices[3] = {"가위", "바위", "보"};

int judge(const char* p1, const char* p2) {
    if (strcmp(p1, p2) == 0) return 0; // 비김
    if ((strcmp(p1, "가위") == 0 && strcmp(p2, "보") == 0) ||
        (strcmp(p1, "바위") == 0 && strcmp(p2, "가위") == 0) ||
        (strcmp(p1, "보") == 0 && strcmp(p2, "바위") == 0)) {
        return 1; // p1 승
    }
    return -1; // p2 승
}

// 랜덤 선택
const char* randomChoice() {
    return choices[rand() % 3];
}

// 다른 선수들 경기 진행
const char* autoMatch(const char* p1, const char* p2) {
    const char* c1, *c2;
    int result = 0;
    do {
        c1 = randomChoice();
        c2 = randomChoice();
        printf("%s : %s   %s : %s\n", p1, c1, p2, c2);
        result = judge(c1, c2);
        if (result == 0) {
            printf("=> 비겼습니다! 재경기!\n");
        }
    } while (result == 0);

    if (result == 1) {
        printf("=> %s 승!\n\n", p1);
        return p1;
    } else {
        printf("=> %s 승!\n\n", p2);
        return p2;
    }
}

// 내가 하는 경기
const char* playerMatch(const char* opponent) {
    char input[20];
    const char* oppChoice;
    int result;
    do {
        printf("\n상대 : %s\n", opponent);
        printf("가위 / 바위 / 보 중 하나 입력 > ");
        scanf("%s", input);

        if (strcmp(input, "가위") != 0 &&
            strcmp(input, "바위") != 0 &&
            strcmp(input, "보") != 0) {
            printf("잘못 입력했습니다! 다시 입력하세요.\n");
            continue;
        }

        oppChoice = randomChoice();
        printf("나 : %s   %s : %s\n", input, opponent, oppChoice);

        result = judge(input, oppChoice);
        if (result == 0) {
            printf("=> 비겼습니다! 재경기!\n");
        } else if (result == 1) {
            printf("=> 이겼습니다!\n");
            return "플레이어";
        } else {
            printf("=> 졌습니다...\n");
            return opponent;
        }
    } while (result == 0);

    return opponent;
}

int main() {
    srand((unsigned int)time(NULL));

    const char* players[8] = {"플레이어", "철수", "영희", "민준", "지아", "현우", "수빈", "태양"};

    printf("## 가위바위보 토너먼트 ##\n");

    // 8강
    printf("\n=== 8강 경기 ===\n");
    const char* qf1 = playerMatch(players[1]); // 플레이어 vs 철수
    const char* qf2 = autoMatch(players[2], players[3]); // 영희 vs 민준
    const char* qf3 = autoMatch(players[4], players[5]); // 지아 vs 현우
    const char* qf4 = autoMatch(players[6], players[7]); // 수빈 vs 태양

    // 4강
    printf("\n=== 4강 경기 ===\n");
    const char* sf1;
    if (strcmp(qf1, "플레이어") == 0)
        sf1 = playerMatch(qf2);
    else
        sf1 = autoMatch(qf1, qf2);

    const char* sf2 = autoMatch(qf3, qf4);

    // 결승
    printf("\n=== 결승 경기 ===\n");
    const char* champion;
    if (strcmp(sf1, "플레이어") == 0)
        champion = playerMatch(sf2);
    else if (strcmp(sf2, "플레이어") == 0)
        champion = playerMatch(sf1);
    else
        champion = autoMatch(sf1, sf2);

    printf("\n=== 최종 결과 ===\n");
    if (strcmp(champion, "플레이어") == 0)
        printf("축하합니다! 당신이 우승했습니다!\n");
    else
        printf("%s 우승! 아쉽습니다. 다음 기회에!\n", champion);

    return 0;
}