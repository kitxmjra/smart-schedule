#include "DaySchedule.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ф-ция выведения дня.

void print_day(const schedule* s) {
    printf("=== %s ===\n", s->day_name);
    if(s->count == 0) {
        printf("No lessons today\n");
        return;
    }
    for(int i = 0; i < s->count; i++) {
        print_lesson(&s->lessons[i]);
    }
}

// Ф-ция инициализации расписания.

void init_schedule(schedule* s, const char* name) {
    strncpy(s->day_name, name, 19);
    s->day_name[19] = '\0';
    s->capacity = 3;
    s->lessons = malloc(s->capacity * sizeof(Lesson));
    if(s->lessons == NULL) {
        printf("Memory allacation failed\n");
        exit(1);
    }
    s->count = 0;
    printf("Schedule '%s' initialized\n", s->day_name);
}

// Ф-ция очистки/освобождения памяти.

void free_schedule(schedule* s) {
    free(s->lessons);
    s->lessons = NULL;
    s->count = 0;
    s->capacity = 0;
    printf("Schedule '%s' freed\n", s->day_name);
}
void add_lesson(schedule* s, const Lesson* lesson) {
    s->lessons[s->count] = *lesson;
    s->count++;
    printf("Lesson has been added\n");
    }

