#ifndef DAYSCHEDULE_H
#define DAYSCHEDULE_H
#include "Lesson.h"


typedef struct {
    Lesson* lessons;
    char day_name[20];
    int count;
    int capacity;
    
} schedule;


void print_day(const schedule* s);
void init_schedule(schedule* s, const char* name);
void free_schedule(schedule* s);
void add_lesson(schedule* s, const Lesson* lesson);
int remove_lesson(schedule* s, int lesson_number);



#endif