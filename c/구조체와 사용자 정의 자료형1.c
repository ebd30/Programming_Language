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

  -구조체 변수의 초기화
int형 변수를 선언과 동시에 초기화할 수 있듯 구조체 변수도 선언과 동시에 초기화할 수 있다. 그리고 초기화 방법은 배열의 초기화와 유사, 동일하다. 즉 멤버의 순서대로 초기화할 대상을 나열하면 된다.

예제InitStructVal.c
#include <stdio.h>
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

int main()
{
  struct point pos={10, 20};
  struct person man={"이승기", "010-1212-1212", 21);
  printf("%d %d \n", pos.xpos, pos.ypos);
  printf("%s %s %d \n", man.name, man.phoneNum, man.age);
  return 0;
}

초기화 과정에서는 문자열 저장을 위해서 strcpy 함수를 호출하지 않아도 된다. TelephoneInfo.c에서는 구조체 변수 선언 이후 구조체의 멤버에 문자열을 저장하기 위해 strcpy() 함수를 호출해야만 했다. 하지만 위 예제와 같이 초기화 과정에서는 멤버에 저장할 데이터를 단순히 나열만하면 된다. 문자열이라도 말이다.


#구조체와 배열 그리고 포인터

  -구조체 배열의 선언과 접근
int num; -> int arr[10]; 과 같듯이 struct point pos -> struct point arr[10]; 로 선언해주면 된다.
int형 변수를 선언할 때 int형 배열의 선언을 고려하듯이, 다수의 구조체 변수를 선언할 때에는 구조체 배열의 선언을 고려해야 한다. 구조체 배열의 선언방법은 일반적인 배열의 선언방법과 동일하다.
ex) struct point arr[4]; point형 구조체 배열을 선언하면

arr[0]   arr[1]   arr[2]   arr[3]
int xpos int xpos int xpos int xpos
int ypos int ypos int ypos int ypos

위 구조로 배열이 할당된다.

예제StructArray.c
#include <stdio.h>
struct point 
{
  int xpos;
  int ypos;
};
int main()
{
  struct point arr[3];
  for(int i=0; i<3; i++)
  {
    printf("점의 좌표 출력: ");
    scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
  }

  for(int i=0; i<3; i++)
    printf("[%d, %d] ", arr[i].xpos, arr[i].ypos);
    
  return 0;
}

  -구조체 배열의 초기화
구조체 변수를 선언과 동시에 초기화할 때에는 다음과 같이 중괄호를 통해서 초기화할 값을 명시한다.
struct person man={"문인성", "010-3232-0922", 21};

구조체 배열을 선언과 동시에 초기화할 때에는 다음과 같이 배열의 길이만큼 중괄호를 이용해서 초기화를 진행하면 된다.
struct person arr[3]={
  {"문인성", "010-3232-0922", 21}, // 첫 번째 요소의 초기화
  {"주인하", "010-3232-0923", 22}, // 두 번째 요소의 초기화
  {"박경희", "010-3232-0924", 23}, // 세 번째 요소의 초기화
};

예제InitStructArray.c
#include <stdio.h>
struct person
{
  char name[20];
  char phoneNum[20];
  int age;
};

