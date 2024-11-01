// [4] A, B, C, D, F 로 평가하는 국어와 수학 과목에서 5명 학생들이 각 과목에서 5번의 시험을 보았다.
//  각 과목의 최종 평가 등급은 5번 시험의 등급에서 제일 많이 받은 등급으로 결정되며 등급갯수가 같으면 상위등급 (ABBCC=>B)으로 결정한다.
//   각 등급을 아래와 같이 점수로 환산할 때 과목별로 각 학생들의 이름(1자)과 5번의 성적을 입력받아 각 학생의 학생이름, 
//   2과목의 전체석차와 평균점수를 소수 둘째 자리까지 석차순으로 출력하는 프로그램을 작성(동일 성적은 없음)
// A:95     B:85   C:75 D:65 F:0

/*

1. 학생의 이름을 입력받는다. (char name[5])
2. 각 학생의 과목별 점수를 A.B,C와 같은 점수로 결정한다.
2.1. 최종 점수는 우선, 이중 for문을 통해서 계산한다. i<5, i<2(국어, 수학) 우선 배열을 초기화하고
2.2. 각 등급의 개수를 센다- int count[5] 각 인덱스별로, ABCDF에 해당, 값은 그 등급의 개수
2.3. 각 등급의 개수에서 가장 많이 받은 등급을 찾는다. (maxCount - 개수, gradeIndex - 어떤 점수인지)
2.3.1 반복문으로 가장 많은 개수를 가진 count[k]값을 찾는다, 만약 등급 개수가 같은 경우 상위 등급을 선택한다.
3. 각 학생의 평균 점수로 석차를 매긴다.
3.1 averages[5]에 각 학생의 평균을 계산해 넣는다. 
3.2 
4. 출력한다.


*/

#include <stdio.h>

int main() {
    char names[5]; // 학생 이름 배열
    char grades[5][2][5]; // 학생별 과목별 시험 성적 ('A', 'B', 'C', 'D', 'F')
    int finalScores[5][2]; // 학생별 과목별 최종 점수 (점수 환산 후)
    float averages[5]; // 학생별 평균 점수
    int indices[5]; // 석차를 계산하기 위한 인덱스 배열
    int i, j, k;
    int count[5]; // 등급별 개수를 저장하기 위한 배열

    // 입력 받기
    for (i = 0; i < 5; i++) {
        // 학생 이름 입력
        scanf(" %c", &names[i]);

        // 국어와 수학 과목별로 입력 받기
        for (j = 0; j < 2; j++) {
            // 각 과목의 5번 시험 성적 입력
            for (k = 0; k < 5; k++) {
                scanf(" %c", &grades[i][j][k]);
            }
        }
    }

    // 최종 점수 계산
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            // 등급별 개수 초기화 (A, B, C, D, F 순서)
            for (k = 0; k < 5; k++) {
                count[k] = 0;
            }

            // 각 등급의 개수 카운트
            for (k = 0; k < 5; k++) {
                switch (grades[i][j][k]) {
                    case 'A':
                        count[0]++;
                        break;
                    case 'B':
                        count[1]++;
                        break;
                    case 'C':
                        count[2]++;
                        break;
                    case 'D':
                        count[3]++;
                        break;
                    case 'F':
                        count[4]++;
                        break;
                }
            }

            // 가장 많이 받은 등급 찾기
            int maxCount = count[0];
            int gradeIndex = 0;

            for (k = 1; k < 5; k++) {
                if (count[k] > maxCount) {
                    maxCount = count[k];
                    gradeIndex = k;
                } else if (count[k] == maxCount && k < gradeIndex) {
                    // 등급 개수가 같을 경우 상위 등급 선택
                    gradeIndex = k;
                }
            }

            // 등급을 점수로 환산하여 최종 점수에 저장
            switch (gradeIndex) {
                case 0:
                    finalScores[i][j] = 95; // A
                    break;
                case 1:
                    finalScores[i][j] = 85; // B
                    break;
                case 2:
                    finalScores[i][j] = 75; // C
                    break;
                case 3:
                    finalScores[i][j] = 65; // D
                    break;
                case 4:
                    finalScores[i][j] = 0;  // F
                    break;
            }
        }
    }

    // 평균 점수 계산 및 인덱스 초기화
    for (i = 0; i < 5; i++) {
        averages[i] = (finalScores[i][0] + finalScores[i][1]) / 2.0;
        indices[i] = i; // 초기 인덱스 설정
    }

    for (i = 0; i < 4; i++) {  // 전체 학생을 순회하며
        for (j = 0; j < 4 - i; j++) {  // 인접한 학생의 점수 비교
            if (averages[indices[j]] < averages[indices[j + 1]]) {
                // 평균 점수가 더 크면 인덱스를 교환
                int tempIndex = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tempIndex;
            }
        }
    }

    // 결과 출력
    for (i = 0; i < 5; i++) {
        int idx = indices[i]; // 정렬된 인덱스 가져오기
        printf("%c %d %.2f\n", names[idx], i + 1, averages[idx]);
    }

    return 0;
}