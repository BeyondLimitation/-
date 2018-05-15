#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct node { // 학생 Linked List 구조체 선언
  char name [10];
  int kor;
  int eng;
  int math;
	struct node * link;
}StudentList;

StudentList * get_node() { // 학생 Linked List에 메모리를 할당및 초기 설정.
	StudentList * tmp;
	tmp = (StudentList*)malloc(sizeof(StudentList));
	tmp -> link = NULL;
	return tmp;
}

void Insert(StudentList ** head, char name [10], int kor, int eng, int math) { // 학생 정보 삽입
	if(*head == NULL)
	{
		*head = get_node();
		strcpy( (*head)->name, name);
    (*head) -> kor = kor;
    (*head) -> eng = eng;
    (*head) -> math = math;
    return;
	}
	Insert(&(*head)->link, name, kor, eng, math);
}

void Delete(StudentList ** head, char name [10]) { // 학생 정보 삭제.
  StudentList * tmp;
  if(*head == NULL) {
    printf("학생 목록에 지울 대상이 없습니다!");
  } else {
    if (strcmp( ((*head) -> name), name) == 0 ) { // 이름을 찾음.
      tmp = (*head) -> link;
      free(*head);
      *head = tmp;
    } else { // 찾지 못한 경우
      Delete(&(*head)->link, name);
    }
  }
}

void Edit(StudentList ** head, char name [10], int kor, int eng, int math) {
  if (*head == NULL) { // 학생이 존재하지 않는 경우.
    printf("해당 학생이 존재하지 않습니다!");
    return;
  } else { //이름 검색 단계
    if (strcmp(((*head) -> name), name) == 0 ) { // 이름 찾기
      /* 학생 자료 편집 */
      strcpy( (*head)->name, name);
      (*head) -> kor = kor;
      (*head) -> eng = eng;
      (*head) -> math = math;
    } else {
      /* 찾지 못한 경우 */
      Edit(&(*head)->link, name, kor, eng, math);
    }
  }

}

void Search(StudentList ** head, char name [10]) {
  if(*head == NULL) {
    printf("학생 목록에 지울 대상이 없습니다!");
  } else {
    if (strcmp( ((*head) -> name), name) == 0 ) { // 이름을 찾음.
      printf("이름 : %s\n", (*head) -> name);
      printf("국어 : %d\n", (*head) -> kor);
      printf("영어 : %d\n", (*head) -> eng);
      printf("수학 : %d\n", (*head) -> math);
    } else { // 찾지 못한 경우
      Search(&(*head)->link, name);
    }
  }
}

void Print(StudentList ** head) {
  if(*head != NULL) {
    printf("이름 : %s\n", (*head) -> name);
    printf("국어 : %d\n", (*head) -> kor);
    printf("영어 : %d\n", (*head) -> eng);
    printf("수학 : %d\n", (*head) -> math);
    printf("-------------\n" );
    Print(&(*head)->link);
  }
}

int main() {
	int menu, kor, eng, math;
	char name [10];
	StudentList *head;
	head = NULL;
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
				Print(&head);
        break;
      case 2: //학생 정보 입력
        printf("학생 정보를 입력하세요.\n");
		    printf("이름 :" ); scanf("%s", name);
				printf("국어 점수 :" ); scanf("%d", &kor);
				printf("영어 점수 :" ); scanf("%d", &eng);
				printf("수학 점수 :" ); scanf("%d", &math);
				Insert(&head, name, kor, eng, math);
				break;
      case 3: //학생 정보 수정
				Edit(&head, name, kor, eng, math);
        break;
      case 4: //학생 정보 삭제
				printf("지울 학생의 이름을 입력하세요.");
				printf("이름 :" );
				scanf("%s", name);// 이름 입력
				Delete(&head, name);
        break;
      case 5: //학생 정보 삽입
				printf("학생 정보를 입력하세요.\n");
				printf("이름 :" );
				scanf("%s", name);//이름 입력
				printf("국어 점수 :" );
				scanf("%d", &kor);//국어 점수 입력
				printf("영어 점수 :" );
				scanf("%d", &eng);//영어 점수 입력
				printf("수학 점수 :" );
				scanf("%d", &math);//수학 점수 입력
				Insert(&head, name, kor, eng, math);
        break;
      case 6: //학생 정보 검색
				printf("검색할 학생의 이름을 입력하세요.\n이름 : ");
				scanf("%s", name);//학생 이름 입력
				Search(&head, name);
				break;
      case 7:// 종료
        printf("프로그램 종료\n");
        exit(0);
        break;
     }

  }
  return 0;
}
