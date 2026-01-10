#include <stdio.h>
#include "Time.h"
#include "Lesson.h"
#include "DaySchedule.h"

int main() {
    schedule monday;

    init_schedule(&monday, "Monday");
    print_day(&monday);
    free_schedule(&monday);
    return 0;
}