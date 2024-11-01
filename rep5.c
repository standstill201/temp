#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL));

    int gr1[30]; 
    int gr2[30]; 
    int gr3[60]; 
    int input_num = rand() % 21 + 10;

    // 그룹 1: 사용자 입력 받기
    printf("자연수를 입력하세요 (0~99), 입력 종료는 EOF (Ctrl+Z):\n");
    for (int i = 0; i < input_num; i++) {
        if (scanf("%d", &gr1[i]) == EOF) {
            input_num = i; // 실제 입력된 개수로 갱신
            break;
        }
        if (gr1[i] < 0 || gr1[i] > 99) {
            printf("0~99 사이의 자연수만 입력하세요.\n");
            i--; // 잘못된 입력은 다시 받도록 함
        }
    }

    // 그룹 2: 무작위로 30개의 숫자 생성 (중복 없이)
    for (int i = 0; i < 30; i++) {
        int temp = rand() % 100;
        for (int j = 0; j < i; j++) {
            if (temp == gr2[j]) { // 중복 체크
                temp = -1;
                i--; // 중복이면 다시 생성
                break;
            }
        }
        if (temp != -1) {
            gr2[i] = temp;
        }
    }

    // 그룹 1과 그룹 2의 배열 정렬 (버블 정렬)
    for (int i = 0; i < input_num - 1; i++) {
        for (int j = 0; j < input_num - i - 1; j++) {
            if (gr1[j] > gr1[j + 1]) {
                int temp = gr1[j];
                gr1[j] = gr1[j + 1];
                gr1[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 29 - i; j++) {
            if (gr2[j] > gr2[j + 1]) {
                int temp = gr2[j];
                gr2[j] = gr2[j + 1];
                gr2[j + 1] = temp;
            }
        }
    }

    // 정렬된 결과 출력
    printf("그룹 1 (정렬됨): ");
    for (int i = 0; i < input_num; i++) {
        printf("%d ", gr1[i]);
    }
    printf("\n");

    printf("그룹 2 (정렬됨): ");
    for (int i = 0; i < 30; i++) {
        printf("%d ", gr2[i]);
    }
    printf("\n");

    // 병합 정렬 (Merge) - 두 그룹을 하나로 병합
    int i = 0, j = 0, k = 0;
    while (i < input_num && j < 30) {
        if (gr1[i] <= gr2[j]) {
            gr3[k++] = gr1[i++];
        } else {
            gr3[k++] = gr2[j++];
        }
    }
    while (i < input_num) {
        gr3[k++] = gr1[i++];
    }
    while (j < 30) {
        gr3[k++] = gr2[j++];
    }

    // 병합된 배열 출력
    printf("병합된 전체 배열 (정렬됨): ");
    for (int i = 0; i < input_num + 30; i++) {
        printf("%d ", gr3[i]);
    }
    printf("\n");

    // 그룹 A~T로 분류하여 출력 (배열 없이)
    printf("그룹별 분류:\n");

    char group_name = 'A'; // 현재 그룹명 ('A'부터 시작)
    int lower_bound = 0; // 그룹의 하한값 (0부터 시작)
    int count = 0; // 해당 그룹의 멤버 수
    int temp_index = 0; // 병합된 배열의 인덱스

    // 그룹 A~T까지 순회하며 각 그룹의 멤버 수를 출력
    while (group_name <= 'T') {
        // 현재 그룹의 범위에 속하는 원소 세기
        while (temp_index < input_num + 30 && gr3[temp_index] < lower_bound + 5) {
            count++;
            temp_index++;
        }

        // 그룹 출력
        printf("%c: %d개\n", group_name, count);

        // 다음 그룹으로 이동
        group_name++; // 다음 그룹명으로 변경 ('A' -> 'B' -> ...)
        lower_bound += 5; // 다음 그룹의 시작점 설정
        count = 0; // 멤버 수 초기화
    }

    return 0;
}
