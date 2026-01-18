#include <stdio.h>
#include "Time.h"
#include "Lesson.h"
#include "DaySchedule.h"

int main() {
    schedule monday;
    
    Time start = {10, 0};
    Time end = {11, 0};
    Lesson math = create_Lesson(1, "Math", 20, start, end);
    init_schedule(&monday, "Monday");
    add_lesson(&monday, &math);
    print_day(&monday);
    return 0;
}