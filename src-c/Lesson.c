#include <stdio.h>
#include <string.h>
#include "Lesson.h"


Lesson create_lesson(int num, const char* subj, int room, Time start, Time end) {
    Lesson l;
    l.number = num;
    strncpy(l.subject, subj, sizeof(l.subject) - 1);
    l.subject[sizeof(l.subject) - 1] = '\0';
    l.room = room;
    l.start = start;
    l.end = end;
    return l;
}
void print_lesson(const Lesson* l) {
    if(l->number >= 10 || l->number <= 0) {
        printf("%d Impossible\n", l->number);
    return;
    }

    printf("%d. %s (room %d) ", l->number, l->subject, l->room);
    print_time(&l->start);
    printf(" - ");
    print_time(&l->end);
    printf("\n");
    if(time_less(&l->end, &l->start)) {
        printf(" Alarm! Lesson end faster than start\n");
    }

}
void change_room(Lesson* l, int new_room) {
    l->room = new_room;
    printf("Room changed to %d\n", new_room);
}
int is_math(const Lesson* l) {  
    return strcmp(l->subject, "Math") == 0 ||
           strcmp(l->subject, "Algebra") == 0;
}

