#ifndef LESSON_H
#define LESSON_H


#include "Time.h"
typedef struct {
    char subject[50];
    int room;
    int number;
    Time start;
    Time end;
} Lesson;

Lesson create_Lesson(int num, const char* subj, int room, Time start, Time end);
void print_lesson(const Lesson* l);
void change_room(Lesson* l, int new_room);
int is_math(const Lesson* l);



#endif