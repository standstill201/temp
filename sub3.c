
// [3] 5명 학생의 이름(알파벳 1자)과 각 학생의 5번(중복 학점 존재 가능)의 학점(A, B, C, D, F중에서)을 한 학생씩 읽어 최대학점과 최소학점을 제외한 나머지 3개 학점으로
// (예: A, A, B, B, F: A, B, B가 해당) 다음과 같이 해당 학생의 평균 평점을 계산하여 석차순으로(동일 석차 존재가능: 예:1 1 3등) 
// 각 학생의 석차, 이름 및 평균 평점과 전체 학생의 평균 평점을 출력하는 프로그램을 작성
//  A(4.5),  B(3.5) C(2.5)D(1.5)F(0)
// **출력 예시: 1:S 4.00    1:K 4.00     3: H 3.58   4: M 3.33   5: L 3.01

// 1. 우선 5명의 학생 이름과 5명의 학점을 읽어야 한다. 이는 하나의 배열 arr으로 처리 가능하다
// 2. 최대, 최소 학점을 제외한 나머지 3개만을 남긴다
// 2.1 최대, 최소 학점을 찾는다. - 반복문으로 arr 반복하면서 최대엔 char max, 최소엔  char min을 할당한다. (ascii 값으로 비교)
// 2.2 다시 반복문을 돌리면서 최대, 최소 학점을 "한 번만" '0'으로 초기화한다. - 첫 번째 초기화 당시 min, max문을 초기화하고, if 조건문을 달아, min, max값이 초기화 됐는지 확인한다.
// 2.3 sortArr에 각 행마다 이름과, 더한 값을 저장한다.
// 3. 이후 sortArr 버블 정렬을 통해 정렬한다. (배열 안에 들어있는 값들을 ascii값으로 더해서 계산)
// 3.1 정렬한 배열을 이중 반복문을 통해 순위를 매긴다
// 4. 출력한다.
// 부록: 필요한 함수 : printf, scanf
#include <stdio.h>

int main() {
    char arr[5][7];          // 학생 이름 + 5개의 학점 저장
    float floatArr[5];        // 각 학생의 평균 평점 저장
    int rankArr[5];           // 석차 저장

    // 1. 학생 이름과 학점 입력 받기 및 최대/최소 제외한 평균 계산
    for (int i = 0; i < 5; i++) {
        printf("학생 이름과 학점 5개를 입력하세요: ");
        scanf(" %c %c %c %c %c %c", 
            &arr[i][0], &arr[i][1], &arr[i][2], 
            &arr[i][3], &arr[i][4], &arr[i][5]);

        // 2. 최대/최소 학점 찾기
        char max = arr[i][1];
        char min = arr[i][1];
        for (int j = 2; j < 6; j++) {
            if (arr[i][j] > max) max = arr[i][j];
            if (arr[i][j] < min) min = arr[i][j];
        }

        // 3. 최대/최소 학점 각각 한 번씩만 제외하고 나머지 3개의 평점 합산
        float sum = 0.0;
        int maxRemoved = 0, minRemoved = 0;  // 최대/최소 학점 제거 여부
        int count = 0;

        for (int j = 1; j < 6; j++) {
            if (arr[i][j] == max && maxRemoved == 0) {
                maxRemoved = 1;  // 최대값 한 번만 제외
                continue;
            }
            if (arr[i][j] == min && minRemoved == 0) {
                minRemoved = 1;  // 최소값 한 번만 제외
                continue;
            }

            // 나머지 학점의 평점을 합산
            if (arr[i][j] == 'A') sum += 4.5;
            else if (arr[i][j] == 'B') sum += 3.5;
            else if (arr[i][j] == 'C') sum += 2.5;
            else if (arr[i][j] == 'D') sum += 1.5;
            else if (arr[i][j] == 'F') sum += 0.0;
            count++;
        }

        // 4. 나머지 3개 학점의 평균 계산 후 저장
        floatArr[i] = sum / 3.0;
    }

    // 5. 버블 정렬로 평점 기준 정렬 (floatArr와 arr 동시 정렬)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (floatArr[j] < floatArr[j + 1]) {
                // floatArr 교환
                float temp = floatArr[j];
                floatArr[j] = floatArr[j + 1];
                floatArr[j + 1] = temp;

                // arr 교환 (학생 이름과 학점)
                for (int k = 0; k < 7; k++) {
                    char tempChar = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = tempChar;
                }
            }
        }
    }

    // 6. 석차 계산
    for (int i = 0; i < 5; i++) {
        rankArr[i] = 1;  // 초기 석차는 1등으로 설정
        for (int j = 0; j < 5; j++) {
            if (floatArr[i] < floatArr[j]) rankArr[i]++;
        }
    }

    // 7. 결과 출력
    printf("\n석차 : 이름 평균 평점\n");
    for (int i = 0; i < 5; i++) {
        printf("%d : %c %.2f\n", rankArr[i], arr[i][0], floatArr[i]);
    }

    return 0;
}