#ifndef TIME_H
#define TIME_H

typedef struct {
    int hour;
    int minute;
} Time;
Time creat_time(int h, int m);
void print_time(const Time* t);
int time_less(const Time* a, const Time* b);
int time_equal(const Time* a, const Time* b);

#endif
