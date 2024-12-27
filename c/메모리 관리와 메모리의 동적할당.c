/*
#C언어의 메모리 구조

  -메모리의 구성
프로그램 실행 시 운영체제에 의해 마련되는 메모리의 구조는 네 개의 영역으로 구분된다.
코드 영역
데이터 영역
힙 영역
스택 영역

  -메모리 영역별로 저장되는 데이터 유형
각 영역별 특성에 대해 구체적으로 살펴보겠다.

코드 영역(Code Area)
코드 영역은 이름 그대로 실행할 프로그램의 코드가 저장되는 메모리 공간이다. 따라서 CPU는 코드 영역에 저장된 명령문들을 하나씩 가져가 실행한다.

데이터 영역(Data Area)
데이터 영역에는 전역변수와 static으로 선언되는 static 변수가 할당된다. 즉, 이 영역에 할당되는 변수들은 프로그램의 시작과 동시에 메모리 공간에 할당되어 프로그램 종료 시까지 남아있게 된다는 특징이 있다.

스택 영역(Stack Area)
스택 영역에는 지역변수와 매개변수가 할당된다. 이렇듯 이 영역에 할당되는 변수들은 선언된 함수를 빠져나가면 소멸된다는 특징이 있다.

힙 영역(Heap Area)
데이터 영역에 할당되는 변수와 스택 영역에 할당되는 변수들은 생성과 소멸의 시점이 이미 결정돼있다. 그러나 프로그램을 구현하다 보면, 이 두 영역의 변수들과는 다른 성격의 변수가 필요하기도하다. 그래서 C언어에서는 프로그래머가 원하는 시점에 변수를 할당하고 또 소멸하도록 지원을 한다. 바로 이러한 유형의 변수들이 할당되는 영역이 힙 영역이다.


  -프로그램의 실행에 따른 메모리의 상태 변화
프로그램의 실행과정에서 보이는 메모리 공간의 변화를 통해서 각 영역별 특징에 대해 다시 한 번 정리하겠다. 단 코드 영역은 변수가 할당되는 영역이 아니니 생략하고 진행하겠다.

실행의 흐름1
프로그램 시작->int sum=25;      ---전역변수의 할당--->  sum=25; 데이터 영역(data area)

int main(void)
{
  int num1=10;
  fct(num1);
  num1++;
  fct(num1);
  return 0;
}

void fct(int n)
{
  int num2=12;
  ....
}

프로그램의 시작은 main함수의 호출에서부터다라고 이야기를 들어왔겠지만 실제로는 main함수가 호출되기 이전에 데이터 영역이 먼저 초기화된다. 위와 같이 전역변수가, 그리고 (위에는 없는)static 변수가 먼저 데이터 영역에 할당이 되고 나서 main 함수가 호출된다.
이어서 main 함수가 호출되고 main 함수 내에 선언된 지역변수 num1이 스택에 할당되어 다음의 구조가 된다.

실행의 흐름2
int sum=25;      sum=25; 데이터 영역(data area)

int main(void)
{
  현재 실행위치->int num1=10; --지역변수의 할당--> num1=10; 스택 영역(stack area)
  fct(num1);
  num1++;
  fct(num1);
  return 0;
}

void fct(int n)
{
  int num2=12;
  ....
}

다음으로 main 함수 내에 fct 함수가 호출된다. 때문에 fct 함수의 매개변수가 스택에 할당되고 fct함수의 지역변수도 다음과 같이 그 뒤를 이어 할당된다.

실행의 흐름3

int sum=25;       sum=25; 데이터 영역(data area)
                  
int main(void)
{
  int num1=10;      num1=10; 스택 영역(stack area)
  호출된 함수->fct(num1); ----매개변수--->n=10; 스택 영역(stack area)
  num1++;
  fct(num1);
  return 0;
}

void fct(int n)
{
  현재 실행위치->int num2=12; ---지역 변수----> num2=12; 스택 영역(stack area)
  ....
}

다음으로 fct 함수가 반환을 하면서 fct 함수호출 시 할당되었던 매개변수와 지역변수가 소멸되면서 다음의 형태가 된다. 참고로 다음에서 fct함수를 빠져 나온 이후에 main함수 내에서 num1의 값이 증가한 상황까지의 결과를 보이고 있다.

실행의 흐름4

int sum=25;       sum=25; 데이터 영역(data area)
                  
int main(void)
{
  int num1=10;      
  fct(num1);       n=10; 스택 영역(stack area)<- 소멸
  현재 실행위치->num1++;      num1=11; 스택 영역(stack area)
  fct(num1);
  return 0;
}

void fct(int n)
{
  int num2=12;      num2=12; 스택 영역(stack area)<- 소멸
  ....
}

이어서 다시 fct 함수의 호출이 진행되고, 더불어 매개변수와 지역변수가 다시 스택에 할당되어 다음의 구조가 된다.

실행의 흐름5

int sum=25;       sum=25; 데이터 영역(data area)
                  
int main(void)
{
  int num1=10;      
  fct(num1);       
  num1++;      num1=11; 스택 영역(stack area)
  호출된 함수->fct(num1); ---매개변수--->n=11; 스택 영역(stack area)
  return 0;
}

void fct(int n)
{
  현재 실행위치->int num2=12;---지역변수--->num2=12; 스택 영역(stack area)
  ....
}

마지막으로 fct 함수가 반환되고, main 함수의 return 문이 실행되면서 프로그램이 종료된다. 그리고 프로그램이 종료되면, 운영체제에 의해 할당된 메모리 공간 전체를 반환하게 되는데, 바로 그때가 전역변수가 소멸되는 시점이다.

프로그램의 종료(실행의 흐름6)

int sum=25;       sum=25; 데이터 영역(data area)<- 소멸 
                  
int main(void)
{
  int num1=10;      
  fct(num1);       
  num1++;      num1=11; 스택 영역(stack area)<- 소멸
  fct(num1);      n=11; 스택 영역(stack area)<- 소멸
  프로그램 종료->return 0;
}

void fct(int n)
{
  int num2=12;      num2=12; 스택 영역(stack area)<- 소멸
  ....
}

지금까지 살펴 본 내용을 기준으로 스택 영역의 특징을 하나 더 찾아보자면 다음의 순서로 함수가 호출되었다 가정하자.
main함수의 호출 -> fct1 함수의 호출 -> fct2 함수의 호출

이는 fct1함수가 반환된 이후에 fct2 함수가 호출되었다는 뜻이 아니고 fct1 함수 내에서 fct2 함수가 호출되었다는 뜻이다. 그리고 이러한 경우 지역(매개)변수의 소멸순서는 다음과 같다.
fct2의 지역변수 소멸 -> fct1의 지역변수 소멸 -> main의 지역변수 소멸

이렇듯 먼저 호출된 함수의 스택공간일수록 늦게 해제된다는 것을 알 수 있다. 


#메모리의 동적 할당

  -전역변수와 지역변수로 해결이 되지 않는 상황
예제ReadStringFault1.c
#include <stdio.h>

char * ReadUserName(void)
{
  char name[30];
  printf("What's your name? ");
  gets(name);
  return name; // 무엇을 반환하는가?
}
int main()
{
  char * name1;
  char * name2;
  name1=ReadUserName();
  printf("name1: %s \n", name1);
  name2=ReadUserName();
  printf("name2: %s \n", name2);

  return 0;
}
위 예제의 문제점은 함수 내에 지역적으로 선언된 배열(변수)의 주소 값을 반환하는데있다. 
함수 내에서 프로그램 사용자로부터 문자열을 입력 받아 그 결과를 반환하는 것은 좋지만 그 문자열이 저장되어 있는 배열이 지역적으로 선언되었기 때문에 함수를 빠져나오면서 소멸된다는데 있다.
그래서 실제로 실행해보면 정상적이지 못할 결과로 이어진다. 간혹 정상적인 결과를 보일 수 있지만 이는 우연이다.

예제ReadStringFault2.c
#include <stdio.h>
char name[30];

char * ReadUserName(void)
{
  printf("What's your name? ");
  gets(name);
  return name; // 무엇을 반환하는가?
}
int main()
{
  char * name1;
  char * name2;
  name1=ReadUserName();
  printf("name1: %s \n", name1);
  name2=ReadUserName();
  printf("name2: %s \n", name2);

  return 0;
}
위 예제는 전역변수를 이용한 것이다. 하지만 이 역시 답이 될 수 없다.
하나의 전역변수(전역으로 선언된 배열)을 이용하면, 이 전역변수를 덮어쓰게 되기 때문에, 함수호출을 통해서 얻게 된 이름정보가 유지되지 않는다. 즉 프로그램 사용자에게 이름정보를 입력 받아서 이를 반환하는 함수를 정의하기에는 지역변수도 전역변수도 답이 될 수 없다. 

"함수가 매번 호출될 때마다 새롭게 할당되고 또 함수를 빠져나가도 유지가 되는 유형의 변수"
지역변수와 같이 함수가 호출될 때마다 매번 할당이 이뤄지지만, 할당이 되면 전역변수와 마찬가지로 함수를 빠져나가도 소멸되지 않는 성격의 변수가 필요하다. 그런데 다행스럽게도 이렇듯 생성과 소멸의 시기가 지역변수나 전역변수와 다른 유형의 변수는 malloc과 free라는 이름의 함수를 통해 힙 영역에 할당하고 소멸할 수 있다.

  -힙 영역의 메모리 공간 할당과 해제: malloc(), free()
#include <stdlib.h>
void * malloc(size_t size); // 힙 영역으로의 메모리 공간 할당
void * free(void * ptr); // 힙 영역에 할당된 메모리 공간 해제
-> malloc 함수는 성공 시 할당된 메모리의 주소 값, 실패 시 NULL 반환

힙 영역을 흔히 '프로그래머가 관리하는 메모리 공간' 이라고 한다. 이유는 malloc함수호출로 할당된 메모리 공간은 프로그래머가 직접 free 함수의 호출을 통해서 해제하지 않으면 계속 남아있기 때문이다.
즉 malloc, free는 쌍을 이루어 호출하게 된다.

int main()
{
  void * ptr1 = malloc(4); // 4byte 힙 영역에 할당
  void * ptr2 = malloc(12); // 12byte 힙 영역에 할당
  ....
  free(ptr1); // ptr1이 가리키는 4byte 메모리 공간 해제
  free(ptr2); // ptr2가 가리키는 12byte 메모리 공간 해제
  ....
}
이렇듯 malloc 함수는 인자로 전달된 정수 값에 해당하는 바이트 크기의 메모리 공간을 힙 영역에 할당하고, 이 메모리 공간의 주소 값을 반환한다.
위의 코드를 실행 시 ptr1은 첫 번째 malloc 함수호출을 통해 할당된 메모리 공간의 첫 번째 바이트를 가리키게 되고, ptr2는 두 번째 malloc 함수호출을 통해 할당된 메모리 공간의 첫 번째 바이트를 가리키게 된다.이어서 ptr1을 인자로 free 함수를 호출하는 시점에 ptr1이 가리키는 메모리 공간이 소멸되고, ptr2를 인자로 free 함수를 호출하는 시점에 ptr2가 가리키는 메모리 공간이 소멸된다.
무엇보다도  malloc함수와 free함수의 호출 위치 및 시점에는 제한이 없다. 따라서 원하는 시점에 할당하고 원하는 시점에 소멸이 가능하다. 

"힙에 할당된 메모리 공간은 포인터 변수를 이용해서 접근하는 방법밖에 없나요?" 
라는 질문을 할 수 있다. malloc함수는 주소 값을 반환한다. 그리고 그 주소 값을 이용해서 힙에 접근을 해야 한다.따라서 포인터를 이용해서 메모리 공간에 접근하는 수 밖에 없다. 

  -malloc 함수의 반환형이 void형 포인터인 이유와 힙 영역으로의 접근
malloc함수의 반환형은 void형 포인터이다. 따라서 malloc함수의 반환 값에 아무런 가공도 가하지 않으면, 이를 이용해서는 할당된 메모리 공간에 접근이 불가능하다.

void * ptr = malloc(sizeof(int)); // int형 변수 크기의 메모리 공간 할당
*ptr=20; // ptr이 void형 포인터이므로 컴파일 에러

그럼에도 불구하고 malloc함수의 반환형이 void형 포인터인 이유가 무엇인지 malloc 함수에게 물었다. 그리고 이에 대한 malloc 함수의 답변은 다음과 같다.

"제가 어떻게 포인터 형을 결정합니까? 저에게 전달하는 것은 숫자뿐이잖아요. 4를 전달하시면 int형 변수로 사용할지 float형 변수로 사용할지, 아니면 길이가 4인 char형 배열로 사용할지 제가 어떻게 압니까? 그러니 void형 포인터로 반환하는 수밖에요."

다음과 같이 문장을 구성하고선 충분히 malloc함수에게 정보를 잘 전달했다고 생각할 수 있다.
void * ptr1=malloc(sizeof(int));
void * ptr2=malloc(sizeof(double));
void * ptr3=malloc(sizeof(int)*7);
void * ptr4=malloc(sizeof(double)*9);

하지만 sizeof연산과 곱셈연산 이후에 정작 malloc함수에게 전달되는 인자는 다음과 같을 뿐이다.
void * ptr1=malloc(4);
void * ptr2=malloc(8);
void * ptr3=malloc(28);
void * ptr4=malloc(72);

때문에 malloc 함수는 다음과 같이 이야기 한다.
"저는 원하시는 크기만큼 메모리 공간을 할당하고 그 메모리의 주소 값을 반환하겠습니다. 그러니 어떻게 사용할지는 포인터 형의 변환을 통해서 직접 결정하세요."
다음과 같이 void형으로 반환되는 주소 값을 적절히 형 변환해서 할당된 메모리 공간에 접근해야 한다.
int * ptr1 = (int *)malloc(sizeof(int));
double * ptr2 = (double *)malloc(sizeof(double));
int * ptr3 = (int *)malloc(sizeof(int)*7);
double * ptr4 = (double *)malloc(sizeof(double)*9);

지금까지 설명한 내용을 바탕으로 힙 영역에 int형 변수와 int형 배열을 각각 하나씩 선언해서 접근하고 또 해제해보겠다.
예제DynamicMemoryAllocation.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int * ptr1 = (int *)malloc(sizeof(int));
  int * ptr2 = (int *)malloc(sizeof(int)*7);
  int i;

  *ptr1 = 20;
  for(i=0; i<7; i++)
    ptr2[i]=i+1;

  printf("%d \n", *ptr1);
  for(i=0; i<7; i++)
    printf("%d ", ptr2[i]);

  free(ptr1);
  free(ptr2);
  return 0;
}

참고로 malloc함수는 메모리 공간의 할당에 실패할 경우 NULL을 반환한다. 따라서 메모리 할당의 성공여부를 확인하고자 한다면 다음과 같이 코드를 작성해야 한다.
int * ptr = (int *)malloc(sizeof(int));
if(ptr==NULL)
{
  //메모리 할당 실패에 따른 오류의 처리
}
그리고 malloc 함수의 호출을 통한 메모리 공간의 할당을 가리켜 '동적 할당(dynamic allocation)'이라 한다. 이유는 할당되는 메모리의 크기를 컴파일러가 결정하지 않고, 프로그램의 실행 중간에 호출되는 malloc함수가 결정하기 때문이다.










*/
