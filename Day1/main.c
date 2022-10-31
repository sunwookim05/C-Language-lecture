#include <stdio.h>

int main(void){
    printf("Hello World!\n");//이스케이프 시퀀스: \n, \t, \b, \r, \a, \f, \v, \', \", \\ 언어특성상 출력할수 없는 문자를 출력할때 사용

    char a = 'A'; //1byte, 8bit 정수형, 문자표현, -128 ~ 127
    short b = 1; //2byte, 16bit 정수형, -32768 ~ 32767
    int c = 2; //4byte, 32bit 정수형, -2147483648 ~ 2147483647
    long long d = 4; //8byte, 64bit 정수형, -9223372036854775808 ~ 9223372036854775807
    float e = 5.0; //4byte, 32bit 실수형, 1.2E-38 ~ 3.4E+38
    double f = 6.0; //8byte, 64bit 실수형, 2.3E-308 ~ 1.7E+308
    long double g = 7.0; //16byte, 128bit 실수형, 3.4E-4932 ~ 1.1E+4932

    unsigned char h = 1; //1byte, 8bit 정수형, 0 ~ 255
    unsigned short i = 2; //2byte, 16bit 정수형, 0 ~ 65535
    unsigned int j = 3; //4byte, 32bit 정수형, 0 ~ 4294967295
    unsigned long long k = 4; //8byte, 64bit 정수형, 0 ~ 18446744073709551615

    const int l = 5; //상수형, 값 변경 불가   

    char m = 128; //오버플로우 발생, 128은 1byte에 저장할수 없는 값
    char n = -129; //언더플로우 발생, 127은 1byte에 저장할수 없는 값
    printf("%d %d\n", m, n); //출력결과: -128 127

    short o = 32768; //오버플로우 발생, 32768은 2byte에 저장할수 없는 값
    short p = -32769; //언더플로우 발생, -32769은 2byte에 저장할수 없는 값
    printf("%d %d\n", o, p); //출력결과: -32768 32767

    int q = 2147483648; //오버플로우 발생, 2147483648은 4byte에 저장할수 없는 값
    int r = -2147483649; //언더플로우 발생, -2147483649은 4byte에 저장할수 없는 값
    printf("%d %d\n", q, r); //출력결과: -2147483648 2147483647

    long long s = 9223372036854775808; //오버플로우 발생, 9223372036854775808은 8byte에 저장할수 없는 값
    long long t = -9223372036854775809; //언더플로우 발생, -9223372036854775809은 8byte에 저장할수 없는 값
    printf("%lld %lld\n", s, t); //출력결과: -9223372036854775808 9223372036854775807

    float u = 3.4E+39; //오버플로우 발생, 3.4E+39은 4byte에 저장할수 없는 값
    float v = 1.2E-39; //언더플로우 발생, 1.2E-39은 4byte에 저장할수 없는 값
    printf("%f %f\n", u, v); //출력결과: inf 0.000000

    double w = 1.7E+309; //오버플로우 발생, 1.7E+309은 8byte에 저장할수 없는 값
    double x = 2.3E-309; //언더플로우 발생, 2.3E-309은 8byte에 저장할수 없는 값
    printf("%lf %lf\n", w, x); //출력결과: inf 0.000000

    long double y = 1.1E+4933; //오버플로우 발생, 1.1E+4933은 16byte에 저장할수 없는 값
    long double z = 3.4E-4933; //언더플로우 발생, 3.4E-4933은 16byte에 저장할수 없는 값
    printf("%Lf %Lf\n", y, z); //출력결과: inf 0.000000

    unsigned char aa = 256; //오버플로우 발생
    unsigned short bb = 65536; //오버플로우 발생
    unsigned int cc = 4294967296; //오버플로우 발생
    unsigned long long dd = 18446744073709551616; //오버플로우 발생
    printf("%d %d %d %lld\n", aa, bb, cc, dd); //출력결과: 0 0 0 0

    unsigned char ee = -1; //언더플로우 발생
    unsigned short ff = -1; //언더플로우 발생
    unsigned int gg = -1; //언더플로우 발생
    unsigned long long hh = -1; //언더플로우 발생
    printf("%d %d %d %lld\n", ee, ff, gg, hh); //출력결과: 255 65535 4294967295 18446744073709551615

    return 0;
}