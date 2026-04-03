//플레이어를 항상 1번에 고정
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

const char* randomChoice() {
    return choices[rand() % 3];
}

// 다른 선수들 경기 자동 진행
const char* autoMatch(const char* p1, const char* p2) {
    const char* c1, *c2;
    int result;
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

// 내가 하는 경기 (입력 검증 포함)
const char* playerMatch(const char* playerName, const char* opponent) {
    char input[20];
    const char* oppChoice;
    int result = 0;        // ✅ 반드시 초기화
    int wrongCount = 0;

    do {
        printf("\n상대 : %s\n", opponent);
        printf("가위 / 바위 / 보 중 하나 입력 > ");
        scanf("%s", input);

        // 입력 검증
        if (strcmp(input, "가위") != 0 &&
            strcmp(input, "바위") != 0 &&
            strcmp(input, "보") != 0) {
            wrongCount++;
            if (wrongCount == 1) {
                printf("1회 잘못 입력했습니다! 다시 입력해주세요.\n");
                result = 0;   // ✅ 재경기 상태 유지
                continue;
            } else if (wrongCount == 2) {
                printf("2회 잘못 입력했습니다! 다시 입력해주세요.\n");
                result = 0;
                continue;
            } else if (wrongCount >= 3) {
                printf("3회 잘못 입력했습니다! 실격입니다.\n");
                return opponent; // 상대 승, 게임 종료
            }
        } else {
            // 정상 입력일 경우
            oppChoice = randomChoice();
            printf("%s : %s   %s : %s\n", playerName, input, opponent, oppChoice);

            result = judge(input, oppChoice);
            if (result == 0) {
                printf("=> 비겼습니다! 재경기!\n");
            } else if (result == 1) {
                printf("=> 이겼습니다!\n");
                return playerName;
            } else {
                printf("=> 졌습니다...\n");
                return opponent;
            }
        }
    } while (result == 0);

    return opponent;
}

// 대진표 출력
void printBracket(const char* roundName, const char* players[], int count) {
    printf("\n=== %s 대진표 ===\n", roundName);
    for (int i = 0; i < count; i += 2) {
        printf("[%d] %s vs [%d] %s\n", i+1, players[i], i+2, players[i+1]);
    }
    printf("\n");
}

// 배열 섞기 (랜덤 대진표, 단 플레이어는 항상 1번)
void shuffleOpponents(const char* arr[], int n) {
    for (int i = n-1; i > 1; i--) { // 1번은 고정, 2번부터 섞음
        int j = rand() % (i-1) + 1;
        const char* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand((unsigned int)time(NULL));

    char playerName[50];
    printf("당신의 닉네임을 입력하세요: ");
    scanf("%s", playerName);

    // 규칙 설명
    printf("\n## 가위바위보 토너먼트 ##\n\n");
    printf("=== 게임 규칙 ===\n");
    printf("1. 가위는 보를 이깁니다.\n");
    printf("2. 바위는 가위를 이깁니다.\n");
    printf("3. 보는 바위를 이깁니다.\n");
    printf("4. 잘못 입력은 2번까지 허용됩니다.\n");
    printf("   - 1번째 잘못 입력: '다시 입력해주세요'\n");
    printf("   - 2번째 잘못 입력: '다시 입력해주세요'\n");
    printf("   - 3번째 잘못 입력: 실격 처리 → 게임 종료\n");
    printf("5. 비기면 재경기를 진행합니다.\n\n");

    // 초기 선수 목록 (플레이어는 항상 1번)
    const char* players[8] = {playerName, "철수", "영희", "민준", "지아", "현우", "수빈", "태양"};

    // 8강
    shuffleOpponents(players, 8);
    printBracket("8강", players, 8);

    const char* qfWinners[4];
    for (int i = 0; i < 8; i += 2) {
        if (strcmp(players[i], playerName) == 0 || strcmp(players[i+1], playerName) == 0) {
            const char* opponent = (strcmp(players[i], playerName) == 0) ? players[i+1] : players[i];
            qfWinners[i/2] = playerMatch(playerName, opponent);
            if (strcmp(qfWinners[i/2], playerName) != 0) {
                printf("\n당신은 탈락했습니다. 게임 종료.\n");
                return 0;
            }
        } else {
            qfWinners[i/2] = autoMatch(players[i], players[i+1]);
        }
    }

    // 4강
    shuffleOpponents(qfWinners, 4);
    printBracket("4강", qfWinners, 4);

    const char* sfWinners[2];
    for (int i = 0; i < 4; i += 2) {
        if (strcmp(qfWinners[i], playerName) == 0 || strcmp(qfWinners[i+1], playerName) == 0) {
            const char* opponent = (strcmp(qfWinners[i], playerName) == 0) ? qfWinners[i+1] : qfWinners[i];
            sfWinners[i/2] = playerMatch(playerName, opponent);
            if (strcmp(sfWinners[i/2], playerName) != 0) {
                printf("\n당신은 탈락했습니다. 게임 종료.\n");
                return 0;
            }
        } else {
            sfWinners[i/2] = autoMatch(qfWinners[i], qfWinners[i+1]);
        }
    }

    // 결승
    shuffleOpponents(sfWinners, 2);
    printBracket("결승", sfWinners, 2);

    const char* champion;
    if (strcmp(sfWinners[0], playerName) == 0 || strcmp(sfWinners[1], playerName) == 0) {
        const char* opponent = (strcmp(sfWinners[0], playerName) == 0) ? sfWinners[1] : sfWinners[0];
        champion = playerMatch(playerName, opponent);
    } else {
        champion = autoMatch(sfWinners[0], sfWinners[1]);
    }

    printf("\n=== 최종 결과 ===\n");
    if (strcmp(champion, playerName) == 0)
        printf("축하합니다! 당신이 우승했습니다!\n");
    else
        printf("%s 우승! 아쉽습니다. 다음 기회에!\n", champion);
    return 0;
}