/*
#파일의 분할
현명한 프로그래머들은 여러 개의 파일을 만들어서 서로 연관 있는 함수와 변수들을 구분해서 담는다.

  -파일을 그냥 나눠도 될까요?
두 개의 서랍장이 있다. 하나는 수납공간이 통으로 되있고, 하나는 크고 작은 여러 개의 공간으로 수납공간이 나눠진 서랍장이다. 당연히 여러 개의 공간으로 나눠진 서랍장이 물건관리가 용이하다.
파일을 나누는 이유도 별반 차이가 없다. 파일을 나눠서 각각의 파일에, 용도 및 특성 별로 함수와 변수를 나눠서 저장하면 소스코드의 관리가 용이해진다.

예제SimpleOneFile.c
#include <stdio.h>
int num=0;
void Increment(void)
{
  num++;
}
int GetNum(void)
{
  return num;
}
int main()
{
  printf("num: %d\n", GetNum());
  Increment();
  printf("num: %d\n", GetNum());
  Increment();
  printf("num: %d\n", GetNum());
  return 0;
}

이 파일을 다음과 같이 총 세 개의 파일로 나눠서 저장한다 가정해보자. 단, 헤더파일 선언은 각각의 파일에 적절히 이뤄졌다고 가정하겠으니 문제 삼지는 말자.
단순한 구조의 파일 분할
int num=0; -> num.c

void Increment(void) -> func.c
{
  num++;
}
int GetNum(void)
{
  return num;
}

int main() -> main.c
{
  printf("num: %d\n", GetNum());
  Increment();
  printf("num: %d\n", GetNum());
  Increment();
  printf("num: %d\n", GetNum());
  return 0;
}

안타깝게도 위 형태로 파일을 나누면 컴파일 시 에러가 발생하는데, 에러의 발생 이유는 컴파일러의 다음과 같은 특성 때문이다.

"컴파일러는 파일 단위로 컴파일을 진행합니다."

컴파일러는 다른 파일의 정보를 참조하여 컴파일을 진행하지 않는다. 때문에 위 파일 func.c를 컴파일하면 다음과 같은 불평을 한다.

"변수 num이 어디에 선언되있습니까?"

그리고 main.c를 컴파일 하면서도 다음과 같은 불평을 한다.

"Increment 함수는 정의된 적이 없습니다."

사용자는 변수 num, 함수 Increment 가 각 num.c, func.c에 정의되어 있는 것을 알지만 컴파일러는 이를 인식하지 못한다.
컴파일러는 func.c 안에서만 변수 num의 선언을 찾고, main.c 안에서만 Increment 함수의 정의를 찾다가 에러 메시지를 출력할 뿐이다.

  -외부에 선언 및 정의되었다고 컴파일러에게 알려줘야 합니다!
파일을 분할해서 컴파일 하기 위해서는 컴파일러에게 다음과 같은 내용의 메세지를 전달해야 한다.
"num은 외부 파일에 int형으로 선언된 변수다."
"Increment는 반환형과 매개변수의 형이 void이 함수인데, 외부 파일에 정의돼있다."

이 중 첫 번째 메시지는 func.c를 컴파일 할 때 필요하다. 따라서 func.c 에는 다음의 선언이 삽입돼야 하는데 여기서 extern은 int형 변수 num이 외부에 선언되었음을 컴파일러에게 알릴 때 사용하는 키워드다.
extern int num; // int형 변수 num이 외부에 선언돼있다.

즉 위의 선언은 변수 num을 할당하는 선언이 아닌 num의 자료형이 무엇이고, 어디에 선언돼있는지 컴파일러에게 알려주는 메시지일 뿐이다. 그리고 두 번째 메시지는 main.c에 필요하다. 
따라서 main.c에는 다음의 선언이 삽입돼야한다.
extern void Increment(void); // void Increment(void) 함수가 외부에 정의돼있다.

참고로 함수가 외부에 정의되어 있음을 알릴 때에는 extern 선언을 생략할 수 있다. 즉 다음과 같이 선언해도 동일한 메시지가 컴파일러에게 전달된다.
void Increment(void); = extern void Increment(void);

컴파일러 에러 메시지의 해결을 위해서 소스코드가 다음과 같이 정정돼야 함을 알 수 있다.

컴파일을 위한 extern 선언
int num=0; -> num.c

extern int num; -> func.c
void Increment(void)
{
  num++;
}
int GetNum(void)
{
  return num;
}

extern void Increment(void); -> main.c
extern int GetNum(void);
int main()
{
  printf(....);
  Increment();
  .....
}
참고로 컴파일러에게는 extern 선언을 통해서 함수 또는 변수가 외부에 선언 및 정의돼있다는 사실만 알리면 된다. 구체적으로 어느 파일에 선언 및 정의되어 있는지 까지 알리지 않아도 된다.

  -다른 파일에서 접근을 못하게 하고 싶다면 static!
'static 지역변수'에 대해서 공부했을 것이다. 이를 이어서 'static 전역변수'에 대해 설명하고자 한다. 
전역변수의 static 선언은 다음과 같은 의미를 담는다.

"이 변수는 외부 팡리에서의 접근을 허용하지 않는다."

이를 다소 전문적으로 표현하면 다음과 같다.

"이 변수의 접근범위는 파일 내부로 제한한다."

num.c에 선언된 변수 num을 다음과 같이 선언하면 func.c에서는 변수 num에 접근할 수 없어서 컴파일 오류가 발생한다.
static int num=0;

이처럼 static 전역변수는 접근의 범위를 파일의 내부로 제한하는 경우에 사용된다.


#둘 이상의 파일을 컴파일하는 방법과 static에 대한 고찰

  -파일부터 정리하고 시작합시다!
파일을 생성하고 프로젝트에 추가하는 방법에는 두 가지가 있다.
첫 번째 방법: 파일을 먼저 생성해서 코드를 삽입한 다음에 프로젝트를 추가한다.
두 번째 방법: 프로젝트에 파일을 추가한 다음에 코드를 삽입한다.

첫 번째 방법에서는 파일을 먼저 생성해서 코드를 삽입한다고 했는데, 이 때 메모장을 포함한 어떠한 편집기를 사용해도 된다. 하지만 이는 일반적으로 컴파일 할 파일이 이미 존재하는 경우에 사용하는 방법이다. 
두 번째 방법은 새로운 파일을 추가해서 코드를 직접 입력하는 경우에 사용하는 방법이다.

  -함수에도 static 선언을 할 수 있습니다.
전역변수에 static 선언을 할 수 있듯이 함수에도 static 선언을 할 수 있다. 그리고 그 의미는 static전역변수와 마찬가지로 파일 내에서만 접근이 가능하도록 함수를 제한하는 것이다.
static void MinCnt(void)
{
  cnt--;
}
함수가 위와 같이 정의되면, extern 선언을 하더라도 다른 파일에서는 접근이 불가능하다. 그리고 이는 코드의 안전성을 높이는 역할을 하는 만큼(파일의 외부에서 원치 않게 호출되는 것을 막을 수 있다.), 파일 내에서만 호출하기 위해서 정의된 함수라면 이렇듯 static 선언을 추가해 코드에 안전성을 부여하는 것이 좋다.


#헤더파일의 디자인과 활용


  -#include 지시자의 의미를 알면 헤더파일을 완전히 이해할 수 있습니다.
먼저 #include 지시자의 의미를 이해하면 헤더파일을 이해할 수 있을 뿐 아니라, 헤더파일에 무엇을 담아야 할지도 알 수 있게 된다.

예제header1.h
{
  puts("Hello World!");

예제header2.h
  return 0;
}

예제main.c
#include <stdio.h>

int main(void)
#include "header1.h"
#include "header2.h"

언뜻 보면 정상적인 프로그램인가? 하는 의심이 든다. 하지만 정상적인 프로그램이 맞다. 일단 프로그램의 분석을 위해 다음 문장의 의미를 설명하자면
#include "header1.h"
이는 다음과 같은 메시지를 선행처리기에게 전달하는 것이다.
"이 문장의 위치에다가 header1.h에 저장된 내용을 가져다 놓으세요."
유사하게 main.c의
#include "header2.h"
문장도 마찬가지로
"이 문장의 위치에다가 header2.h에 저장된 내용을 가져다 놓으세요."

이처럼 #include 지시자는 그 이름이 의미하듯이 파일의 내용을 단순히 포함시키는 용도로 사용된다. 단순한 '포함'일 뿐이다.

  -헤더파일을 include 하는 두 가지 방법
헤더파일을 포함하는 방식에는 두 가지가 있다.

#include <헤더파일 이름> // 첫 번째 방식
#include "헤더파일 이름" // 두 번째 방식

이 둘의 유일한 차이점은 포함시킬 헤더파일의 기본 경로인데
첫 번째 방식을 사용하면 표준 헤더파일(C의 표준에서 정의하고 있는, 기본적으로 제공되는 헤더파일)이 저장되어 있는 디렉터리에서 파일을 찾게 된다. 때문에 이 방식은 stdio.h, stdlib.h, string.h 등과 같은 표준 헤더파일을 포함시킬 경우 사용된다.
두 번째 방식을 사용하면 이 문장을 포함하는 소스파일이 저장된 디렉터리에서 헤더파일을 찾는다. 때문에 프로그래머가 정의하는 헤더파일을 포함시킬 때 사용하는 방식이다. 그리고 이 방식을 사용하면 헤더파일의 이름뿐만 아니라 드라이브 명과 디렉터리 경로를 포함하는 '절대경로(완전경로)'를 명시해서 헤더파일을 지정할 수 있다.
#include "C:\CPower\MyProject\header.h" //Windows 상에서의 절대경로 지정
#include "/CPower/MyProject/header.h" //Linux 상에서의 절대경로 지정

절대경로를 이용하면 헤더파일의 위치를 완벽히 알려줄 수 있다. 하지만 프로그램 개발에서는 특별한 이유가 없으면 절대경로를 사용하지 않는다. 절대경로를 지정해서 헤더파일을 선언하면 다른 컴퓨터에서 컴파일 하는 일이 매우 번거로워진다.
그래서 #include 문에서는 절대경로를 사용하지 않는다. 대신 상대경로를 사용한다.

  -상대경로의 지정 방법
드라이브 명과 디렉터리 경로를 포함하는 방식을 가리켜 '절대경로'라 하는 이유는 "절대로 경로가 변경되지 않는다. 컴퓨터로 옮겨도 지정한 경로는 병경되지 않는다"는 이유다.
반면, 상대경로는 말 그대로 상대적인 경로이다. 즉 실행하는 컴퓨터의 환경에 따라서 경로가 바뀌기 때문에 '상대경로'라 하는 것이다. 
예를 들어서 헤더파일을 다음과 같이 포함시켰다고 가정하자(참고로 이것도 상대경로 지정방식이다.)
#include "header.h"
이 문장의 헤더파일 검색경로를 알 수 없다. 왜냐하면 상대적이기 때문이다. 이 문장을 포함하는 소스파일이 C:\AAA에 저장돼있다면 이 문장의 헤더파일 검색경로도 C:\AAA가 된다. 
반면 이 문장을 포함하는 소스파일이 C:\AAA\BBB에 저장됐다면, 이 문장의 헤더파일 검색경로 역시 C:\AAA\BBB가 된다. 그리고 상대경로는 다음과 같은 형태로도 지정이 가능하다.(때문에 상대경로가 절대경로보다 훨씬 유용하다)

#include "Release\header0.h" // 소스파일이 있는 디렉터리 하위 디렉터리인 Release 디렉터리에 존재하는 header0.h를 포함하라
#include "..\CProg\header1.h" // 한 단계 상위 디렉터리의 하위 디렉터리인 CProg에 존재하는 header1.h를 포함하라
#include "..\..\MyHeader\header2.h" // 두 단계 상위 디렉터리의 하위 디렉터리인 MyHeader에 존재하는 header2.h를 포함하라

이렇듯 상대경로를 기반으로 헤더파일을 선언하면, 드라이브 명이나 디렉터리 위치에 덜 영향을 받는다. 때문에 실제로는 상대경로를 기반으로 헤더파일이 선언되며, 그렇기 때문에 사용자는 상대경로를 이용하는 습관을 들여야 한다.

  -헤더파일에 무엇을 담으면 좋겠습니까?
기본적으로 헤더파일에는 다음과 같은 유형의 선언을 담게 된다.
extern int num;
extern int GetNum(void); // extern 생략 가능

외부에 선언된 변수에 접근하거나 외부에 정의된 함수를 호출하기 위한 선언들인데, 이들은 둘 이상의 소스파일로 이뤄진 프로그램에서 당연히 삽입될 수 밖에 없는 유형의 선언들이다. 그런데 필요할 때마다 매번 삽입하는 것은 번거롭다.
따라서 이들 선언을 헤더파일에 모아두고 필요할 때마다 헤더파일을 포함시키는 방법을 택한다. 이와 관련해 다음 예제를 보자. 예제는 총 7개의 파일로 이뤄져있다.
예제basicArith.h
#define PI 3.1415
double Add(double num1, double num2);
double Min(double num1, double num2);
double Mul(double num1, double num2);
double Div(double num1, double num2);

예제basicArith.h
double Add(double num1, double num2)
{
  return num1+num2;
}
double Min(double num1, double num2)
{
  return num1-num2;
}
double Mul(double num1, double num2)
{
  return num1*num2;
}
double Div(double num1, double num2)
{
  return num1/num2;
}

basicArith.c에는 사칙연산의 기능을 제공하는 함수들이 정의돼있다. 그리고 이 함수들의 선언을 basicArith.h에 모아두었으므로 basicArith.c에 정의된 함수의 호출을 위해서는 헤더파일 basicArith.h를 포함시켜야한다.

그리고 '매크로의 명령문도 파일 단위로만 유효'하기 때문에(선행처리기도 파일 단위로 선행처리한다.) 매크로 PI에 대한 정의가 헤더파일 basicArith.h에 삽입됐다.때문에 매크로 PI를 필요로 하는 소스파일은 헤더파일 basicArith.h를 포함시키기만 하면 된다.

예제areaArith.h
double TriangleArea(double base, double height);
double CircleArea(double rad);

예제areaArith.c
#include "basicArith.h"
double TriangleArea(double base, double height)
{
  return Div(Mul(base, heigth), 2);
}
double CircleArea(double rad)
{
  return Mul(Mul(rad, rad), PI);
}

areaArith.c에는 면적을 구하는 함수들이 정의돼있다. 그런데 이 함수들은 basicArith.c에 정의된 함수를 호출하기 때문에 헤더파일 basicArith.h를 포함시켜야 한다.

예제roundArith.h
double RectangleRound(double base, double height);
double SquareRound(double side);

예제roundArith.c
#include "basicArith.h"
double RectnagleRound(double base, double height)
{
  return Mul(Add(base, height), 2);
}
double SquareRound(double side)
{
  return Mul(side, 4);
}

roundArith.c에는 둘레를 구하는 함수들이 정의돼있다. 이 함수들 역시 basicArith.c에 정의된 함수를 호출하기 때문에 헤더파일 basicArith.h를 포함시켜야 한다.

잠깐 헤더파일의 유용함을 관찰하자면 만약 헤더파일 basicArith.h가 존재하지 않았다면, 소스파일 areaArith.c, roundArith.c에서 호출하고 있는 함수의 선언을 각각의 소스파일에 추가해야한다. 번거로운 과정을 거쳐야만 하는 것이다.
그러나 헤더파일을 만들었기 때문에 한 줄의 #include 문으로 모든 것이 해결됐다. 이것이 바로 헤더파일의 유용함이다. 

예제main.c
#include <stdio.h>
#include "areaArith.h"
#include "roundArith.h"
int main()
{
  printf("삼각형 넓이(밑변 4, 높이 2): %g \n", TriangleArea(4, 2));
  printf("원 넓이(반지름 3): %g \n", CircleArea(3));

  printf("직사각형 둘레(밑변 2.5, 높이 5.2): %g \n", RectangleRound(2.5, 5.2));
  printf("정사각형 둘레(변의 길이 3): %g \n", SquareRound(3));
  return 0;
}

  -구조체의 정의는 어디에 둘까요? 그런데 중복은 안됩니다.
구조체는 프로그램 개발에서 빠질 수 없는 중요한 요소이다. 그렇다면 구조체의 선언(typedef 선언)및 정의는 어디에 두는 것이 정답일까? 소스파일일까 아님 헤더파일일까? 
두 개의 파일로 이뤄진 다음 예제를 참조해 감을 잡아보자.

예제intdiv.c
typedef struct div
{
  int quotient; // 몫
  int remainder; // 나머지
} Div;
Div IntDiv(int num1, int num2)
{
  Div dval;
  dval.quotient=num1/num2;
  dval.remainder=num1%num2;
  return dval;
}

예제main.c
#include <stdio.h>
typedef struct div
{
  int quotient; // 몫
  int remainder; // 나머지
} Div;
extern Div IntDiv(int num1, int num2);
int main()
{
  Div val=IntDiv(5, 2);
  printf("몫: %d \n", val.quotient);
  printf("나머지: %d \n", val.remainder);
  return 0;
}

분석하는 과정에서 다음 사실에 놀라지 않을 수 없다. 구조체 Div의 선언 및 정의가 두 번씩이나 삽입됐다는 사실이다.
처음 보면 상당히 이상하게 보이지만 앞서 설명한 다음 사실을 기억하면 전혀 이상하지 않다. 컴파일러는 파일 단위로 컴파일을 진행한다.

컴파일러는 다른 파일의 정보를 참조해 컴파일을 진행하지 않는다. 때문에 구조체 Div에 대한 선언 및 정의는 Div를 필요로 하는 모든 파일에 존재해야 한다.
헤더파일을 만들어 Div의 선언 및 정의가 프로그램 내에서 하나만 존재하도록 개선가능하다. 동일한 구조체의 정의가 두 군데 이상 존재하면 구조체의 수정 및 확장에 불편함이 따르기 때문이다.

예제stdiv.h
typedef struct div
{
  int quotient; // 몫
  int remainder; // 나머지
} Div;

예제intdiv2.c
#include "stdiv.h"
Div IntDiv(int num1, int num2)
{
  Div dval;
  dval.quotient=num1/num2;
  dval.remainder=num1%num2;
  return dval;
}

예제main.c
#include <stdio.h>
#include "stdiv.h"
extern Div IntDiv(int num1, int num2);
int main()
{
  Div val=IntDiv(5, 2);
  printf("몫: %d \n", val.quotient);
  printf("나머지: %d \n", val.remainder);
  return 0;
}

구조체의 선언 및 정의는 헤더파일에 삽입하는 것이 좋다. 그러나 하나의 소스파일 내에서만 사용되는 구조체라면 소스파일에 정의하는 것도 좋다.

  -헤더파일의 중복삽입 문제
일단 구조체의 선언 및 정의는 헤더파일에 삽입하는 것이 좋다는 결론이 내려졌지만 이는 자칫 컴파일 에러의 원인으로 이어질 수 있어 주의해야한다.
총 네 개의 파일로 이뤄진 다음 예제를 통해 주의할 점을 살펴보자.

예제stdiv.h
typedef struct div
{
  int quotient; // 몫
  int remainder; // 나머지
} Div;

예제intdiv3.c
#include "stdiv.h"
Div IntDiv(int num1, int num2)
{
  Div dval;
  dval.quotient=num1/num2;
  dval.remainder=num1%num2;
  return dval;
}
위 소스파일에는 헤더파일 stdiv.h를 포함하고 있다. IntDiv 함수에서 구조체 Div의 변수를 선언하니 당연하다.

예제intdiv3.h
#include "stdiv.h"
Div IntDiv(int num1, int num2);

위의 헤더파일은 소스파일 intdiv3.c에서 정의한 함수의 선언을 담고 있다. 그런데 함수의 선언에서 구조체 Div가 반환형으로 선언돼있기 때문에 헤더파일 stdiv.h를 포함해야한다.

예제main.c
#include <stdio.h>
#include "stdiv.h"
#include "intdiv3.h"

int main()
{
  Div val=IntDiv(5, 2);
  printf("몫: %d \n", val.quotient);
  printf("나머지: %d \n", val.remainder);
  return 0;
}

위 main.c에서는 intdiv3.h를 포함하고 있다. IntDiv 함수를 호출하고 있기 때문이다. 그리고 stdiv.h를 포함하고 있다. Div형 변수를 선언하고 있기 때문이다.
이렇듯 이 예제는 파일을 하나씩만 놓고 보면 문제되리 것이 없어보인다. 하지만 파일들을 묶어놓으면 문제가 생긴다. 헤더파일의 중복 포함의 문제가 생긴다.

다음 문장에 의해서 stdiv.h를 한 번 포함한다.
#include "stdiv.h"
그리고 다음 문장에 의해 stdiv.h를 한 번 더 포함한다. 왜냐하면 헤더파일 intdiv3.h가 stdiv.h를 포함하고 있기 때문이다.
#include "intdiv3.h"

결과적으로 main.c에서 구조체 Div가 두 번 정의된 형태가 되어 컴파일 에러가 발생한다. 

  -헤더파일을 중복해서 삽입하면 문제가 되나요?
헤더파일의 중복삽입 자체는 문제가 되지 않는다. 특히 다음과 같은 유형의 선언은 두 번 이상 삽입돼도 컴파일 오류가 발생하지 않는다. 왜냐하면 이는 컴파일러에게 전달하는 메시지에 지나지 않기 때문이다.

extern int num;
void Increment(void);

컴파일러에게 메시지를 두 번 이상 전달한다고 해서 문제가 되진 않는다. 그리고 이러한 유형의 선언은 실행파일의 크기와도 상관이 없다(컴파일러가 컴파일을 할 수 있도록 도움을 줄 뿐이므로).
하지만 구조체의 정의는 얘기가 다르다. 이는 컴파일을 하는데 도움을 주는 정보가 아닌, 실행파일의 내용에 직접적인 연관이 있는 정보다. 구조체를 어떻게 정의하냐에 따라 실행파일의 크기뿐 아니라 실행파일의 내용도 달라지기에 이러한 형태의 정의는 두 번 이상 중복 불가하다.

  -조건부 컴파일을 활용한 중복삽입 문제의 해결
헤더파일의 중복삽입에 대한 해결책은 '조건부 컴파일을 위한 매크로'에서 찾을 수 있다. 

예제stdiv2.h
#ifndef __STDIV2_H__
#define __STDIV2_H__

typedef struct div
{
  int quotient; // 몫
  int remainder; // 나머지
} Div;

#endif

위의 파일은 앞서 중복삽입으로 문제됐던 헤더파일이다. 그런데 이 파일의 #ifndef __STDIV2_H__, #define __STDIV2_H__, #endif를 통해 중복삽입을 막을 수 있다.
이 파일을 처음 포함하는 소스파일은 __STDIV2_H__라는 이름의 매크로가 정의되지 않은 상태이므로 구조체의 정의 및 선언을 포함하게 된다. 때문에 #define __STDIV2_H__에 의해서 매크로 __STDIV2_H__가 정의되고 이어서 구조체 Div가 정의된다.
그리고 이후 이 파일을 다시 포함하는 경우 매크로 __STDIV2_H__가 정의된 상태이므로 stdiv2.h의 내용은 포함되지 않는다. 결국 구조체 Div는 소스파일 당 하나씩만 정의되는 것이다.

예제intdiv4.h
#ifndef __INTDIV4_H__
#define __INTDIV4_H__

#include "stdiv2.h"
Div IntDiv(int num1, int num2);
#endif

위의 파일은 중복삽입으로 인한 문제를 일으켰던 헤더파일은 아니다. 하지만 헤더파일에 존재하는 내용은 이렇듯 #ifndef~#endif를 이용해 중복삽입의 문제를 미연에 방지하는 것이 좋다.

예제intdiv4.c
#include "stdiv2.h"
Div IntDiv(int num1, int num2)
{
  Div dval;
  dval.quotient=num1/num2;
  dval.remainder=num1%num2;
  return dval;
}

예제main.c
#include <stdio.h>
#include "stdiv2.h"
#include "intdiv4.h"

int main()
{
  Div val=IntDiv(5, 2);
  printf("몫: %d \n", val.quotient);
  printf("나머지: %d \n", val.remainder);
  return 0;
}
위의 main.c에서는 stdiv2.h를 두 번 포함하려 든다. 하지만 stdiv2.h에 삽입된 매크로 지시자 #ifndef~#endif에 의해 중복삽입으로 인한 문제는 발생하지 않는다. 
이로써 헤더파일을 디자인하고 파일을 분할하여 프로그램을 작성하는데 필요한 이론적인 것을 다 살펴보았다.


*/