int main()
{
  struct person arr[3]={
    {"문인성", "010-3232-0922", 21}, // 첫 번째 요소의 초기화
    {"주인하", "010-3232-0923", 22}, // 두 번째 요소의 초기화
    {"박경희", "010-3232-0924", 23}, // 세 번째 요소의 초기화
  };

  for(int i=0; i<3; i++)
    printf("%s %s %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);
  
  return 0;
}

  -구조체 변수와 포인터
구조체 포인터 변수의 선언 및 연산의 방법도 일반적인 포인터 변수의 선언 및 연산의 방법과 다르지 않다.
int형 포인터 변수 선언 및 초기화
int num=10;
int * iptr=&num;

point형 구조체의 포인터 변수 선언 및 초기화
struct point pos={10,11}; // xpos, ypos 각각 10, 11로 초기화
struct point * pptr=&pos; // 포인터 변수 pptr이 구조체 변수 pos를 가리킴

int형 포인터 변수 iptr을 이용해 변수 num에 접근
*iptr=20;

point형 포인터 변수 pptr을 이용해 구조체 변수 pos에 접근
(*pptr).xpos=10; // pptr이 가리키는 구조체 변수의 멤버 xpos에 10 저장
(*pptr).ypos=20; // pptr이 가리키는 구조체 변수의 멤버 ypos에 20 저장

접근을 위해 포인터 변수를 대상으로 * 연산을 하는 것은 동일하다. 다만 구조체 포인터 변수의 경우 접근하고자 하는 멤버의 선택을 위해 . 연산을 추가했다.
다음과 같이 쓸 수도 있다.

pptr->xpos=10; // pptr이 가리키는 구조체 변수의 멤버 xpos에 10 저장
pptr->ypos=20; // pptr이 가리키는 구조체 변수의 멤버 ypos에 20 저장
즉, *연산과 . 연산을 하나의 -> 연산으로 대체할 수 있는 것이다. 프로그래머들이 편의상 -> 연산자의 사용을 즐긴다.

예제StructPointer.c
#include <stdio.h>
struct point
{
  int xpos;
  int ypos;
};
int main()
{
  struct point pos1={1, 2};
  struct point pos2={100, 200};
  struct point * pptr=&pos1;

  (*pptr).xpos += 4;
  (*pptr).ypos += 5;
  printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

  pptr=&pos2;
  pptr->xpos += 1;
  pptr->ypos += 2;
  printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);
  reuturn 0;
}
어느 정도 익숙해지면 * 연산과 . 연산의 조합으로 바꿔서 해석하는 습관을 버리기 바란다.

  -포인터 변수를 구조체의 멤버로 선언하기
배열이 구조체의 멤버로 선언될 수 있듯, 포인터 변수도 구조체의 멤버가 될 수 있다.
예제Struct PointerMem.c
#include <stdio.h>
struct point
{
  int xpos;
  int ypos;
};
struct circle
{
  double radius;
  struct point *center;
};
int main()
{
  struct point cen={2,7};
  double rad=5.5;

  struct circle ring={rad, &cen};
  printf("원의 반지름: %g \n", ring.radius);
  printf("원의 중심 [%d, %d] \n", (ring.center)->xpos, (ring.center)->ypos);
  return 0;
}

ring
radius=5.5
center->cen

cen
xpos=2
ypos=7
위 예제에서 선언한 구조체 변수 ring, cen의 관계는 위와 같다.

type형 구조체 변수의 멤버로 type형 포인터 변수를 둘 수 있다.
즉 다음과 같은 선언이 가능하다.
struct point
{
  int xpos;
  int ypos;
  sturct point * ptr; // 구조체 point의 포인터 변수 선언
};

예제PointRelation.c
#include <stdio.h>
struct point
{
  int xpos;
  int ypos;
  struct point * ptr;
};
int main()
{
  struct point pos1={1, 1};
  struct point pos2={2, 2};
  struct point pos3={3, 3};

  pos1.ptr = &pos2;
  pos2.ptr = &pos3;
  pos3.ptr = &pos1;

  printf("[%d, %d]와(과) [%d, %d] 연결 \n, pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
  printf("[%d, %d]와(과) [%d, %d] 연결 \n, pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
  printf("[%d, %d]와(과) [%d, %d] 연결 \n, pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
  return 0;
}

  -구조체 변수의 주소 값과 첫 번째 멤버의 주소 값
구조체 변수의 주소 값은 구조체 첫 번째 멤버의 주소 값과 동일하다.
예제StructValAddress.c
#include <stdio.h>
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

int main()
{
  struct point pos={10, 20};
  struct person man={"이승기", "010-1212-0001", 21};
  
  printf("%p %p \n", &pos, &pos.xpos);
  printf("%p %p \n", &man, man.name);
  return 0;
}

*/
