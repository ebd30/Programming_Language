/*
#파일과 스트림(Stream), 그리고 기본적인 파일의 입출력
파일은 운영체제에 의해 관리가 되기 때문에 운영체제와 파일의 관계를 이해하는 것부터 시작할 필요가 있다.

  -저기 저 파일에 저장되어 있는 데이터를 읽고 싶어요.
프로그램상에서 저장돼있는 데이터를참조하길 원한다고(읽기 원한다고) 가정해보면 구현한 프로그램과 참조할 데이터가 저장돼있는 파일 사이에 데이터가 이동할 수 있는 다리를 놓는 일이 제일 먼저 해야 할 일이다.
이러한 데이터 이동의 경로가 되는 다리를 가리켜 '스트림(Stream)'이라 한다. 
프로그램과 파일 사이 스트림을 형성해야 데이터를 주고 받을 수 있다.

Program(code) <----stream----> Hard Disk in file.txt

파일로부터 데이터를 읽어 들일(파일에 데이터를 쓸) 기본적인 준비가 됐다라는 의미는 프로그램과 파일 사이에 스트림이 형성되었다고 이해하면 된다.
그런데 파일은 운영체제에 의해 그 구조가 결정되고 관리되는 대상이기에, 파일 뿐만 아니라 스트림의 형성도 운영체제의 몫임을 기억해야한다.

  -fopen 함수호출을 통한 팡리과의 스트림 형성과 FILE 구조체
#include <stdio.h>
FILE * fopen(const char * filename, const char * mode);
-> 성공 시 해당 파일의 FILE 구조체 변수의 주소 값, 실패 시 NULL 포인터 반환
fopen()함수의 첫 번째 인자로는 스트림을 형성할 파일의 이름, 두 번째 인자로는 형성할 스트림의 종류에 대한 정보를 문자열의 형태로 전달한다. 그러면 fopen함수는 해당 파일과의 스트림을 형성하고 스트림 정보를 FILE 구조체 변수에 담아서 그 변수의 주소 값을 반환한다.

fopen함수가 호출되면 FILE 구조체 변수가 생성된다.
생성된 FILE 구조체 변수에는 파일에 대한 정보가 담긴다.
FILE 구조체의 포인터는 사실상 파일을 가리키는 '지시자'의 역할을 한다.

  -입력 스트림과 출력 스트림의 생성
스트림은 '한 방향으로 흐르는 데이터의 흐름'을 의미한다. 때문에 스트림은 데이터를 파일로부터 읽어들이기 위한 '입력 스트림'과 데이터를 파일에 쓰기 위한 '출력 스트림'으로 구분된다.
fopen함수를 호출할 때 두 가지 인자.
첫 번째 인자 - 스트림을 형성할 파일의 이름
두 번째 인자 - 형성하고자 하는 스트림의 종류

출력 스트림의 형성을 요청하는 fopen 함수의 호출문
FILE * fp = fopen("data.txt", "wt"); // 출력 스트림의 형성, 파일 data.txt와 스트림을 형성하되 wt모드(쓰기 곧 출력 스트림)로 스트림을 형성해라라는 의미다.

입력 스트림의 형성을 요청하는 fopen 함수의 호출문
FILE * fp = fopen("data.txt", "rt"); // 입력 스트림의 형성, 파일 data.txt와 스트림을 형성하되 rt모드(읽기 곧 입력 스트림)로 스트림을 형성해라라는 의미다.

참고로 fopen함수의 호출을 통해 파일과의 스트림이 형성되었을 때 '파일이 개방(오픈)되었다'라고 표현하는 것이 일반적이다.

  -파일에 데이터를 써봅시다.
예제FirstFileWrite.c
#include <stdio.h>
int main()
{
  FILE * fp=fopen("data.txt", "wt");
  if(fp==NULL) {
    puts("파일 오픈 실패!");
    return -1;
  }

  fputc('A', fp);
  fputc('B', fp);
  fputc('C', fp);
  fclose(fp);
  return 0;
}

출력 스트림을 형성하는 경우에는 해당 파일이 생성된다. 따라서 파일 data.txt파일이 생성됨을 확인할 수 있을 것이다. 그런데 실행방법, 실행환경 및 설정에 따라 파일이 생성되는 위치가 달라진다. 
생성위치를 고정시키고 싶으면
FILE * fp = fopen("C:\\Project\\data.txt", "wt");
절대경로를 지정해 파일의 경로를 지정시켜주면 된다.예시로 경로를 지정한 것과 일치하게 드라이브랑 디렉토리가 생성되어있어야한다. 

  -스트림의 소멸을 요청하는 fclose함수
#include <stdio.h>
int fclose(FILE * stream);
-> 성공 시 0, 실패 시 EOF를 반환

fclose함수는 fopen함수의 반대 기능을 제공한다. stream을 해제하는, 파일을 닫는 함수이다.

fclose함수의 호출을 통해 파일을 닫아줘야 하는 이유
운영체제가 할당한 자원은 반환
버퍼링 되었던 데이터의 출력

함수의 호출을 통해 스트림의 형성을 요청하는 것은 사용자지만, 실제로 스트림을 형성하는 주체는 운영체제이다. 그리고 운영체제는 스트림의 형성을 위해 시스템의 자원(주로 메모리)을 할당한다. 그런데 이 자원은 파일을 닫아주지 않으면 할당된 채로 남아있게 되서 그만큼의 자원손실을 초래하기 때문에 파일의 사용이 끝나는 즉시 fclose함수를 호출해 자원을 반환해줄 필요가 있다.
두 번째 이유는 콘솔 스트림의 중간에 존재하는 입력버퍼와 출력버퍼를 기억하는가? 이와 마찬가지로 파일 스트림도 중간에 입력버퍼 출력버퍼가 있다. 
운영체제가 파일과 프로그램 사이 입출력 버퍼를 두어 성능의 향상을 도모하고 때문에 fputc와 같은 함수의 호출로 데이터를 파일로 전송한다고 해서 파일에 바로 저장되는 것이 아니라 일단 출력버퍼에 저장되고 운영체제가 정해놓은 버퍼링 방식에 따라 뒤늦게 파일에 저장된다.
그런데 이러한 버퍼링 방식에는 문제가 하나 있다. 예를 들어 'A'와 'B' 문자가 출력버퍼에 존재하는 상태에서(파일에 저장되기 직전의 상태에서) 컴퓨터의 전원이 꺼지면 문자 A, B는 파일에 저장되지 않는다. 그러나 fclose함수의 호출을 통해 파일을 닫아주면 출력버퍼에 저장되었던 데이터가 파일로 이동해 출력버퍼가 비워진다. 그 이후는 컴퓨터의 전원이 꺼져도 팡리에 저장된 데이터는 소멸되지 않는다. 때문에 사용이 끝난 파일은 곧바로 fclose함수를 호출해주는 것이 좋다.

  -Chapter21 에서 호출한 적 있는 fflush함수
#include <stdio.h>
int fflush(FILE * stream);
-> 함수호출 성공 시 0, 실패 시 EOF 반환

입출력 버퍼를 비우는 것과 관련해 설명할 사실
1. 출력버퍼를 비운다는 것은 출력버퍼에 저장된 데이터를 목적지로 전송한다는 의미
2. 입력버퍼를 비운다는 것은 입력버퍼에 저장된 데이터를 소멸시킨다는 의미
3. fflush함수는 출력버퍼를 비우는 함수다.
4. fflush함수는 입력버퍼를 대상으로 호출할 수 없다.

위 내용은 파일 스트림에도 그대로 적용된다. 다음과 같이 파일의 출력버퍼를 비울 수 있다.
int main()
{
  FILE * fp=fopen("data.txt", "wt"); // 출력 스트림 형성
  ....
  fflush(fp); // 출력버퍼 비워라는 요청
  ....
}
이렇듯 fflush 함수는 출력버퍼를 위한 함수다. 파일스트림의 입력버퍼는 어떻게 지우냐고 질문할 수 있다. 그런데 파일 스트림의 입력버퍼를 비우는 함수는 필요가 없다. 파일에 저장된 데이터는 원할 때 언제든지 읽을 수 있을 뿐 아니라(읽혀진 데이터는 입력버퍼에서 지워진다.), 파일대상의 입력버퍼를 비워야만 하는 상황이라는 것이 특별히 존재하지 않기 때문이다.

  -파일로부터 데이터를 읽어 봅시다.
예제FirstFileRead.c
#include <stdio.h>
int main()
{
  int ch;
  FILE * fp=fopen("data.txt" , "rt");
  if(fp==NULL) {
    puts("파일 열기 실패!");
    return -1;
  }
  for(i=0; i<3; i++)
  {
    ch=fgetc(fp);
    printf("%c\n", ch);
  }
  fclose(fp);
  return 0;
}


#파일의 개방 모드(Mode)
앞서 fopen함수의 두 번째 인자로 "rt", "wt"를 전달해 입력, 출력 스트림을 형성했었다. 하지만 형성할 수 있는 스트림의 종류는 다양하다. 
기본적으로 두 가지 기준을 통해 스트림을 구분하게 된다.
기준1 - 읽기 위한 스트림이냐? 쓰기 위한 스트림이냐?
기준2 - 텍스트 데이터를 읽기 위한 스트림이냐? 바이너리 데이터를 읽기 위한 스트림이냐?

  -스트림을 구분하는 기준1: 읽기 위한 스트림? 쓰기 위한 스트림?
스트림을 구분하는 기준은 두 가지인데, 이 중 데이터의 이동방향을 기준으로 다음과 같이 네 가지로 구분할 수 있다.
데이터 READ 스트림(읽기만 가능)
데이터 WRITE 스트림(쓰기만 가능)
데이터 APPEND 스트림(쓰되 덧붙여 쓰기만 가능)
데이터 READ/WRITE 스트림(읽기, 쓰기 모두 가능)

그러나 C언어는 이를 바탕으로 총 6가지로 스트림을 세분화한다. 
모드(mode) - 스트림의 성격 - 파일이 없으면?
r - 읽기 가능 - 에러
w - 쓰기 가능 - 생성
a - 파일의 끝에 덧붙여 쓰기 가능 - 생성
r+ - 읽기/쓰기 가능 - 에러
w+ - 읽기/쓰기 가능 - 생성
a+ - 읽기/덧붙여 쓰기 가능 - 생성

필요로 하는 스트림의 특성과 일치하는 '파일의 개방 모드(Mode)'를 선택하면 된다. fopen함수의 두 번째 인자가 된다.
다음 두 가지를 기억하라
모드의 +는 읽기, 쓰기가 모두 가능한 스트림의 형성을 의미한다.
모드의 a는 쓰기가 가능한 스트림을 형성하는데, 여기서 말하는 쓰기는 덧붙이기이다.

웬만하면 r, w, a 중에서 선택하라
파일의 개방모드 중 r+, w+, a+는 읽기와 쓰기가 동시에 가능하여 더 좋다고 생각할 수 있다. 그러나 이러한 모드를 기반으로 작업하는 경우 읽기에서 쓰기, 그리고 쓰기에서 읽기로 작업을 변경할 때마다 메모리 버퍼를 비워줘야 하는 등의 불편함과 더불어 잘못된 사용의 위험성도 따른다.

  -텍스트 파일과 바이너리 파일
스트림을 구분하는 두 번째 기준에 대해 설명하기 위해 파일에 담을 수 있는 데이터들의 유형을 나열해보겠다.

개인이 소유하는 도서의 목록 - 문자 데이터
슈퍼마켓의 물품 가격 - 문자 데이터
제임스 캐머런 감독의 타이타닉 영상파일 - 바이너리 데이터
소녀시대의 히트곡 음원파일 - 바이너리 데이터

정리하면 사람이 인식할 수 있는 문자를 담고 있는 파일을 가리켜 '텍스트 파일(text file)'이라 하고, 컴퓨터가 인식할 수 있는 데이터를 담고 있는 파일을 가리켜 '바이너리 파일(binary file)'이라 한다.
데이터의 입출력을 위해 스트림을 형성할 때 이와 관련해서 특별히 '문장의 끝을 의미하는 개행의 표현방식'을 신경 써야한다.

  -개행이 \n 아니라고요?
개행은 일반적인 문자 데이터와 성격이 다르다. 개행은 줄이 바뀌었다는 일종의 현상이지 그 자체가 하나의 데이터로 존재하는 대상은 아니기 때문이다.
C언어는 개행을 \n으로 표현하도록 약속하였다. 모든 컴퓨터 환경에서의 약속이 아닌 C언어만의 약속이라는 점이 중요한 사실이다.

개행에 대한 몇몇의 약속
MS-DOS(Windows)의 파일 내 개행 - \r\n
Mac(Mackintosh)의 파일 내 개행 - \r
Unix 계열의 파일 내 개행 - \n

c 프로그램의 실행과정에서 \n이 Windows에서는 \r\n으로 mac에서는 \r로 unix/linux 계열에서는 \n로 저장되어야 해당 운영체제에서 개행으로 인식이 된다. 
막상 이러한 형태의 변환을 직접 하려니 귀찮다는 생각이 들지 않을 수 없는데 파일을 텍스트 모드로 개방하면 해결된다.

  -스트림을 구분하는 기준2: 텍스트 모드와 바이너리 모드
파일을 텍스트 모드로 개방하면 형태의 변환이 자동으로 이뤄진다. 예를 든면 windows를 기반으로는 다음 두 가지의 변환이 자동으로 이뤄진다.
c프로그램에서 \n을 파일에 저장하면 \r\n으로 변환되어 저장됨.
파일에 저장된 \r\n을 c프로그램상에서 읽으면 \n으로 변환되어 읽어짐.
때문에 사용자가 직접 개행의 문자의 변환을 신경 쓸 필요가 없다. 그저 텍스트 모드로 파일을 개방만하면 된다. 
텍스트 모드의 파일 개방을 위해서는 fopen 함수의 두 번째 인자로 
rt, wt, at, r+t, w+t, a+t
중 하나를 전달해야 한다.

반대로 바이너리 데이터를 저장하고 있는 파일의 경우는 형태의 변환이 이러나면 안되기 때문에(아무런 변환도 일어나면 안되기 때문에) 바이너리 모드로 파일을 개방해야 한다.
바이너리 모드의 파일 개방을 위해서는 fopen함수의 두 번째 인자로 
rb, wb, ab, r+b, w+b, a+b
중 하나를 전달해야 한다.

참고로 t도 b도 붙여주지 않으면 파일은 텍스트 모드로 개방된다는 사실도 알아두기 바란다. 
w+t나 wt+는 같은 의미이다. 나머지 개방 모드도 비슷하다. 


#파일 입출력 함수의 기본


  -Chapter 21에서 학습한 파일 입출력 함수들
int fputc(int c, FILE * stream); // 문자 출력
int fgetc(FILE * stream); // 문자 입력
int fputs(const char * s, FILE * stream); // 문자열 출력
char * fgets(char *s, int n, FILE * stream); // 문자열 입력

예제TextDataFileWrite.c
#include <stdio.h>
int main()
{
  FILE * fp=fopen("simple.txt", "wt");
  if(fp == NULL) {
    puts("파일 열기 실패!");
    return -1;
  }

  fputc('A', fp);
  fputc('B', fp);
  fputs("My name is cong \n", fp);
  fputs("Your name is bob \n", fp);
  fclose(fp);
  
  return 0;
}
위 예제는 문자와 문자열을 출력하고 있으며, 문자열 안에는 개행문자도 포함되어 있다. 따라서 반드시 텍스트 모드로 파일을 개방해야 한다.

예제TextDataFileRead.c
#include <stdio.h>
int main()
{
  char str[30];
  int ch;
  FILE * fp=fopen("simple.txt", "rt");
  
  if(fp == NULL) {
    puts("파일 열기 실패!");
    return -1;
  }
  
  ch=fgetc(fp);
  printf("%c\n", ch);
  ch=fgetc(fp);
  printf("%c\n", ch);
  ch=fgets(str, sizeof(str), fp);
  printf("%s \n", str);
  ch=fgets(str, sizeof(str), fp);
  printf("%s \n", str);
  fclose(fp);
  
  return 0;
}

  -feof 함수 기반의 파일복사 프로그램
#include <stdio.h>
int feof(FILE * stream);
-> 파일의 끝에 도달한 경우 0이 아닌 값 반환

feof() 함수는 인자로 전달된 FILE 구조체의 포인터를 대상으로 더 이상 읽어들일 데이터가 존재하지 않으면(파일의 끝까지 모두 읽어들인 상태면) 0이 아닌 값을 반환한다. 파일의 끝을 확인해야 하는 경우에 유용하게 사용된다.
예제TextCharFileCopy.c
#include <stdio.h>
int main()
{
  FILE * src = fopen("src.txt", "rt");
  FILE * des = fopen("dst.txt", "wt");
  int ch;

  if(src == NULL || des == NULL) {
    puts("파일 열기 실패!");
    return -1;
  }
  while((ch=fgetc(src)) != EOF)
    fputc(ch, des);

  if(feof(src)!=0)
    puts("파일복사 완료!");
  else
    puts("파일복사 실패!");

  fclose(src);
  fclose(des);
  
  return 0;
}

예제TextStringFileCopy.c
#include <stdio.h>
int main()
{
  char str[20];
  FILE * src = fopen("src.txt", "rt");
  FILE * des = fopen("des.txt", "wt");
  if(src == NULL || des == NULL) {
    puts("파일 열기 실패!");
    return -1;
  }
  while((str=fgets(str, sizeof(str), src)) != NULL)
    fputs(str, des);

  if(feof(src)!=0)
    puts("파일 복사 완료!");
  else
    puts("파일 복사 실패!");

  fclose(src);
  fclose(des);

  return 0;
}
fgets함수는 파일의 끝에 도달해서 더 이상 읽을 데이터가 존재하지 않거나 오류가 발생하는 경우 NULL을 반환한다. 때문에 위 예제세어 파일복사의 성공을 확인하기 위해 feof함수를 호출했다.

  -바이너리 데이터의 입출력: fread, fwrite
#include <stdio.h>
size_t fread(void * buffer, size_t size, size_t count, FILE * stream);
-> 성공 시 전달인자 count, 실패 또는 파일의 끝 도달 시 count보다 작은 값 반환

fread함수는 다음과 같이 호출된다.
int buf[12];
fread((void*)buf, sizeof(int), 12, fp); // fp는 FILE 구조체 포인터
sizeof(int)크기의 데이터 12개를 fp로부터 읽어들여서 배열 buf에 저장하라는 의미다. fread함수는 두 번째 전달인자와 세 번째 전달인자의 곱의 바이트 크기만큼 데이터를 읽어 들이는 함수다. 

#include <stdio.h>
size_t fwrite(const void * buffer, size_t size, size_t count, FILE * stream);
-> 성공 시 전달인자 count, 실패 시 count보다 작은 값 반환

fwrite함수는 다음과 같이 호출된다.
int buf[7]={1,2,3,4,5,6,7,};
fwrite((void*)buf, sizeof(int), 7, fp);
sizeof(int)크기의 데이터 7개를 buf로부터 읽어서 fp에 저장하라는 의미다.

예제BinaryFileCopy.c
#include <stdio.h>
int main()
{
  FILE * src = fopen("src.bin", "rb");
  FILE * des = fopen("dst.bin", "wb");
  char buf[20];
  int readCnt;

  if(src==NULL || des==NULL) {
    puts("파일 열기 실패!");
    return -1;
  }

  while(1)
  {
    readCnt=fread((void*)buf, 1, sizeof(buf), src);

    if(readCnt<sizeof(buf))
    {
      if(feof(src)!=0)
      {
        fwrite((void*)buf, 1, readCnt, des);
        puts("파일 복사 완료!");
        break;
      }
      else
        puts("파일 복사 실패!");
    }
    fwrite((void*)buf, 1, sizeof(buf), des);
  }

  fclose(src);
  fclose(des);
  
  return 0;
}

위 예제는 복사 프로그램이다. 
복사 프로그램은 다음의 성격을 지닌다.
READ/WRITE 동시에 진행해야 한다.
파일의 끝에 도달했는지를 확인해야 한다.


#텍스트 데이터와 바이너리 데이터를 동시에 입출력하기

  -서식에 따른 데이터 입출력: fprintf, fscanf
이 두 함수는 printf, scanf 함수와 유사하지만 입출력의 대상이 콘솔이 아닌 파일이라는 점에서 차이가 있다.

fprintf 함수의 호출방법
char name[10]="권소련"; // text data
char sex='M'; // text data: man M, woman F.
int age=24; // binary data
fprintf(fp, "%s, %c, %d", name, sex, age); // fp는 FILE 구조체 포인터

printf함수의 호출문과 차이를 보이는 부분은 FILE 구조체의 포인터가 첫 번째 전달인자라는 점이다. 결국 텍스트 데이터와 바이너리 데이터를 하나의 문자열로 묶어서 저장하는 셈이다.
예제ComplexFileWrite.c
#include <stdio.h>
int main()
{
  char name[10];
  char sex;
  int age;

  FILE * fp=fopen("friend.txt", "wt");
  for(int i=0; i<3; i++)
  {
    printf("이름 성별 나이 순 입력: ");
    scanf("%s %c %d", name, &sex, &age);
    getchar(); // 버퍼에 남아있는 \n의 소멸을 위해서
    fprintf(fp, "%s %c %d", name, sex, age);
  }
  fclose(fp);
  
  return 0;
}

fscanf 함수의 호출방식
char name[10];
char sex;
int age;
fscanf(fp, "%s %c %d", name, &sex, &age);

scanf함수 호출문과 차이를 보이는 부분은 첫 번째 인자로 FILE 구조체의 포인터가 전달된다는 점이다. 그리고 fscanf함수는 파일의 끝에 도달하거나 오류가 발생하면 EOF를 반환한다.
예제ComplexFileRead.c
#include <stdio.h>
int main()
{
  char name[10];
  char sex;
  int age, ret;
  FILE * fp=fopen("friend.txt", "rt");
  while(1)
  {
    ret=fscanf(fp, "%s %c %d", name, &sex, &age);
    if(ret==EOF)
      break;
    printf("%s %c %d \n", name, sex, age);
  }
  
  fclose(fp);
  
  return 0;
}

  -텍스트와 바이너리 데이터의 집합체인 구조체 변수의 입출력
프로그램에서는 데이터들을 구조체로 묶어서 정의하는 것이 보통이다. 
typedef struct friend
{
  char name[10];
  char sex;
  int age;
} Friend;

구조체 변수 단위의 입출력이 구조체 멤버 단위의 입출력보다 입출력의 형태가 단순해질 수 밖에 없다. 구조체 변수를 하나의 바이너리 데이터로 인식하고 처리하면 구조체 변수를 통째로 저장하고 통째로 읽어들일 수 있다.

예제StructFileWriteRead.c
#include <stdio.h>

typedef struct friend
{
  char name[10];
  char sex;
  int age;
} Friend;

int main()
{
  FILE * fp;
  Friend myfriend1;
  Friend myfriend2;

  // file write 
  fp=fopen("friend.bin", "wb");
  printf("이름, 성별, 나이 순 입력: "); scanf("%s %c %d", name, &sex, &age);
  fwrite((void*)&myfriend1, sizeof(myfriend1), 1, fp);
  fclose(fp);

  // file read
  fp=fopen("friend.bin", "rb");
  fread((void*)&myfriend2, sizeof(myfriend2), 1, fp);
  printf("%s %c %d \n", myfriend2.name, myfriend2.sex, myfriend2.age);
  fclose(fp);
  
  return 0;
}

  -임의 접근을 위한 '파일 위치 지시자'의 이동
경우에 따라서는 파일의 중간 또는 마지막 부분에 저장된 데이터의 일부를 읽어야 하는 경우도 있다. 그리고 이러한 경우에는 '파일 위치 지시자'라는 것을 파일의 중간 또는 마지막 부분으로 이동시켜야 한다.

  -파일 위치 지시자란?
FILE 구조체의 멤버 중에는 파일의 위치 정보를 저장하고 있는 멤버가 있는데, 이 멤버의 값은 fgets, fputs 또는 fread, fwrite 와 같은 함수가 호출될 때마다 참조 및 갱신된다.
예를 들어 fgets 함수호출을 통해서 파일에 저장된 문자열을 읽어 들이는 경우, 이 멤버가 가리키는 위치를 시작으로 문자열을 읽어들이게 되며, 총 20바이트 크기의 문자열이 읽혀졌다고 가정하면, 이 멤버는 20바이트 뒤를 가리키게 된다.
이처럼 이 멤버에 저장된 위치 정보의 갱신을 통해 데이터를 읽고 쓸 위치 정보가 유지되는 것이다. 따라서 이 멤버를 가리켜 '파일 위치 지시자' 라 부르기로 약속했다.

  -파일 위치 지시자의 이동: fseek
#include <stdio.h>
int fseek(FILE * stream, long offset, int wherefrom);
-> 성공 시 0, 실패 시 0이 아닌 값을 반환

파일 위치 지시자를 직접 이동시키고자 할 때 fseek() 함수를 호출해야 한다.
함수는 세 개의 인자를 요구하는데 인자가 의미하는 바는 'stream으로 전달된 파일 위치 지시자를 wherefrom에서부터 offset 바이트만큼 이동시켜라'다.

wherefrom에 전달도리 수 있는 상수와 의미
매개변수 wherefrom 이 - 파일 위치 지시자는...
SEEK_SET(0)이라면 - 파일 맨 앞에서부터 이동을 시작
SEEK_CUR(1)이라면 - 현재 위치에서부터 이동을 시작
SEEK_END(2)이라면 - 파일 맨 끝에서부터 이동을 시작

매개변수 offset에는 양의 정수뿐만 아니라 음의 정수도 전달될 수 있다. 양의 정수가 전달되면 파일의 마지막을 향해 파일 위치 지시자가 이동하지만, 음의 정수가 전달되면 파일의 시작 위치를 향해 파일 위치 지시자가 이동을 한다.
fseek 함수의 호출 시 언급하고자 하는 사항
SEEK_SET 전달 시 첫 번째 바이트에서부터 이동을 시작한다.
SEEK_END 전달 시 EOF 에서부터 이동을 시작한다.
fseek 함수의 두 번째 인자로 음수가 전달되면 왼쪽으로(앞 부분으로) 이동을 한다.

일반적으로 SEEK_END가 전달되면 파일의 끝에서부터 이동이 시작된다 했는데 여기서 말하는 파일의 끝은 파일의 마지막 데이터가 아닌, 파일의 끝을 표시하기 위해 삽입이 되는 EOF를 의미함에 주의해야 한다.

예제MoveFileReWrPos.c
#include <stdio.h>
int main()
{
  //file create
  FILE * fp=fopen("text.txt", "wt");
  fputs("123456789", fp);
  fclose(fp);

  //file open
  fp=fopen("text.txt", "rt");

  //SEEK_END test
  fseek(fp, -2, SEEK_END);
  putchar(fgetc(fp);

  //SEEK_SET test
  fseek(fp, 2, SEEK_SET);
  putchar(fgetc(fp));

  //SEEK_CUR test
  fseek(fp, 2, SEEK_CUR);
  putchar(fgetc(fp));

  fclose(fp);
  
  return 0;
}

  -현재 파일 위치 지시자의 위치는?: ftell
#include <stdio.h>
long ftell(FILE * stream);
-> 파일 위치 지시자의 위치 정보 반환

현재의 파일 위치 지시자 정보를 확인하고 싶다면 ftell() 함수를 호출하면 된다.
파일 위치 지시자가 첫 번째 바이트를 가리킬 경우 0을 반환하고, 세 번째 바이트를 가리킬 경우 2를 반환한다. 이처럼 가장 앞 부분의 바이트 위치를 0으로 간주한다는 점에 주의해야 한다.

예제TellFileReWrPos.c
#include <stdio.h>
int main()
{
  long fpos;

  //file create
  FILE * fp=fopen("text.txt", "wt");
  fputs("1234-", fp);
  fclose(fp);

  //file open
  fp=fopen("text.txt", "rt");

  for(int i=0; i<4; i++)
  {
    putchar(fgetc(fp));
    fpos=ftell(fp);
    fseek(fp, -1, SEEK_END);
    putchar(fgetc(fp));
    fseek(fp, fpos, SEEK_SET);
  }
  fclose(fp);
  
  return 0;
}
ftell 함수는 파일 위치 지시자의 정보를 임시롤 저장할 때 유용하게 사용된다.


*/
