#include <stdio.h>
#include "Time.h"
#include "Lesson.h"
#include "DaySchedule.h"

int main() {
    schedule monday;
    
    Time start = {10, 0};
    Time end = {11, 0};
    Time endl = {13, 00};
    Time statr = {12, 00};
    Lesson math = create_Lesson(1, "Math", 20, start, end);
    Lesson language = create_Lesson(2, "English Language", 10, statr, endl);
    init_schedule(&monday, "Monday");
    add_lesson(&monday, &math);
    add_lesson(&monday, &language);
    print_day(&monday);
    return 0;
}
