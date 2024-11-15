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
  -문자 출력 함수:putchar, fputc
#include <stdio.h>
int putchar(int c);
int fputc(int c, FILE * stream); -> 함수호출 성공 시 쓰여진 문자정보가, 실패 시 EOF 반환

putchar(): 인자로 전달된 문자정보를 stdout으로 표현되는 표준 출력 스트림으로 전송하는 함수. 인자로 전달된 문자를 모니터로 출력하는 함수라 할 수 있다.
fputc(): putchar() 와 동일하다. 단, fputc함수는 문자를 전송할 스트림을 지정할 수 있다. 즉, stdout 뿐 아니라, 파일을 대상으로도 데이터를 전송할 수 있다. 두 번째 매개변수 stream은 문자를 출력할 스트림의 지정에 사용된다.(stdout을 전달하면 putchar() 동일한 함수가 된다.)

  -문자 입력 함수:getchar, fgetc
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

  -반환형이 int이고, int형 변수에 문자를 담는 이유는?
fgetc, getchar 함수를 다시 관찰해보면
int getchar(void);
int fgetc(FILE * stream);
반환되는 것은 1바이트 크기의 문자인데, 반환형이 int다. 
char를 unsigned char로 처리하는 컴파일러도 존재하는데, 위의 두 함수가 반환하는 값 중 하나인 EOF는 -1로 정의된 상수이다. 따라서 반환형이 char형 이라면, 그리고 char를 unsigned char로 처리하는 컴파일러에 의해서 컴파일이 되었다면, EOF는 반환의 과정에서 엉뚱한 양의 정수로 형 변환이 되버린다.
어떠한 상황에서도 -1을 인식시킬 수 있는 int형으로 반환형을 정의해 놓은 것이다.

#문자열 단위 입출력 함수

  -문자열 출력 함수:puts, fputs
#include <stdio.h>
int puts(const char * s);
int fputs(cont char * s, FILE * stream); -> 성공 시 음수가 아닌 값을, 실패 시 EOF 반환
puts(): 출력의 대상이 stdout으로 결정되어 있다.
fputs(): 두 번째 인자를 통해 출력의 대상을 결정할 수 있다.
둘 다 첫 번째 인자로 전달되는 주소 값의 문자열을 출력하지만, 출력의 형태에 있어 한 가지 차이점이 있다. puts()는 호출되면 문자열 출력 후 자동으로 개행이 이뤄지고, fputs()는 호출되면 문자열이 출력 후 자동으로 개행이 이뤄지지 않는다.


  -문자열 입력 함수:gets, fgets
#include <stdio.h>
char * gets(char * s);
char * fgets(char * s, int n, FILE * stream); -> 파일의 끝에 도달하거나 함수호출 실패 시 NULL 포인터 반환

gets() 함수 호출 유형
int main(void)
{
  char str[7]; // 7byte 메모리 공간 할당
  gets(str); // 입력 받은 문자열을 배열 str에 저장
  ....
}
미리 마련해 놓은 배열을 넘어서는 길이의 문자열이 입력되면, 할당 받지 않은 메모리 공간을 침범하여 실행 중 오류가 발생함. 그래서 가급적 다음의 형태로 fgets 함수를 호출하는 것이 좋다.
int main(void)
{
  char str[7];
  fgets(str, sizeof(str), stdin); // stdin으로부터 문자열 입력 받아 str에 저장
}
stdin으로부터 문자열을 입력 받아 배열str에 저장하되, sizeof(str)의 길이만큼 저장해라는 의미다.

ex) "123456789" 입력되면 sizeof(str)의 반환 값인 7보다 1작은 6을 길이로 문자열만 읽어 str에 저장하게 된다. "123456" 이 저장되는 것이다.
문자열을 입력받으면 문자열의 끝에 자동으로 널 문자가 추가된다.

예제ReadString.c
#include <stdio.h>
int main()
{
  char str[7];
  for(int i=0; i<3; i++)
  {
    fgets(str, sizeof(str), stdin);
    printf("Read %d: %s \n", i+1, str);
  }
  return 0;
}
fgets()는 \n을 만날 때까지 문자열을 읽어들이는데, \n을 제외시키거나 버리지 않고 문자열의 일부로 받아들인다. 엔터 키의 정보도 문자열의 일부로 저장되는 것이다. 공백을 포함하는 형태의 문자열도 입력 가능하다. 참고: scanf()를 통해서는 공백을 포함하는 문자열을 입력 받을 수 없다.

