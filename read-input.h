#include "header.h"

// Reading input files

class ReadInput
{
   protected:
      
      // Room Variables
      int total_rooms, rows[MIN_SIZE], cols[MAX_SIZE];
      string room_no[MIN_SIZE];
      
      // Roll No details
      int total_branches;
      string branch_name[MIN_SIZE], string_rollno[MIN_SIZE];
      
      // Subject Code Variables
      int total_subject[MIN_SIZE];
      string subject_code[MIN_SIZE][MIN_SIZE];
      
      // Loop variables
      int i, j, k;
      
      // File variables
      ifstream infile;
      ofstream outfile;
      
   public:
   
      void readRoomsInput(string);  // Rooms details
      void readRollNoInput(string); // Roll No Details
      void readSubjectCode(string); // Subject code Details
      void showDetails();  // for checking purpose
      void Main();
};
