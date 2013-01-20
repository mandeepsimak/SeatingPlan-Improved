#include "subject-wise-rollno.h"

class Strategy : public SubjectWiseRollNo
{
    protected:
        int total_seats, total_students, room_size[MIN_SIZE][MIN_SIZE],
            strategy_choice, total_group_seats;
    
    public:
        
        Strategy();
        void chooseStrategy();
        void totalSeats(int);
        void totalStudents();
        void checkValidation(int);
        void Main();
};