#표준 입출력과 버퍼

  -표준 입출력 기반의 버퍼
ANSI C의 표준에서 정의된 함수를 '표준 입출력 함수'라 한다. ex) printf, scanf, fputc, fgetc,...etc
표준 입출력 함수를 통해서 데이터를 입출력하는 경우, 해당 데이터들은 운영체제가 제공하는 '메모리 버퍼'를 중간에 통과하게 된다. 
메모리 버퍼는 데이터를 임시로 모아두는(저장하는) 메모리 공간이다.

키보드 통해 입력된 데이터 -> 입력버퍼에 저장된 다음(버퍼링 된 다음) -> 프로그램에서 읽혀진다.
ex) fgets()가 읽어 들이는 문자열은 입력버퍼에 저장된 문자열이다.
입력된 데이터가 입력 스트림을 거쳐서 입력버퍼로 들어가는 시점은 엔터 키가 눌리는 시점이다. 그래서 키보드로 아무리 문자열을 입력해도 엔터 키가 눌ㄹ기 전에는 fgets함수가 문자열을 읽어 들이지 못 한다.
엔터 키가 눌리기 전에는 입력버퍼가 비워져 있기 때문이다.

  -버퍼링(Buffering)하는 이유
창고에 물건을 나르는 경우 손으로 하나씩 나르는 것보다 손수레에 가득 채워서 나르는 것이 보다 빠르고 효율적인 것처럼 입출력의 과정에서 버퍼링을 했을 때 보다 빠르고 효율적이게 된다.

  -출력버퍼를 비우는 fflush함수
#include <stdio.h>
int fflush(FILE * stream); -> 함수호출 성공 시 0, 실패 시 EOF 반환

fflush(): 인자로 전달된 스트림의 버퍼를 비우는 기능을 제공한다. 

fflush(stdout); // 표준 출력버퍼를 비워라

출력버퍼가 비워진다는 것은 출력버퍼에 저장된 데이터가 버퍼를 떠나서 목적지로 이동됨을 뜻한다.
출력버퍼가 비워지는 시점은 시스템에 따라 버퍼의 성격에 따라 달라진다. ex) 하나의 문장이 완전히 입력되었을 때마다 비워지는 버퍼, 버퍼가 꽉 찼을 때 비워지는 버퍼 등 다양하기 때문에 fflush() 함수를 알아둘 필요가 있다.
인자로 파일의 스트림정보가 전달되면, 해당 버퍼에 저장되어 있던 데이터들이 버퍼를 떠나 파일에 기록된다.

  -입력버퍼는 어떻게 비워야 하나요?
'입력버퍼의 비워짐'은 '출력버퍼의 비워짐'과 개념적으로 차이가 있다. 
'출력버퍼의 비워짐'이 저장된 데이터가 목적지로 전송됨을 의미한다면, '입력버퍼의 비워짐'은 데이터의 소멸을 의미하기 때문이다.
혹시 
fflush(stdin); 를 떠올리지는 않았는가?
fflush함수는 출력버퍼를 대상으로 호출하는 함수다. C언어 표준에서는 위의 결과에 대해 정의하고 있지 않다. 따라서 위의 함수는 예측이 불가능하다. 물론 일부 컴파일러는 위의 형태로 함수 호출 시 입력버퍼 비워주기도 한다(입력버퍼의 데이터를 소멸시키기도 함).
대표적으로 Windows 계열의 컴파일러가 그러하다.

예제NeedInputBufFlush.c
#include <stdio.h>
void ClearLineFromReadBuffer(void)
{
  while(getchar()!='\n');
}
int main()
{
  char perID[7];
  char name[10];
  
  fputs("주민번호 앞 6자리 입력: ", stdout);
  fgets(perID, sizeof(perID), stdin);
  ClearLineFromReadBuffer(); // 입력버퍼 비우기
  fputs("이름 입력: ", stdout);
  fgets(name, sizeof(name), stdin);

  printf("주민번호: %s \n", perID);
  printf("이름: %s \n", name);
  return 0;
}
위 예제에서 정의된 ClearLineFromReadBuffer 함수는 입력버퍼를 통째로 비우는 함수가 아니라 \n이 읽혀질 때까지 입력버퍼에 저장된 문자들을 지우는 함수이다.

*/
