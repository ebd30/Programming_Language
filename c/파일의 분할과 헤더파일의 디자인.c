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







  
*/
