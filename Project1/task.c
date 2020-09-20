#include <stdio.h>        

const TOO_MANY_NUMBERS = -1;
const NO_LITERALS = -2;
const ERROR = -3;
const int limits[3] = { 23, 59, 59 };
const char* time_names[3] = {"hours", "mins", "secs"};

int is_digit(char c) {
    return '0' <= c && c <= '9';
}

int make_digit(char c) {
    return c - '0';
}

int check_time(int time, int i) {
    if (time > limits[i]) {
        printf("too many numbers in %s\n should be max %d\n", time_names[i], limits[i]);
        return TOO_MANY_NUMBERS;
    } 
    return 0;
}

int check_sym(char sym, int time, int* i) {
    if (':' == sym) {
        int index = *i;
        (*i)++;
        return check_time(time, index);
    }
    if (is_digit(sym)) {
        return time * 10 + make_digit(sym);
    } else {
        printf("avoid literals %c in %s", sym, time_names[*i]);
        return NO_LITERALS;
    }
}

void proccess_str(char* s) {
    int time[3] = { 0, 0, 0 };
    int i;
    for (i = 0;  *s; s++) {
        time[i] = check_sym(*s, time[i], &i);
        if (time[i] < 0) return;
    }
    check_time(time[i], i);
    printf("finished correctly! %d %d %d", time[0], time[1], time[2]);
    return;
}

int main(void)                  
{                               
    char str[80];
    printf("Enter a string: ");
    scanf("%s", str);
    proccess_str(str);
    return 0;                   // выходим из функции
}