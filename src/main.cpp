#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
class Time {
  int hour;
  int minute;
public:
  Time(int h = 0, int m = 0) {
    if(h > 23 || h < 0 || m < 0 || m > 59) {
      std::cout << "Uncorrect time! Time set 00:00" << std::endl;
      hour = 0;
      minute = 0;
    }
    else {
      hour = h;
      minute = m;
    }
  }
  void printTime() const {
    std::cout << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute;
  }
  bool operator<(const Time& other) const {
    if (hour == other.hour) return minute < other.minute;
    return hour < other.hour;
  }
  bool operator==(const Time& other) const {
    return hour == other.hour && minute == other.minute;
  }
  int getHour() const { return hour; }
  int getMinute() const { return minute; }
};
class Lesson {
  std::string subjects;
  int roomnumber;
  int lessnumber;
  Time startTime;
  Time endTime;
public:
      Lesson(int lessn, std::string subj, int room, Time start, Time end) : subjects(subj), roomnumber(room), lessnumber(lessn), startTime(start), endTime(end) {
      }
      void printInfo() const {
        if (lessnumber >= 10 || lessnumber <= 0) {
        std::cout << lessnumber << " Impossible" << std::endl;
        return;
      }
      else {
        std::cout << lessnumber << ". " << subjects << " (class number - " << roomnumber << ") ";
        std::cout << "[";
        startTime.printTime();
        std::cout << " - ";
        endTime.printTime();
        std::cout << "]" << std::endl; 
      }
      if (endTime < startTime) {
        std::cout << "Warning! End time is faster than start time" << std::endl;
      }
      }
      void changeRoom(int newRoom) {
        roomnumber = newRoom;
        std::cout << "Room has changed to " << newRoom << std::endl; 
      }
      bool isMath() const {
        return subjects == "Math" || subjects == "Algebra";
      }

};
class DaySchedule {
    std::string dayName;
    std::vector<Lesson> lessons;
    
public:
    DaySchedule(std::string name) : dayName(name) {}
    
    void addLesson(const Lesson& lesson) {
      if(lessons.size() >= 10) {
        std::cout << "No more than 10 lessons!!";
        return;
      } 
        lessons.push_back(lesson);
    }
    void printDay() const {
        std::cout << "=== " << dayName << " ===" << std::endl;
        for(const auto& lesson : lessons) {
            lesson.printInfo();
        }
    } 
};
int main() {
        Lesson math(4, "Math", 221, Time(11, 30), Time(12, 30));
        Lesson physics(3, "Physics", 234, Time(10, 30), Time(11, 30 ));
        physics.printInfo();
        math.printInfo();
        if(math.isMath()) {
          std::cout << "It's Math!" << std::endl;
        }
        physics.changeRoom(241);
        physics.printInfo();
        DaySchedule monday("Monday");
        monday.addLesson(Lesson(1, "Biology", 122, Time(8, 30), Time(9, 30)));
        monday.addLesson(Lesson(2, "History", 4, Time(9, 30), Time(10, 30)));
        monday.addLesson(Lesson(3, "Physics", 241, Time(10, 30), Time(11, 30)));
        monday.addLesson(Lesson(4, "Math", 221,Time(11, 30), Time(12, 30)));
        monday.printDay();
        return 0;      
      } 
