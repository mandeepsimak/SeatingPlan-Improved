#include "report.h"

// Constructor for initialising values

RoomReport :: RoomReport()
{
   tab = "\t";
   newline = "\n";
   
   i = j = k = 0;
   
   // HTML Tag Variables
   bold = "<b>";  cbold = "</b>";
   table = "<table border = \"1\" align = \"center\" cellpadding = \"4\" >";   
   ctable = "</table>";
   th = "<th>";   cth = "</th>";
   tr = "<tr>";   ctr = "</tr>";
   td = "<td width = \"80\" height = \"30\" align = \"center\" valign = \"center\" >";   
   ctd = "</td>";
   brk = "<br>";
   div = "<div>";
   cdiv = "</div>";
   
   htmlstart = "<html> <head> <title>Seating Plan</title> <style type=\"text/css\"> div{page-break-after: always;}  </style> </head> <body align = \"center\"> ";
   htmlend = "</body></html>";
   // <style> div{ page-break-before: always; } </style> 
}

// Getting Allotment Details from "FinalAllotment.out" File

void RoomReport :: getAllotmentDetails()
{
   infile.open(FinalAllotment_out);
   
   infile >> total_rooms;
   
   for( i = 0; i < total_rooms; i++)
   {
      infile >> room_no[i] >> rows[i] >> cols[i];
      
      for(j = 0; j < rows[i]; j++)
      {
         for(k = 0; k < cols[i]; k++)
         {
            infile >> seat[i][j][k];
         }
      }
   }
   
   infile.close();
}

// Getting Roll No and Branch Details from "FinalAllotment.out" File

void RoomReport :: getRollNoDetails()
{
   infile.open(Input_Rollno_out);
   
   infile >> total_branches;
   
   for(i = 0; i < total_branches; i++)
   {
      infile >> branch_name[i] >> sub_code[i] >> total_rno[i];
      
      for(j = 0; j < total_rno[i]; j++)
      {
         infile >> rollno[i][j];
      }
   }
   
   infile.close();
}

// Get Examination Details

void RoomReport :: getExamDetails()
{
   cout << "\n\n\t Enter Examination Details \n" << endl
        << "\t\t Examination Name: ";
   getline(cin, exam_name, '\n');  //cin >> exam_name;
   
   cout << "\n\t\t Date: ";
   getline(cin, exam_date, '\n');  //cin >> exam_date;
   
   cout << "\n\t\t Time: ";
   getline(cin, exam_time, '\n');  //cin >> exam_time;
   
   cout << "\n\t\t Venue: ";
   getline(cin, exam_venue, '\n');  //cin >> exam_venue;
   
   cout << endl;
}

// Getting Branch Name accord. to roll no

string RoomReport :: branchName(int rno)
{
   string brnch;// = " ";

   if(rno > 0)
   {
      for(m = 0; m < total_branches; m++)
      {
         for(n = 0; n < total_rno[m]; n++)
         {
            if (rno == rollno[m][n])
            {
               brnch = branch_name[m];
               brnch += " ";
               std::stringstream srno;
               srno << rno;
               brnch += srno.str();
               //brnch += " ";
               //brnch += sub_code[m];
               count[m]++; // = count[i] + 1;
               sum++;  //= 1;
               if(rno < start_rno[m])
                  start_rno[m] = rno;
               if(rno > end_rno[m])
                  end_rno[m] = rno;
               break;
            }
         }
      }
   }
   
   else if (rno == 0)
      brnch  = " - ";
  
	return brnch;
}

void RoomReport :: showStudentDetails()
{
   outfile << newline;
   for(j = 0; j < total_branches; j++)
   {
      if(count[j] != 0)
         outfile << branch_name[j] << " ";
         
      if(start_rno[j] != 37657 && end_rno[j] !=0)
      {
         if(start_rno[j]== end_rno[j])
            outfile << "{ " << start_rno[j] << " } ";
         else
            outfile << "{ " << start_rno[j] << " to " << end_rno[j] << " } ";
      }
      
      if(count[j] != 0)
         outfile << " = " << count[j] << newline;
   }
   outfile << newline;
   outfile << "Total Students: " << sum << newline << newline;
   sum = 0;
   totalStudents();
}

