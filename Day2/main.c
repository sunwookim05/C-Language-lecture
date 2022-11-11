#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define import extern

typedef char* String;

#pragma pack(push, 1)
typedef struct Calcultor{
    double a;
    double b;
    char op;
    double (*plus)(double, double);
    double (*minus)(double, double);
    double (*multiply)(double, double);
    double (*divide)(double, double);
    double (*mod)(double, double);
    double (*pow)(double, double);
    double (*result[6])(double, double);
    char (*get_op)(char);
    struct Calcultor *this;    
} Calculator;
#pragma pack(pop)

Calculator *new_Calculator(){
    Calculator *this = (Calculator*)malloc(sizeof(Calculator));
    import char get_op(char);
    import double plus(double, double);
    import double minus(double, double);
    import double multiply(double, double);
    import double divide(double, double);
    import double mod(double, double);
    import double pow(double, double);

    this->plus = plus;
    this->minus = minus;
    this->multiply = multiply;
    this->divide = divide;
    this->mod = mod;
    this->pow = pow;
    this->get_op = get_op;
    this->result[0] = this->plus;
    this->result[1] = this->minus;
    this->result[2] = this->multiply;
    this->result[3] = this->divide;
    this->result[4] = this->mod;
    this->result[5] = this->pow;

    return this;
}

void delete_Calculator(Calculator *this){
    free(this);
}

int main(void){
    Calculator *cal = new_Calculator();

    scanf("%lf %c %lf", &cal->a, &cal->op, &cal->b);
    printf("%.1000g %c %.1000g = %.1000g", cal->a, cal->op, cal->b, cal->result[cal->get_op(cal->op)](cal->a, cal->b));

    delete_Calculator(cal);

    return 0;
}

double plus(double a, double b){
    return a + b;
}

double minus(double a, double b){
    return a - b;
}

double multiply(double a, double b){
    return a * b;
}

double divide(double a, double b){
    return a / b;
}

double mod(double a, double b){
    return (int)a % (int)b;
}

double pow(double a, double b){
    double result = a; 
    if(b == 0) 
        return 1;
    else if(a == 0) 
        return 0; 
    else 
        for(int i = 0; i < (b - 1); i++) 
            result *= a; 
    return result;
}

char get_op(char op){
    return op == '+' ? 0 : op == '-' ? 1 : op == '*' ? 2 : op == '/' ? 3 : op == '%' ? 4 : op == '^' ? 5 : -1;
}