//잘못 입력시 경고문 + 문자열로 입력
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 승패 판정 함수
int judge(const char* player, const char* opponent) {
    if (strcmp(player, opponent) == 0) return 0; // 비김

    if ((strcmp(player, "가위") == 0 && strcmp(opponent, "보") == 0) ||
        (strcmp(player, "바위") == 0 && strcmp(opponent, "가위") == 0) ||
        (strcmp(player, "보") == 0 && strcmp(opponent, "바위") == 0)) {
        return 1; // 플레이어 승
    }
    return -1; // 플레이어 패
}

// 랜덤으로 상대 선택
const char* randomChoice() {
    int r = rand() % 3;
    if (r == 0) return "가위";
    else if (r == 1) return "바위";
    else return "보";
}

// 경기 진행 함수
int playMatch(const char* opponentName) {
    char player[20];
    const char* opponent;
    int result = 0;

    do {
        printf("\n상대 : %s\n", opponentName);
        printf("가위 / 바위 / 보 중 하나 입력 > ");
        scanf("%s", player);

        // 입력 검증
        if (strcmp(player, "가위") != 0 &&
            strcmp(player, "바위") != 0 &&
            strcmp(player, "보") != 0) {
            printf("잘못 입력했습니다! '가위', '바위', '보' 중 하나만 입력하세요.\n");
            continue;
        }

        opponent = randomChoice();
        printf("나 : %s   %s : %s\n", player, opponentName, opponent);

        result = judge(player, opponent);
        if (result == 0) {
            printf("=> 비겼습니다! 재경기!\n");
        } else if (result == 1) {
            printf("=> 이겼습니다!\n");
        } else {
            printf("=> 졌습니다...\n");
        }
    } while (result == 0); // 비기면 반복

    return result;
}

int main() {
    srand((unsigned int)time(NULL));

    const char* opponents[7] = {"철수", "영희", "민준", "지아", "현우", "수빈", "태양"};

    printf("## 가위바위보 토너먼트 ##\n");
    printf("당신은 [1] 플레이어입니다.\n");

    // 8강
    if (playMatch(opponents[0]) == -1) {
        printf("아쉽습니다. 탈락...\n");
        return 0;
    }

    // 4강
    if (playMatch(opponents[2]) == -1) {
        printf("아쉽습니다. 탈락...\n");
        return 0;
    }

    // 결승
    if (playMatch(opponents[6]) == -1) {
        printf("아쉽습니다. 다음 기회에!\n");
        return 0;
    }

    printf("\n축하합니다! 우승!\n");
    return 0;
}