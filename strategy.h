#include "subject-wise-rollno.h"

class Strategy : public SubjectWiseRollNo
{
   protected:
      int choice, total_students, total_seats, group_seats, group_students
          min, max, min_pos;
   
   public:
   
      void Strategy();
      void chooseStrategy();
      void checkStrategyConditions(int);
      void totalStudents();
      void totalSeats();
      int maxStudent(int);
      void Main();
};
