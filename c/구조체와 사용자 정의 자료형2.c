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

#함수로의 구조체 변수 전달과 반환

  -함수의 인자로 전달되고 return문에 의해 반환되는 구조체 변수
void SimpleFunc(int num){....}
int main()
{
  int age=24;
  SimpleFunc(age); //age에 저장된 값이 매개변수 num에 전달(복사)
  ....
}
위 코드 실행 시, 인자로 전달되는 변수의 값은 매개변수에 복사가 된다.
마찬가지로 함수의 인자로 구조체 변수가 전달될 수 있으며, 이러한 인자를 전달받을 수 있도록 구조체 변수가 매개변수의 선언으로 올 수 있다. 그리고 전달되는 구조체 변수의 값은 매개변수에 통째로 복사가 된다.

예제StructValFunction.c
#include <stdio.h>
typedef struct point
{
  int xpos;
  int ypos;
} Point;

void ShowPosition(Point pos)
{
  printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

Point GetCurrentPosition(void)
{
  Point cen;
  printf("Input current pos: ");
  scanf("%d %d', &cen.xpos, &cen.ypos);
  return cen;
}

int main()
{
  Point curPos=GetCurrentPosition();
  ShowPosition(curPos);
  return 0;
}

그리고 구조체의 멤버로 배열이 선언되어도 위 예제에서 보인 것과 동일한 형태의 복사가 진행된다. 즉 인자의 전달과정에서 값의 반환과정에서 구조체의 멤버로 선언된 배열도 통째로 복사가 된다.
예제StructMemArrCopy.c
#include <stdio.h>
typedef struct person
{
  char name[20];
  char phoneNum[20];
  int age;
} Person;

void ShowPersonInfo(Person man)
{
  printf("name: %s \n", man.name);
  printf("phone: %s \n", man.phoneNum);
  printf("age: %d \n", man.age);
}

Person ReadPersonInfo(void)
{
  Person man;
  printf("name? "); scanf("%s", man.name);
  printf("phone? "); scanf("%s", man.phoneNum);
  printf("age? "); scanf("%d", &man.age);
  return man;
}

int main()
{
  Person man=ReadPersonInfo();
  ShowPersonInfo(man);
  return 0;
}

실행결과는 인자의 전달과정에서, 그리고 값의 반환과정에서 구조체의 멤버로 선언된 배열도 통째로 복사됨을 보이고 있다.

예제StructFunctionCallByRef.c
#include <stdio.h>
typedef struct point
{
  int xpos;
  int ypos;
} Point;

void OrgSymTrans(Point * ptr)
{
  ptr->xpos = (ptr->xpos) * -1;
  ptr->ypos = (ptr->xpos) * -1;
}

void ShowPosition(Point pos)
{
  printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

int main()
{
  Point pos={7, 5};
  OrgSymTrans(&pos);
  ShowPosition(pos);
  OrgSymTrans(&pos);
  ShowPosition(pos);
  return 0;
}

위 예제 OrgSymTrans()함수에서 보이는 바와 같이 구조체의 포인터 변수도 매개변수로 선언이 되어서 Call-by-reference 형태의 함수호출을 구성할 수 있다.

  -구조체 변수를 대상으로 가능한 연산
구조체 변수를 대상으로는 제한된 형태의 연산만 허용이 된다. 허용되는 가장 대표적인 연산은 대입연산이며, 그 이외로 주소 값 반환을 목적으로 하는 &연산이나 구조체 변수의 크기를 반환하는 sizeof() 정도의 연산만 허용이 된다.
예제StructOperation.c
#include <stdio.h>
typedef struct point
{
  int xpos;
  int ypos;
} Point;

int main()
{
  Point pos1={1, 2};
  Point pos2;
  pos2=pos1; // pos1의 멤버 대 pos2의 멤버간 복사가 진행됨

  printf("크기: %d \n", sizeof(pos1)); // pos1의 전체 크기 반환
  printf("[%d, %d] \n", pos1.xpos, pos1.ypos);
  printf("크기: %d \n", sizeof(pos2)); // pos2의 전체 크기 반환
  printf("[%d, %d] \n", pos2.xpos, pos2.ypos);
  return 0;
}
구조체 변수간 대입연산의 결과로 멤버 대 멤버의 복사가 이뤄짐을 확인할 수 있다.

위 예제에서 정의한 Point 구조체만 놓고 보면 구조체 변수를 대상으로도 덧셈,뺄셈이 가능할 것처럼 보이지만 구조체 안에는 배열,포인터 변수도 또한 다른 구조체의 변수도 존재할 수 있다. 따라서 구조체 변수 대상의 덧셈과 뺄셈연산의 결과를 정형화하는 데는 무리가 있다.
구조체 변수를 덧셈이나 뺄셈을 하려면 함수를 직접 정의해야 한다.
예제StructAddMin.c
#include <stdio.h>
typedef struct point
{
  int xpos;
  int ypos;
} Point;

Point AddPoint(Point pos1, Point pos2)
{
  Point pos={pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos};
  return pos;
}

Point MinPoint(Point pos1, Point pos2)
{
  Point pos={pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos};
  return pos;
}

int main()
{
  Point pos1={5, 6};
  Point pos2={2, 9};
  Point result;
  result = AddPoint(pos1, pos2);
  printf("[%d, %d] \n", result.xpos, result.ypos);
  result = MinPoint(pos1, pos2);
  printf("[%d, %d] \n", result.xpos, result.ypos);
  return 0;
}


#구조체의 유용함에 대한 논의와 중첩 구조체

  -구조체를 정의하는 이유
구조체를 통해서 연관 있는 데이터를 하나로 묶을 수 있는 자료형을 정의하면, 데이터의 표현 및 관리가 용이해지고, 그만큼 합리적인 코드를 작성할 수 있게 된다.
예제StructImportant.c
#include <stdio.h>
typedef struct student
{
  char name[20]; // 학생 이름
  char stdnum[20]; // 학생 고유번호
  char school[20]; // 학교 이름
  char major[20]; // 선택 전공
  int year; // 학년
} Student;

void ShowStudentInfo(Student * sptr)
{
  printf("학생 이름: %s \n", sptr->name);
  printf("학생 고유번호: %s \n", sptr->stdnum);
  printf("학교 이름: %s \n", sptr->school);
  printf("선택 전공: %s \n", sptr->major);
  printf("학년: %d \n", sptr->year);
}

int main()
{
  Student arr[7];

  for(int i=0; i<7; i++)
  {
    printf("이름: "); scanf("%s", arr[i].name);
    printf("번호: "); scanf("%s", arr[i].stdnum);
    printf("학교: "); scanf("%s", arr[i].school);
    printf("전공: "); scanf("%s", arr[i].major;
    printf("학년: "); scanf("%d", &arr[i].year);
  }

  for(int i=0; i<7; i++);
    ShowStudentInfo(&arr[i]);
  return 0;
}

구조체를 정의하지 않고 위 예제와 동일한 코드를 작성하기 어려울 것이다. 하나의 배열에 모든 데이터를 저장할 수 없게 되고, 때문에 다수의 배열이 필요하게 된다. 출력할 데이터의 종류만큼 매개변수가 선언되어야 하기 때문이다.

  -중첩된 구조체의 정의와 변수의 선언
구조체 안에 구조체 변수가 멤버로 존재하는 경우를 가리켜 '구조체의 중첩'이라 한다.
예제CircleIncludePoint.c
#include <stdio.h>
typedef struct point 
{
  int xpos;
  int ypos;
} Point;

typedef struct circle
{
  Point cen;
  double rad;
} Circle;

void ShowCircleInfo(Circle * cptr)
{
  printf("[%d, %d] \n", (cptr->cen).xpos, (cptr->cen).ypos);
  printf("radius: %g \n\n", cptr->rad);
}

int main()
{
  Circle c1={{1, 2}, 3.5};
  Circle c2={{2, 4, 3.9};
  ShowCircleInfo(&c1);
  ShowCircleInfo(&c2);
  return 0;
}
참고로 구조체 변수를 초기화하는 경우에도 배열의 초기화와 마찬가지로 초가화하지 않은 일부 멤버에 대해서는 0으로 초기화가 진행된다.


#공용체(Unidon Type)의 정의와 의미

  -struct구조체 VS union공용체
동일한 구성의 멤버를 이용해 구조체, 공용체를 각각 정의해 보겠다.
typedef struct sbox // 구조체 sbox 정의
{
  int mem1;
  int mem2;
  double mem3;
} SBox;

typedef union ubox // 공용체 ubox 정의
{
  int mem1;
  int mem2;
  double mem3;
} UBox;
정의방식에서 유일한 차이는 struct 선언을 하냐, union 선언을 하냐에 있다. 하지만 각가의 변수가 메모리 공간에 할당되는 방식과 접근의 결과에는 많은 차이가 있다.

printf("%d \n", sizeof(SBox)); // 16, 모든 멤버의 크기를 합한 결과
printf("%d \n", sizeof(UBox)); // 8, 멤버 중 가장 크기가 큰 double의 크기만 계산된 결과

예제UnionMemAlloc.c
#include <stdio.h>
typedef struct sbox // 구조체 sbox 정의
{
  int mem1;
  int mem2;
  double mem3;
} SBox;

typedef union ubox // 공용체 ubox 정의
{
  int mem1;
  int mem2;
  double mem3;
} UBox;

int main()
{
  SBox sbx;
  UBox ubx;
  printf("%p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3);
  printf("%p %p %p \n", &ubx.mem1, &ubx.mem2, &ubx.mem3);
  printf("%d %d \n", sizeof(SBox), sizeof(Ubox));
  return 0;
}
실행결과에서 가장 주목할 부분은 UBox형 변수를 구성하는 멤버 mem1, mem2, mem3의 주소 값이 동일하다는 것이다.

구조체 변수
int mem1----
int mem2----
double mem3--------

공용체 변수
----double----
<-mem1->
<-mem2->
<----mem3---->

구조체 변수가 선언되면, 구조체를 구성하는 멤버는 각각 할당이 된다. 반면 공용체 변수가 선언되면, 공용체를 구성하는 멤버는 각각 할당되지 않고 크기가 가장 큰 멤버의 변수만 하나 할당되어 이를 공유한다. 
예제UnionValAccess.c
#include <stdio.h>
typedef union ubox // 공용체 ubox 정의
{
  int mem1;
  int mem2;
  double mem3;
} UBox;

int main()
{
  UBox ubx; // 8byte allocation
  ubx.mem1=20;
  printf("%d \n", ubx.mem2);

  ubx.mem3=7.15;
  printf("%d \n", ubx.mem1);
  printf("%d \n", ubx.mem2);
  printf("%d \n", ubx.mem3);
  return 0;
}

  -공용체의 유용함은 다양한 접근방식을 제공하는데 있습니다
공용체의 유용함은 간단히 설명되지 않는데 결과적으로는 '하나의 메모리 공간을 둘 이상의 방식으로 접근할 수 있다.'는 것으로 정리가 되지만, 유용하게 사용이 되는 상황은 분야별로 차이가 있기 때문이다.

공용체의 유용함을 이해할 수 있는 상황 연출
민선:수진아 교수님이 과제 내줬어
수진: 뭔 과제?

민선: 프로그램 사용자로부터 int형 정수 하나를 입력 받으래
수진: 그리고?

민선: 입력 받은 정수 상위 2byte, 하위 2byte 값을 양으로 출력하고, 그 다음엔 상위 1byte, 하위 1byte에 저장된 값의 아스키 문자 출력하래
수진: 흠... 아마도 공용체 이용하라는 과제같아.

예제UsefulUnionAccess.c
#include <stdio.h>
typedef struct dbshort
{
  unsigned short upper;
  unsigned short lower;
} DBShort;

typedef union rdbuf
{
  int iBuf;
  char bBuf[4];
  DBShort sBuf;
} RDBuf;

int main()
{
  RDBuf buf;
  printf("정수 입력: ");
  scanf("%d", &(buf.iBuf));
  printf("상위 2byte: %u \n", buf.sBuf.upper);
  printf("하위 2byte: %u \n", buf.sBuf.lower);
  printf("상위 1byte ascii code: %c \n", buf.bBuf[0]);
  printf("하위 1byte ascii code: %c \n", buf.bBuf[3]);
  return 0;
}

공용체 변수는 메모리 공간에 다음의 형태로 할당되고 공유된다.

buf
|  1byte  || 1byte   || 1byte   || 1byte   |
< bBuf[0] >< bBuf[1] >< bBuf[2] >< bBuf[3] >
<-----sBuf.upper-----><-----sBuf.lower----->
<-------------------iBuf------------------->


#열거형(Enumerated Type)의 정의와 의미

  -열거형의 정의와 변수의 선언
간단한 열거형을 하나 정의해보겠다.
enum syllable // syllable이라는 열거형 정의
{
  Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7
};
위 열거형은 다음의 의미를 지닌다. syllable형 변수에 저장 가능한 정수 값들을 결정하고, syllable형 변수에는 1, 2, 3, 4, 5, 6, 7 저장이 가능하다.
언뜻 보면 정의방식이 구조체와 차이가 있어 보이나 그 기본적인 구성은 동일하다. struct 대신에 enum이 왔고, 구조체 정의방식과 마찬가지로 enum에 이어서 자료형의 이름 syllable이 선언됐고, 관련된 내용은 중괄호 안에 선언됐다.

Do=1 
Do를 정수 1을 의미하는 상수로 정의한다. 그리고 이 값은 syllable형 변수에 저장 가능하다. 라는 의미를 지닌다.

즉, 위 열거형 정의에서 Do, Re, Mi, Fa, So, La, Ti라는 이름의 상수를 각각 1, 2, 3, 4, 5, 6, 7로 정의하고, syllable형 변수가 저장할 수 있는 값들로 제한한 것이다.

예제EnumTypeTone.c








*/
