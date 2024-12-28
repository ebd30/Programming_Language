/*
#Appendix-A: 아스키 코드 표

DEC	OCT	HEX	BIN	Symbol	HTML Number	HTMLName	Description
0	000	00	00000000	NUL	&#000;	 	Null char
1	001	01	00000001	SOH	&#001;	 	Start of Heading
2	002	02	00000010	STX	&#002;	 	Start of Text
3	003	03	00000011	ETX	&#003;	 	End of Text
4	004	04	00000100	EOT	&#004;	 	End of Transmission
5	005	05	00000101	ENQ	&#005;	 	Enquiry
6	006	06	00000110	ACK	&#006;	 	Acknowledgment
7	007	07	00000111	BEL	&#007;	 	Bell
8	010	08	00001000	BS	&#008;	 	Back Space
9	011	09	00001001	HT	&#009;	 	Horizontal Tab
10	012	0A	00001010	LF	&#010;	 	Line Feed
11	013	0B	00001011	VT	&#011;	 	Vertical Tab
12	014	0C	00001100	FF	&#012;	 	Form Feed
13	015	0D	00001101	CR	&#013;	 	Carriage Return
14	016	0E	00001110	SO	&#014;	 	Shift Out / X-On
15	017	0F	00001111	SI	&#015;	 	Shift In / X-Off
16	020	10	00010000	DLE	&#016;	 	Data Line Escape
17	021	11	00010001	DC1	&#017;	 	Device Control 1 (oft. XON)
18	022	12	00010010	DC2	&#018;	 	Device Control 2
19	023	13	00010011	DC3	&#019;	 	Device Control 3 (oft. XOFF)
20	024	14	00010100	DC4	&#020;	 	Device Control 4
21	025	15	00010101	NAK	&#021;	 	Negative Acknowledgement
22	026	16	00010110	SYN	&#022;	 	Synchronous Idle
23	027	17	00010111	ETB	&#023;	 	End of Transmit Block
24	030	18	00011000	CAN	&#024;	 	Cancel
25	031	19	00011001	EM	&#025;	 	End of Medium
26	032	1A	00011010	SUB	&#026;	 	Substitute
27	033	1B	00011011	ESC	&#027;	 	Escape
28	034	1C	00011100	FS	&#028;	 	File Separator
29	035	1D	00011101	GS	&#029;	 	Group Separator
30	036	1E	00011110	RS	&#030;	 	Record Separator
31	037	1F	00011111	US	&#031;	 	Unit Separator
32	040	20	00100000	 	&#32;	 	Space
33	041	21	00100001	!	&#33;	 	Exclamation mark
34	042	22	00100010	"	&#34;	&quot;	Double quotes (or speech marks)
35	043	23	00100011	#	&#35;	 	Number
36	044	24	00100100	$	&#36;	 	Dollar
37	045	25	00100101	%	&#37;	 	Procenttecken
38	046	26	00100110	&	&#38;	&amp;	Ampersand
39	047	27	00100111	'	&#39;	 	Single quote
40	050	28	00101000	(	&#40;	 	Open parenthesis (or open bracket)
41	051	29	00101001	)	&#41;	 	Close parenthesis (or close bracket)
42	052	2A	00101010	*	&#42;	 	Asterisk
43	053	2B	00101011	+	&#43;	 	Plus
44	054	2C	00101100	,	&#44;	 	Comma
45	055	2D	00101101	-	&#45;	 	Hyphen
46	056	2E	00101110	.	&#46;	 	Period, dot or full stop
47	057	2F	00101111	/	&#47;	 	Slash or divide
48	060	30	00110000	0	&#48;	 	Zero
49	061	31	00110001	1	&#49;	 	One
50	062	32	00110010	2	&#50;	 	Two
51	063	33	00110011	3	&#51;	 	Three
52	064	34	00110100	4	&#52;	 	Four
53	065	35	00110101	5	&#53;	 	Five
54	066	36	00110110	6	&#54;	 	Six
55	067	37	00110111	7	&#55;	 	Seven
56	070	38	00111000	8	&#56;	 	Eight
57	071	39	00111001	9	&#57;	 	Nine
58	072	3A	00111010	:	&#58;	 	Colon
59	073	3B	00111011	;	&#59;	 	Semicolon
60	074	3C	00111100	<	&#60;	&lt;	Less than (or open angled bracket)
61	075	3D	00111101	=	&#61;	 	Equals
62	076	3E	00111110	>	&#62;	&gt;	Greater than (or close angled bracket)
63	077	3F	00111111	?	&#63;	 	Question mark
64	100	40	01000000	@	&#64;	 	At symbol
65	101	41	01000001	A	&#65;	 	Uppercase A
66	102	42	01000010	B	&#66;	 	Uppercase B
67	103	43	01000011	C	&#67;	 	Uppercase C
68	104	44	01000100	D	&#68;	 	Uppercase D
69	105	45	01000101	E	&#69;	 	Uppercase E
70	106	46	01000110	F	&#70;	 	Uppercase F
71	107	47	01000111	G	&#71;	 	Uppercase G
72	110	48	01001000	H	&#72;	 	Uppercase H
73	111	49	01001001	I	&#73;	 	Uppercase I
74	112	4A	01001010	J	&#74;	 	Uppercase J
75	113	4B	01001011	K	&#75;	 	Uppercase K
76	114	4C	01001100	L	&#76;	 	Uppercase L
77	115	4D	01001101	M	&#77;	 	Uppercase M
78	116	4E	01001110	N	&#78;	 	Uppercase N
79	117	4F	01001111	O	&#79;	 	Uppercase O
80	120	50	01010000	P	&#80;	 	Uppercase P
81	121	51	01010001	Q	&#81;	 	Uppercase Q
82	122	52	01010010	R	&#82;	 	Uppercase R
83	123	53	01010011	S	&#83;	 	Uppercase S
84	124	54	01010100	T	&#84;	 	Uppercase T
85	125	55	01010101	U	&#85;	 	Uppercase U
86	126	56	01010110	V	&#86;	 	Uppercase V
87	127	57	01010111	W	&#87;	 	Uppercase W
88	130	58	01011000	X	&#88;	 	Uppercase X
89	131	59	01011001	Y	&#89;	 	Uppercase Y
90	132	5A	01011010	Z	&#90;	 	Uppercase Z
91	133	5B	01011011	[	&#91;	 	Opening bracket
92	134	5C	01011100	\	&#92;	 	Backslash
93	135	5D	01011101	]	&#93;	 	Closing bracket
94	136	5E	01011110	^	&#94;	 	Caret - circumflex
95	137	5F	01011111	_	&#95;	 	Underscore
96	140	60	01100000	`	&#96;	 	Grave accent
97	141	61	01100001	a	&#97;	 	Lowercase a
98	142	62	01100010	b	&#98;	 	Lowercase b
99	143	63	01100011	c	&#99;	 	Lowercase c
100	144	64	01100100	d	&#100;	 	Lowercase d
101	145	65	01100101	e	&#101;	 	Lowercase e
102	146	66	01100110	f	&#102;	 	Lowercase f
103	147	67	01100111	g	&#103;	 	Lowercase g
104	150	68	01101000	h	&#104;	 	Lowercase h
105	151	69	01101001	i	&#105;	 	Lowercase i
106	152	6A	01101010	j	&#106;	 	Lowercase j
107	153	6B	01101011	k	&#107;	 	Lowercase k
108	154	6C	01101100	l	&#108;	 	Lowercase l
109	155	6D	01101101	m	&#109;	 	Lowercase m
110	156	6E	01101110	n	&#110;	 	Lowercase n
111	157	6F	01101111	o	&#111;	 	Lowercase o
112	160	70	01110000	p	&#112;	 	Lowercase p
113	161	71	01110001	q	&#113;	 	Lowercase q
114	162	72	01110010	r	&#114;	 	Lowercase r
115	163	73	01110011	s	&#115;	 	Lowercase s
116	164	74	01110100	t	&#116;	 	Lowercase t
117	165	75	01110101	u	&#117;	 	Lowercase u
118	166	76	01110110	v	&#118;	 	Lowercase v
119	167	77	01110111	w	&#119;	 	Lowercase w
120	170	78	01111000	x	&#120;	 	Lowercase x
121	171	79	01111001	y	&#121;	 	Lowercase y
122	172	7A	01111010	z	&#122;	 	Lowercase z
123	173	7B	01111011	{	&#123;	 	Opening brace
124	174	7C	01111100	|	&#124;	 	Vertical bar
125	175	7D	01111101	}	&#125;	 	Closing brace
126	176	7E	01111110	~	&#126;	 	Equivalency sign - tilde
127	177	7F	01111111		&#127;	 	Delete

#Appendix-B: 수학관련 함수들

  -대표적인 수학 관련 함수들
함수 원형 - 기능
double fabs( double x )- x의 절대값을 반환하는 함수입니다.
double ceil( double x )- x보다 작지 않은 최소 크기의 정수를 반환합니다.
double floor( double x )- x보다 크지 않은 최대크기의 정수를 반환합니다.
double exp( double x )- 무리수 e의 x제곱을 반환합니다.
double pow( double x, double y )- x의 y제곱의 값을 반환합니다.
double log( double x ) - 자연로그 x의 값을 반환합니다.
double log10( double x )- log10 의 x값을 반환합니다.
double sqrt( double x )- 루트 x(x의 제곱근)을 반환합니다.

다음 두 함수는 수학관련 함수임에도 불구하고 정수형 연산을 하는 함수이기 때문에 헤더파일 stdlib.h에 선언돼있다.
int abs(int x); - x의 절댓값 반환
long labs(long x); - x의 절댓값 반환

  -사인(sine), 코사인(cosine), 탄젠트(tangent) 관련 함수들
아래의 함수들도 math.h에 선언돼 있으며, 각도는 라디안(radian)을 기준으로 계산이 된다.

함수 원형 - 기능
double cos( double x )- x의 코사인(cos) 값을 반환합니다.
double sin( double x ) - x의 사인(sin) 값을 반환합니다.
double tan( double x )- x의 탄젠트(tan) 값을 반환합니다.
double cosh( double x )- x의 쌍곡선 코사인(cos) 값을 반환합니다.
double sinh( double x )- x의 쌍곡선 사인(sin) 값을 반환합니다.
double tanh( double x )- x의 쌍곡선 탄젠트(tan) 값을 반환합니다.
double acos( double x )- x의 아크 코사인값을 반환합니다.
double asin( double x )- x의 아크 사인값을 반환합니다.
double atan( double x )- x의 아크 탄젠트값을 반환합니다.
double acosh( double x )- x의 쌍곡선 아크 코사인값을 반환합니다.
double asinh( double x )- x의 쌍곡선 사인값을 반환합니다.
double atanh( double x )- x의 쌍곡선 아크 탄젠트값을 반환합니다.

#Appendix-C: 가변인자 함수에 대한 이해
가변인자 함수를 소개하는 이유는 printf()와 scanf() 계열의 함수 선언을 이해할 수 있도록 돕는데 있다.

  -printf 함수와 scanf 함수의 사용 방법을 생각해 보면!
printf 함수와 scanf 함수의 공통점은 다음과 같다.
"첫 번째 전달인자인 문자열에 존재하는 서식문자의 수만큼 전달인자의 수도 증가한다."
즉, printf 함수와 scanf 함수는 전달인자의 수가 제한되어 있지 않다는 특징이 있다. 그렇다면 우리도 다음과 같은 형태의 호출이 가능한 함수를 정의할 수 있지 않을까(함수 Sum의 첫 번째 전달인자는 이후에 전달되는 인자의 갯수정보이다)?
num = Sum(2, 1, 2); // 1과 2의 합
num = Sum(3, 1, 2, 3); // 1과 2와 3의 합
num = Sum(4, 1, 2, 3, 4); //1,2,3 그리고 4의 합

Sum과 같은 형태의 호출이 가능한 함수를 가리켜 '가변인자 함수'라 하는데, 이 함수에 대한 모든 것은 헤더파일 stdarg.h에 선언되어 있다. 따라서 stdarg.h 에 선언되 내용들을 이해하면, 위와 같은 방식으로 호출 가느한 Sum 함수를 정의할 수 있다.

  -가변인자 매개변수의 선언방법
매개변수 선언을 통해서 함수호출 시 전달되어야 할 인자의 수와 자료형이 결정된다. 그런데 가변인자 함수는 호출이 될 때 비로소 인자의 수가 결정되기 때문에 다음 예제에서 보이는 형태대로 정의되어야 한다.
예제 소스코드
#include <stdio.h>
int Sum(int n, ...);
int main()
{
  Sum(2, 1, 2);
  Sum(3, 1, 2, 3);
  Sum(4, 1, 2, 3, 4);
  return 0;
}
int Sum(int n, ...) // ...은 가변인자에 대한 선언
{
  printf("n=%d \n", n);
  return 0;
}

가변인자에 대한 매개변수의 선언방식을 보았으니, 이제 가변인자의 정보 추출바법을 살펴봐야 한다. 위 예제는 인자의 전달방법만 설명했을 뿐, 전달된 인자의 참조방법은 보여주지 않고 있다.

  -전달된 인자들은 어떻게 추출해 내나요?
가변인자 함수의 호출을 통해서 전달되는 인자정보를 추출하기 위해서는 다음의 단계를 거쳐야 했다.
단계1: 가변인자를 가리킬 수 있는 참조자를 선언한다.
단계2: 참조자가 가변인자를 실제로 참조할 수 있도록 한다.
단계3: 참조자를 통해 전달된 정보를 추출한다.
단계4: 참조자가 더 이상 가벼닌자를 가리키지 않도록 해제한다.

그리고 각각의 기능을 제공하는 함수의 이름과 참조자의 자료형은 다음과 같으며, 이들을 사용하기 위해서는 헤더파일 stdarg.h를 포함해야 한다.
단계1: va_list
단계2: va_start
단계3: va_arg
단계4: va_end

예제 소스코드
#include <stdio.h>
#include <stdarg.h>
int Sum(int n, ...);
int main()
{
  printf("1+2=%d\n", Sum(2, 1, 2));
  printf("1+2+3=%d\n", Sum(3, 1, 2, 3));
  printf("1+2+3+4=%d\n", Sum(4, 1, 2, 3));
  return 0;
}
int Sum(int n, ...)
{
  int sum=0;
  int i;
  va_list vlist; // 단계1: 가변인자의 참조자 선언

  va_start(vlist, n); // 단계2: 참조 대상과 범위 지정
  for(i=0; i<n; i++)
    sum+=va_arg(vlist, int); // 단계3: 값의 추출

  va_end(vlist); // 단계4: 해제
  return sum;
}

*/
