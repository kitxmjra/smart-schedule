#include <stdio.h>
#include "Time.h"
Time creat_time(int h, int m) {
    Time t;
    if(h > 23 || h < 0 || m < 0 || m > 59) {
        printf("Uncorrect time! Time set 00:00\n");
        t.hour = 0;
        t.minute = 0;
    }
    else {
        t.hour = h;
        t.minute = m; 
    }
    return t;
}
void print_time(const Time* t) {
    printf("%02d;%02d;", t->hour, t->minute);
}
int time_less(const Time* a, const Time* b) {
    if(a->hour == b->minute)
        return a->minute < b->minute;
    return a->hour < b->hour;
}
int time_equal(const Time* a, const Time* b) {
    return a->hour == b->hour && a->minute == b->minute;
}
int time_is_valid(const Time* t) {
    if(t->hour < 0 || t->hour > 23) return 0;
    if(t->minute < 0 || t->minute > 59) return 0;
    return 1;
}