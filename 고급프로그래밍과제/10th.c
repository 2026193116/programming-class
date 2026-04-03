//천천히 내용 출력
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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
        sleep(1);
        result = judge(c1, c2);
        if (result == 0) {
            printf("=> 비겼습니다! 재경기!\n");
            sleep(1);
        }
    } while (result == 0);

    if (result == 1) {
        printf("=> %s 승!\n\n", p1);
        sleep(1);
        return p1;
    } else {
        printf("=> %s 승!\n\n", p2);
        sleep(1);
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
                sleep(1);
                result = 0;   // ✅ 재경기 상태 유지
                continue;
            } else if (wrongCount == 2) {
                printf("2회 잘못 입력했습니다! 다시 입력해주세요.\n");
                sleep(1);
                result = 0;
                continue;
            } else if (wrongCount >= 3) {
                printf("3회 잘못 입력했습니다! 실격입니다.\n");
                sleep(1);
                return opponent; // 상대 승, 게임 종료
            }
        } else {
            // 정상 입력일 경우
            oppChoice = randomChoice();
            printf("%s : %s   %s : %s\n", playerName, input, opponent, oppChoice);

            result = judge(input, oppChoice);
            if (result == 0) {
                printf("=> 비겼습니다! 재경기!\n");
                sleep(1);
            } else if (result == 1) {
                printf("=> 이겼습니다!\n");
                sleep(1);
                return playerName;
            } else {
                printf("=> 졌습니다...\n");
                sleep(1);
                return opponent;
            }
        }
    } while (result == 0);

    return opponent;
}

// 대진표 출력
void printBracket(const char* roundName, const char* players[], int count) {
    printf("\n=== %s 대진표 ===\n", roundName);
    sleep(1);
    for (int i = 0; i < count; i += 2) {
        printf("[%d] %s vs [%d] %s\n", i+1, players[i], i+2, players[i+1]);
        sleep(1);
    }
    printf("\n");
}

