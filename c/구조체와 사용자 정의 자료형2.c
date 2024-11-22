/*
#구조체의 정의와 typedef 선언

  -typedef 선언
typedef 선언은 기존에 존재하는 자료형의 이름에 새 이름을 부여하는 것을 목적으로 하는 선언이다. 
ex) typedef int INT; // int의 또 다른 이름 INT를 부여
이로 인해 자료형의 이름 int에 INT라는 이름을 추가로 붙여준다라는 뜻을 컴파일러에게 전달하게 된다.
INT num; // int num; 과 동일한 선언
INT * ptr; // int * ptr; 과 동일한 선언

예제TypeNameTypedef.c
#include <stdio.h>
typedef int INT;
typedef int * PTR_INT;
typedef unsigned int UINT;
typedef unsigned int * PTR_UINT;
typedef unsigned char UCHAR;
typedef unsigned char * PTR_UCHAR;

int main()
{
  INT num1 = 120; // int num1 = 120;
  PTR_INT pnum1 = &num1; // int * pnum1 = &num1;

  UINT num2 = 190; // unsigned int num2 = 190;
  PTR_UINT pnum2 = &num2; // unsigned int * pnum2 = &num2

  UCHAR ch = 'Z' // unsigned char ch= 'Z';
  PTR_UCHAR pch = &ch; // unsigned char * pch = &ch

  printf("%d, %u, %c \n", *pnum1, *pnum2, *pch);
  reuturn 0;
}

typedef 선언에 있어서 새로운 이름의 부여는 가장 마지막에 등장하는 단어를 중심을 이뤄진다. 즉 다음의 형태로 typedef가 선언되면
typedef name1 name2 name3;
가장 마지막에 등장한 name3가 'name1 name2'에 부여된 새로운 이름이 되는 것이다.
typedef로 정의되는 자료형의 이름은 대문자로 시작하는 것이 관례이다. 그래야 기본 자료형의 이름과 typedef로 새로 정의된 자료형의 이름을 구분할 수 있기 때문이다.

  -구조체의 정의와 typedef 선언
구조체 변수의 선언에 있어서 struct 선언을 생략할 수 있는 방법이 있다.
ex)
struct point
{
  int xpos;
  int ypos;
};
이 상황에서는 struct point pos; 같이 구조체 변수를 선언해야 한다.
typedef struct point Point; //struct point에 Point라는 이름을 부여
typedef선언이 이뤄지고 나면 struct point를 대신할 수 있도록 Point라는 이름을 정의한 것이다.
이후로는
Point pos;
선언이 가능하다.

모든 구조체의 이름을 대상으로 struct 선언의 생략을 위한 typedef 선언이 등장한다. 때문에 다음과 같이 구조체의 정의와 typedef의 선언을 한데 묶을 수도 있고, 또 이렇게 선언하는 것이 보다 일반적이다.
typedef struct point
{
  int xpos;
  int ypos;
} Point;
또는
struct point
{
  int xpos;
  int ypos;
};
typedef struct point Point;

예제StructTypedef.c
#include <stdio.h>
struct point 
{
  int xpos;
  int ypos;
};
typedef struct point Point;

typedef struct person
{
  char name[20];
  char phoneNum[20];
  int age;
} Person;

int main()
{
  Point pos={10, 20};
  Person man={"이승기", "010-1212-0001", 21};
  printf("%d %d \n", pos.xpos, pos.ypos);
  printf("%s %s %d \n", man.name, man.phoneNum, man.age);
  return 0;
}

참고로 typedef 선언이 추가되었다고 해서 struct 선언을 통한 구조체 변수의 선언이 불가능한 것은 아니다.
즉 다음과 같이 구조체가 정의되면
typedef struct point
{
  int xpos;
  int ypos;
} Point;
두 가지 방식으로 구조체 변수를 선언할 수 있다.
Point pos1; // typedef 선언을 이용한 변수의 선언이 가능
struct point pos2; // struct 선언을 추가한 형태의 변수선언이 가능

위의 구조체를 가리켜 point 구조체라 부르기도 하고, Point 구조체라 부르기도 한다. 어떻게 부르는지는 상관없지만 typedef로 정의된 이름으로 해당 구조체를 가리키는 것이 일반적이다.

  -구조체의 이름 생략
typedef struct person
{
  char name[20];
  char phoneNum[20];
  int age;
} Person;
이렇게 정의가 되면, 구조체의 이름 person은 사실상 별 의미를 갖지 않게 된다. 구조체 변수를 선언할 때도 typedef에 의해 정의된 이름 Person을 사용하기 때문이다. 
다음과 같이 구조체의 이름을 생략하는 것도 가능하다.
typedef struct
{
  char name[20];
  char phoneNum[20];
  int age;
} Person;
단, 위와 같이 구조체의 이름을 생략하면, 다음의 형태로는 구조체 변수를 선언할 수 없게 된다.
struct person man; // 불가능한 선언이다.
구조체의 이름이 생략 가능함을 잊지 말자.



*/
