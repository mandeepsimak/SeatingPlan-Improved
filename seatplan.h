#include "subject-wise-rollno.h"

class SeatPlan : public SubjectWiseRollNo
{
    protected:
        int total_seats, total_students, room_size[MIN_SIZE][MIN_SIZE],
            strategy_choice, total_group_seats, temp[MIN_SIZE], 
            index_value[MIN_SIZE], group_student_size[MIN_SIZE];
            
        string seat[MIN_SIZE][MIN_SIZE][MIN_SIZE][MIN_SIZE]; // seatplan array
        string seat_rollno[MIN_SIZE][MAX_SIZE];
        
        int seat_size[MIN_SIZE];
        
        // for loop variables
        int centre, room, row, col;
        int s, start, end, index; // temp
    
    public:
        void setRollNo(int);
        void seatingPlan(int);
        void createFile();        
};