// 배열 섞기 (랜덤 대진표, 단 플레이어는 항상 1번)
void shuffleOpponents(const char* arr[], int n) {
    for (int i = n-1; i > 1; i--) { // 1,2번은 고정, 3번부터 섞음
        int j = rand() % (i-1) + 1;
        const char* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// 탈락 후 관람 여부 확인
int askSpectate() {
    char choice;
    printf("\n당신은 탈락했습니다. 이후 경기를 관람하시겠습니까? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') return 1;
    return 0;
}
// 싱글플레이어 모드 (토너먼트 방식)
void singleplayerMode() {
    char playerName[50];
    printf("당신의 닉네임을 입력하세요: ");
    scanf("%s", playerName);

    // 규칙 설명
    printf("\n## 가위바위보 토너먼트 ##\n\n");
    printf("=== 게임 규칙 ===\n");
    sleep(1);
    printf("1. 가위는 보를 이깁니다.\n");
    sleep(1);
    printf("2. 바위는 가위를 이깁니다.\n");
    sleep(1);
    printf("3. 보는 바위를 이깁니다.\n");
    sleep(1);
    printf("4. 잘못 입력은 2번까지 허용됩니다.\n");
    sleep(1);
    printf("   - 1번째 잘못 입력 : 다시 입력해주세요\n");
    sleep(1);
    printf("   - 2번째 잘못 입력 : 다시 입력해주세요\n");
    sleep(1);
    printf("   - 3번째 잘못 입력 : 실격 처리 -> 게임 종료\n");
    sleep(1);
    printf("5. 비기면 재경기를 진행합니다.\n\n");
    sleep(1);

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
                if (!askSpectate()) return;
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
                if (!askSpectate()) return;
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
        if (strcmp(champion, playerName) != 0) {
            if (!askSpectate()) return;
        }
    } else {
        champion = autoMatch(sfWinners[0], sfWinners[1]);
    }

    printf("\n=== 최종 결과 ===\n");
    if (strcmp(champion, playerName) == 0)
        printf("축하합니다! %s 님이 우승했습니다!\n", playerName);
    else
        printf("%s 우승! 아쉽습니다. 다음 기회에!\n", champion);
}

// 듀얼플레이어 모드 (3전 2선승제, 입력 검증 포함)
// 듀얼플레이어 모드 (3전 2선승제, 입력 검증 개선)
void multiplayerMode() {
    char p1[50], p2[50];
    char input1[20], input2[20];
    int score1 = 0, score2 = 0;
    int wrong1 = 0, wrong2 = 0;   // 잘못 입력 횟수 추적
    int round = 1;

    printf("플레이어1 닉네임 입력: ");
    scanf("%s", p1);
    printf("플레이어2 닉네임 입력: ");
    scanf("%s", p2);

    printf("\n=== 듀얼플레이어 모드 시작 ===\n");
    printf("%s vs %s (3전 2선승제)\n\n", p1, p2);
    sleep(1);
    printf("\n## 가위바위보 토너먼트 ##\n\n");
    printf("=== 게임 규칙 ===\n");
    sleep(1);
    printf("1. 가위는 보를 이깁니다.\n");
    sleep(1);
    printf("2. 바위는 가위를 이깁니다.\n");
    sleep(1);
    printf("3. 보는 바위를 이깁니다.\n");
    sleep(1);
    printf("4. 잘못 입력은 2번까지 허용됩니다.\n");
    sleep(1);
    printf("   - 1번째 잘못 입력 : 다시 입력해주세요\n");
    sleep(1);
    printf("   - 2번째 잘못 입력 : 다시 입력해주세요\n");
    sleep(1);
    printf("   - 3번째 잘못 입력 : 실격 처리 -> 게임 종료\n");
    sleep(1);
    printf("5. 비기면 재경기를 진행합니다.\n\n");
    sleep(1);

    while (score1 < 2 && score2 < 2) {
        printf("\n--- Round %d ---\n", round++);

        // ✅ 플레이어1 입력 검증 루프
        while (1) {
            printf("%s 입력 (가위/바위/보): ", p1);
            scanf("%s", input1);
            if (strcmp(input1, "가위") == 0 ||
                strcmp(input1, "바위") == 0 ||
                strcmp(input1, "보") == 0) {
                break; // 정상 입력 → 루프 탈출
            } else {
                wrong1++;
                if (wrong1 == 1) {
                    printf("%s: 1회 잘못 입력했습니다! 다시 입력해주세요.\n", p1);
                    sleep(1);
                } else if (wrong1 == 2) {
                    printf("%s: 2회 잘못 입력했습니다! 다시 입력해주세요.\n", p1);
                    sleep(1);
                } else {
                    printf("%s: 3회 잘못 입력했습니다! 실격입니다.\n", p1);
                    if (wrong2 >= 3) {
                        printf("두 플레이어 모두 실격 → 경기 종료!\n");
                    } else {
                        printf("최종 승자: %s!\n", p2);
                    }
                    return;
                }
            }
        }

        // ✅ 플레이어2 입력 검증 루프
        while (1) {
            printf("%s 입력 (가위/바위/보): ", p2);
            scanf("%s", input2);
            if (strcmp(input2, "가위") == 0 ||
                strcmp(input2, "바위") == 0 ||
                strcmp(input2, "보") == 0) {
                break; // 정상 입력 → 루프 탈출
            } else {
                wrong2++;
                if (wrong2 == 1) {
                    printf("%s: 1회 잘못 입력했습니다! 다시 입력해주세요.\n", p2);
                    sleep(1);
                } else if (wrong2 == 2) {
                    printf("%s: 2회 잘못 입력했습니다! 다시 입력해주세요.\n", p2);
                    sleep(1);
                } else {
                    printf("%s: 3회 잘못 입력 → 실격!\n", p2);
                    if (wrong1 >= 3) {
                        printf("두 플레이어 모두 실격 → 경기 종료!\n");
                    } else {
                        printf("최종 승자: %s!\n", p1);
                    }
                    return;
                }
            }
        }

        // ✅ 정상 입력일 경우 경기 진행
        int result = judge(input1, input2);
        if (result == 0) {
            printf("비겼습니다! 다시 진행합니다.\n");
            sleep(1);
        } else if (result == 1) {
            printf("%s 승!\n", p1);
            score1++;
        } else {
            printf("%s 승!\n", p2);
            score2++;
        }
        printf("현재 스코어: %s %d승 - %s %d승\n", p1, score1, p2, score2);
        sleep(1);
    }

    if (score1 == 2) printf("\n최종 승자: %s!\n", p1);
    else printf("\n최종 승자: %s!\n", p2);
}

int main() {
    srand((unsigned int)time(NULL));

    int mode;
    printf("게임 모드를 선택하세요:\n");
    printf("1. 싱글플레이어\n");
    printf("2. 듀얼플레이어\n");
    printf("선택 > ");
    scanf("%d", &mode);

    if (mode == 1) {
        singleplayerMode();
    } else if (mode == 2) {
        multiplayerMode();
    } else {
        printf("잘못된 선택입니다. 프로그램 종료.\n");
    }

    return 0;
}