// Total students in room
void RoomReport :: totalStudents()
{
   for( x = 0; x < total_branches; x++ )
	{
		count[x]=0;
		start_rno[x] = 37657;
		end_rno[x] = 0;
//		if(total_roll[x] > max_rno)
//			max_rno = total_roll[x];
	}
}

// Adding Branch Name

void RoomReport :: addBranchName()
{
   cout << "\n\t Add Branch Name with roll nos(Y/N): ";
   cin >> ans;
   cout << newline;
   
//   if ( ans == 'Y' || ans == 'y')
//      branchName(rno);
//   else
//      cout << "\n\t\t NOT ADDED!" << endl;
   
}

// Generating Report

void RoomReport :: generateReport()
{
   
   cout << "\n\t Generating Outfile for Seating Plan" << endl;
   
   cout << "\t Choose your file type.\n" << endl
        << " 1. Text File" << endl
        << " 2. HTML File" << endl
        << " 3. CSV File" << endl
        << " 4. PDF File " << endl
        << " 5. All Files " << endl
        << "\n Enter Choice: ";
   cin >> choice; 
   
   switch(choice)
   {
      case 1:
         createTextFile();
         cout << newline << tab << "Check " << TextFile << " File."
              << newline << endl;
         break;
         
      case 2:
         createHTMLFile();
         cout << newline << tab << "Check " << HTMLFile << " File." 
              << newline << endl;
         break;
         
      case 3:
         createCSVFile();
         cout << newline << tab << "Check " << CSVFile << " File." 
              << newline << endl;
         break;
         
      case 4:
         createPDFFile();
         cout << newline << tab << "Check " << PDFFile << " File." 
              << newline << endl;
         break;
      
      case 5:
         createAllFiles();
         cout << newline << tab << "Check All Files." << endl
              << TextFile << tab << CSVFile << tab 
              << HTMLFile << tab << PDFFile << newline << endl;
         break;
         
      default:
         createTextFile();
         break;
   }
   
}

// Creating File

void RoomReport :: createFile(const char* File)
{
   if(choice != 5)
      addBranchName();
   outfile.open(File);
   
   for( i = 0; i < total_rooms; i++)
   {
      outfile << tab << tab << "Room: " << room_no[i] << newline
              << tab << tab << exam_name << newline
              << tab << tab << "Date:" << exam_date 
              << tab << "Time: " << exam_time << newline
              << tab << tab << exam_venue << newline << newline;
      
      sum=0;
		totalStudents();
      
      for( j = 0; j < rows[i]; j++)
      {
         for(k = 0; k < cols[i]; k++)
         {
            if ( ans == 'Y' || ans == 'y')
               outfile << branchName(seat[i][j][k]) << tab;// << " " << seat[i][j][k] << tab;
            else
               outfile << seat[i][j][k] << tab;
         }
         
         outfile << newline;
      }
      
      showStudentDetails();
      
   }
   
   outfile.close();
}

// Creating Text File

void RoomReport :: createTextFile()
{
   createFile(TextFile);   
}

// Creating CSV File

void RoomReport :: createCSVFile()
{
   createFile(CSVFile);
}

// Creating HTML File

