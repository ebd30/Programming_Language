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



*/
