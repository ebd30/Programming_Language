/*
#구조체란 무엇인가?

  -구조체의 정의
구조체(structure)라는 것은 하나 이상의 변수(포인터 변수와 배열 포함)를 묶어서 새로운 자료형을 정의하는 도구이다. 즉 구조체를 기반으로 우리는 새로운 자료형을 정의할 수 있다.

  -구조체 변수의 선언과 접근
구조체 변수의 선언방법은 다음과 같다.
struct type_name val_name; // 구조체 변수선언의 기본 형태

ex) 
struct point
{
  int xpos;
  int ypos;
};

struct person
{
  char name[20];
  char phoneNum[20];
  int age;
};
이렇게 구조체가 정의 되고
struct point pos;
struct person man;

구조체 변수가 선언되면 pos, man은 각각 다음의 형태로 존재하게 된다.
pos   
int xpos  
int ypos

man
char name[20]
char phoneNum[20]
int age

각각 위와 같이 구조체 변수의 구성이 이루어진다.

구조체 변수 안에 존재하는 멤버에 접근할 때는 . 연산자를 사용한다.
구조체 변수의 이름.구조체 멤버의 이름

예제TwoPointDistance.c
#include <stdio.h>
#include <math.h>

struct point
{
  int xpos;
  int ypos;
};

int main()
{
  struct point pos1, pos2;
  double distance;

  fputs("point1 pos: ", stdout);
  scanf("%d %d", &pos1.xpos, &pos1.ypos);

  fputs("point2 pos: ", stdout);
  scanf("%d %d", &pos2.xpos, &pos2.ypos);

  distance=sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos)+(pos1.ypos-pos2-ypos)*(pos1.ypos-pos2.ypos)));

  printf("두 점의 거리는 %g 입니다. \n", distance);
  return 0;
}

두 점의 거리를 계산하는 공식은 루트 씌운 (p1.x-p2.x)^2+(p1.y-p2.y)^2 이다.
header파일 math.h에 선언되어 있는 sqrt() 함수를 호출하였다.

double sqrt(double x) // 제곱근 x의 값을 반환

이 정도의 기능은 하나의 함수로 독립을 시키는 것이 여러가지 측면에서 도움이 된다.

구조체의 멤버로 배열이 선언되면 배열의 접근방식을 취하면 되고, 구조체의 멤버로 포인터 변수가 선언되면 포인터 변수의 접근방식을 취하면 된다.

예제TelephoneInfo.c
#include <stdio.h>
#include <string.h>

struct person
{
  char name[20];
  char phoneNum[20];
  int age;
};

int main()
{
  struct person man1, man2;
  strcpy(man1.name, "안이준");
  strcpy(man1.phoneNum, "010-1234-2321");
  man1.age = 23;

  printf("이름 입력: "); scanf("%s", man2.name);
  printf("번호 입력: "); scanf("%s", man2.phoneNum);
  printf("나이 입력: "); scanf("%d", &man2.age);

  printf("이름: %s \n", man1.name);
  printf("번호: %s \n", man1.phoneNum);
  pritnf("나이: %d \n", man1.age);

  printf("이름: %s \n", man2.name);
  printf("번호: %s \n", man2.phoneNum);
  pritnf("나이: %d \n", man2.age);
  
  return 0;
}

다음과 같이 구조체를 정의함과 동시에 변수를 선언할 수 있다.
struct point // 구조체의 정의와 변수의 선언
{
  int xpos;
  int ypos;
} pos1, pos2, pos3;

struct point // 구조체의 정의
{
  int xpos;
  int ypos;
};
struct point pos1, pos2, pos3; // 구조체 변수의 선언

*/
