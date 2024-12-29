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



  
*/
