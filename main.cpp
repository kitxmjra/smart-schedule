#include <iostream>
#include <vector>
#include <string>
class Lesson {
  std::string subjects;
  int roomnumber;
  int lessnumber;
public:
      Lesson(int lessonNumber, std::string subjectName, int roomNumber) {
        subjects = subjectName;
        roomnumber = roomNumber;
        lessnumber = lessonNumber;
      }
      void printInfo() const {
      if (lessnumber >= 10 || lessnumber <= 0) {
        std::cout << lessnumber << " Impossible" << std::endl;
      }
      else {
        std::cout << lessnumber << ". " << subjects << " (class number - " << roomnumber << ")" << std::endl; 
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
        Lesson math(4, "Math", 221);
        Lesson physics(3, "Physics", 234);
        physics.printInfo();
        math.printInfo();
        if(math.isMath()) {
          std::cout << "It's Math!" << std::endl;
        }
        physics.changeRoom(241);
        physics.printInfo();
        DaySchedule monday("Monday");
        monday.addLesson(Lesson(1, "Biology", 122));
        monday.addLesson(Lesson(2, "History", 4));
        monday.addLesson(Lesson(3, "Physics", 241));
        monday.addLesson(Lesson(4, "Math", 221));
        monday.printDay();
        return 0;      
      } 