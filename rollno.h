#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include "file-names.h"

using namespace std;

const int MIN_SIZES = 50;
const int MAX_SIZES = 100;

class RollNo
{
   
    int rollno[MIN_SIZES][MAX_SIZES], total_rno[MIN_SIZES], total_branches, 
        set_rollno[MIN_SIZES][MAX_SIZES], n, set_trno[MIN_SIZES],
        i, j, k, total_rooms, rows[MIN_SIZES], cols[MIN_SIZES], row, col,
        seat[MIN_SIZES][MIN_SIZES][MAX_SIZES], x, y, z, X, Y, C, D;
//        count[MIN_SIZES], start_rno[MIN_SIZES], end_rno[MIN_SIZES], max_rno;
    
    string room_no[MIN_SIZES], subjectCode[MIN_SIZES];
    
    string exam_name, exam_date, exam_time;
    
    static int A, B, Z;
    
    ifstream infile;
    ofstream outfile;
    
    public:
    
    RollNo();
    void get_details();
    void show_details();
    void arrange_rollno(int strategy);
    void seat_alot(int strategy);
    void next_rollno(int strategy);
    string branch(int rno);
    void count_rollno();
};

