#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct Student { // Student
	char name[10];
	int kor;
	int eng;
	int math;
};

struct StudentList {
	Student * student;
};// Student List 구성

// Student 에 데이터 입력

int main() {
  struct Student stu;
  int menu;
  char name[10];
  int kor=0, eng=0, math=0;

  while (1) {
    printf("<< === Student Manager === >>\n");
    printf("1. 학생 정보 출력\n" );
    printf("2. 학생 정보 입력\n" );
    printf("3. 학생 정보 수정\n" );
    printf("4. 학생 정보 삭제\n" );
    printf("5. 학생 정보 삽입\n" );
    printf("6. 학생 정보 검색\n" );
    printf("7. 학생 정보 종료\n" );
    printf("선택 :\n" );

    scanf("%d", &menu);

    switch (menu) {
      case 1: // 학생 정보 출력
        printf("학생 이름 : %s\n", stu.name);
        printf("국어 : %d\n", kor);
        printf("영어 : %d\n", eng);
        printf("수학 : %d\n", math);
        break;
      case 2: //학생 정보 입력
        printf("학생 정보를 입력하세요.\n");
        printf("이름 :" ); scanf("%s", name);
				strcpy(stu.name, name); // 이름 입력.
				printf("국어 점수 :" ); scanf("%d", &kor);
				stu.kor = kor; // 국어 점수 입력.
				printf("영어 점수 :" ); scanf("%d", &eng);
				stu.eng = eng; // 영어 점수 입력.
				printf("수학 점수 :" ); scanf("%d", &math);
        stu.math = math; // 수학 점수 입력.
		break;
      case 3: //학생 정보 삭제
        break;
      case 4: //학생 정보 삽입
        break;
      case 5: //학생 정보 삽입
        break;
      case 6: //학생 정보 검색
        break;
      case 7:// 종료
        printf("프로그램 종료\n");
        exit(0);
        break;
     }

  }
  return 0;
}