void RoomReport :: createHTMLFile()
{
   if (choice == 2)
      tab = "&nbsp &nbsp &nbsp &nbsp &nbsp";
   else
      tab = "     ";
//   newline = "<br>";
//   createFile(HTMLFile);
   if(choice != 5)
      addBranchName();
   outfile.open(HTMLFile);
   
   outfile << htmlstart << brk;
   
   for( i = 0; i < total_rooms; i++)
   {
      outfile << div;
      outfile << bold << "Room: " << room_no[i] << brk
              << exam_name << brk
              << "Date: " << exam_date << tab 
              << "Time: " << exam_time << brk
              << exam_venue << cbold << brk << brk;
              
      outfile << table << brk;
      
      outfile << tr;
      for( j = 0; j < (cols[i] + 1); j++)
      {
         outfile << th << j << cth;
      }
      outfile << ctr;
      
      for( j = 0; j < rows[i]; j++)
      {
         outfile << tr;
         outfile << td << bold << (j + 1) << cbold << ctd;
         for(k = 0; k < cols[i]; k++)
         {
            
            if ( ans == 'Y' || ans == 'y')
               outfile << td << branchName(seat[i][j][k]) << tab;// << " " << seat[i][j][k] << ctd;
            else
               outfile << td << seat[i][j][k] << ctd;
         }
         
         outfile << ctr;
         
      }
      outfile << ctable;
      
      newline = brk;
      showStudentDetails();
      
      outfile << brk;
      
      outfile << cdiv;
   }
   
   outfile << htmlend;
   
   outfile.close();
//   
//   if(choice == 2)
//      cout << newline << tab << "Check " << HTMLFile << " File." << endl;
//   
}

void RoomReport :: createPDFFile()
{
   createHTMLFile();
   string cmd;
   cmd = "wkhtmltopdf ";
   cmd += HTMLFile; 
   cmd += " ";
   cmd += PDFFile;
   
   tab = "\t";
   
   system(cmd.c_str());
}

// Creating All Files

void RoomReport :: createAllFiles()
{
   addBranchName();
   createTextFile();
   createCSVFile();
   createPDFFile();
   newline = '\n';
}

// Method for calling all functions

void RoomReport :: Main()
{
   system("clear");

   getAllotmentDetails();
   getRollNoDetails();

   getExamDetails();
   
   generateReport();
}

// ------------------ BranchReport Class Member Functions ----------------

BranchReport :: BranchReport()
{
   RoomReport();
}

void BranchReport :: Main()
{
   RoomReport :: Main();
   createBranchReport();
}

void BranchReport :: createBranchReport()
{

   // Text File
   
   outfile.open(BranchReportTextFile);
   
   for ( m = 0; m < total_branches; m++ )
   {
      outfile << "\t\t\t Branch: " << branch_name[m] << "\n" << endl
              << "\t\t Roll No. \t\t\t\t Room No. \n" << endl;
      
      for ( n = 0; n < total_rno[m]; n++)
      {
         string rm = checkRoom (rollno[m][n]);
         
         outfile << "\t\t " << rollno[m][n] 
                 << "\t\t\t\t " << rm << endl;
         
      }
      
      outfile << "\n--------------------------------------------------------"
              << "\n" << endl;
   }
   
   outfile.close();
   
   // HTML File
   
   outfile.open(BranchReportHTMLFile);
   
   outfile << htmlstart << brk;
   
   for ( m = 0; m < total_branches; m++ )
   {
      outfile << bold << " Branch: " << branch_name[m] << cbold << brk << endl
              << table << tr << th << " Roll No. " << cth << th << " Room No. "
              << cth << tr;
      
      for ( n = 0; n < total_rno[m]; n++)
      {
         string rm = checkRoom (rollno[m][n]);
         
         outfile << tr << td << rollno[m][n] << ctd
                 << td << rm << ctd << ctr;
         
      }
      
      outfile << ctable << brk << brk;
   }
   
   outfile << htmlend << brk;
   
   outfile.close();
   
   // PDF File
   
   string cmd;
   cmd = "wkhtmltopdf ";
   cmd += BranchReportHTMLFile; 
   cmd += " ";
   cmd += BranchReportPDFFile;
   
   tab = "\t";
   
   system(cmd.c_str());
   
   newline = '\n';
   
   cout << newline << tab << "Check Branch Reports." << endl;
   cout << BranchReportTextFile << tab 
        << BranchReportHTMLFile << tab << BranchReportPDFFile << newline << endl; 
   
}

string BranchReport :: checkRoom(int rno)
{
   string rm;
   for( i = 0; i < total_rooms; i++)
   {      
      for(j = 0; j < rows[i]; j++)
      {
         for(k = 0; k < cols[i]; k++)
         {
            if (rno == seat[i][j][k])
            {
               rm = room_no[i];
            }
         }
      }
   }
   return rm;
}
