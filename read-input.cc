#include "read-input.h"

void ReadInput :: readRollNoInput(string file)
{
   infile.open(file.c_str());
   infile >> total_branches;
   getline(infile, string_rollno[0], '\n');
   for(i = 0; i < total_branches; i++)
   {
      getline(infile, string_rollno[i], '\n');
   }
   infile.close();
}

void ReadInput :: readRoomsInput(string file)
{
   infile.open(file.c_str());
   infile >> total_rooms;
   for (i = 0; i < total_rooms; i++)
   {
      infile >> room_no[i] >> rows[i] >> cols[i];
   }
   infile.close();
}

void ReadInput :: readSubjectCode(string file)
{
   infile.open(file.c_str());
   for(i = 0; i < total_branches; i++)
   {
      infile >> branch_name[i] >> total_subject[i];
      for(j = 0; j < total_subject[i]; j++)
         infile >> subject_code[i][j];
   }
   infile.close();
}


void ReadInput :: showDetails()
{
   outfile.open(Checking);
   outfile << total_branches << endl;
//   cout << total_branches;
   for (i = 0; i < total_branches; i++)
   {
      outfile << string_rollno[i] << "\n" << branch_name[i] << "\n";// << endl;
   }
   outfile.close();
}

void ReadInput :: Main()
{
   readRoomsInput(Input_Rooms);
   readRollNoInput(Input_Rollno);
   readSubjectCode(Input_SubjectCode);
//   showDetails();  // For Checking purpose
}
