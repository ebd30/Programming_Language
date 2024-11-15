/*
#스트림과 데이터의 이동

  -데이터의 이동수단이 되는 스트림
프로그램과 모니터, 키보드는 기본적으로 떨어져있는 개채이다. 프로그램과 모니터, 키보드를 대상으로 데이터를 입출력하기 위해서는 연결다리가 필요한데 다리 역할을 하는 매개체를 '스트림(Stream)'이라 한다.

  -스트림의 생성과 소멸
콘솔 입출력과 파일 입출력 사이에는 차이점이 있다. 파일과의 연결을 위한 스트림의 생성은 우리가 직접 요구해야 하지만, 콘솔과의 연결을 위한 스트림의 생성은 요구할 필요가 없다.
ex) printf(), scanf() 함수를 호출할 때 스트림의 생성과 관련된 코드가 없다.
콘솔 입출력을 위한 입력 스트림과 출력 스트림은 프로그램이 실행되면 자동으로 생성되고 프로그램이 종료되면 자동으로 소멸되는 스트림이다.
Standard stream(표준 스트림)
stdin 표준 입력 스트림(키보드 대상으로 입력)
stdout 표준 출력 스트림(모니터 대상으로 출력)
stderr 표준 에러 스트림(모니터 대상으로 출력)

스트림(Stream): 한 방향으로 흐르는 데이터의 흐름. 단방향으로만 데이터의 전송이 이뤄진다는 뜻이 담겨있다. 실제로 입출력 스트림도 입력 스트림과 출력 스트림이 구분되어서 한 방향으로만 데이터의 흐름을 유지하고 있다.

#문자 단위 입출력 함수
  -putchar, fputc
#include <stdio.h>
int putchar(int c);
int fputc(int c, FILE * stream); -> 함수호출 성공 시 쓰여진 문자정보가, 실패 시 EOF 반환

putchar(): 인자로 전달된 문자정보를 stdout으로 표현되는 표준 출력 스트림으로 전송하는 함수. 인자로 전달된 문자를 모니터로 출력하는 함수라 할 수 있다.
fputc(): putchar() 와 동일하다. 단, fputc함수는 문자를 전송할 스트림을 지정할 수 있다. 즉, stdout 뿐 아니라, 파일을 대상으로도 데이터를 전송할 수 있다. 두 번째 매개변수 stream은 문자를 출력할 스트림의 지정에 사용된다.(stdout을 전달하면 putchar() 동일한 함수가 된다.)

  -getchar, fgetc
#include <stdio.h>
int getchar(void);
int fgetc(FILE *stream); -> 파일의 끝에 도달하거나 함수호출 실패 시 EOF 반환

getchar(): stdin으로 표현되는 표준 입력 스트림으로부터 하나의 문자를 입력 받아서 반환하는 함수. 
fgetc(): getchar() 와 기능은 동일하지만, 문자를 입력 받을 스트림을 지정할 수 있다. 

예제ReadWriteChar.c
#include <stdio.h>
int main()
{
  int ch1, ch2;
  ch=getchar(); // 문자 입력
  ch2=fgetc(stdin); // 엔터 키 입력

  putchar(ch1); // 문자 출력
  fputc(ch2, stdout); // 엔터 키 출력
  return 0;
}

  -문자 입출력에서 EOF
EOF(End Of File): 파일의 끝을 표현하기 위해서 정의해 놓은 상수. 
ex) 파일을 대상으로 fgetc()가 호출되면, 그리고 그 결과로 EOF가 반환되면, '파일의 끝에 도달해서 더 이상 읽을 내용이 없다'는 뜻이 된다.
fgetc(), getchar() 는 다음 두 가지 중 하나가 만족되었을 때 EOF 반환
함수 호출의 실패
Windonws에서 CTRL+Z, Linux에서 CTRL+D 키가 입력되는 경우

예제ConsoleEOF.c
#include <stdio.h>
int main()
{
  int ch;
  while(1)
  {
    ch=getchar();
    if(ch==EOF)
      break;
    putchar(ch);
  }
  return 0;
}
*/
