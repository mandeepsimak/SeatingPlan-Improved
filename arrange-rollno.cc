#include "arrange-rollno.h"

//void ArrangeRollNo :: arrangeInput()
//{
//   infile.open(Rollno_Expand_out);
//   infile >> total_branches;
//   for(i = 0; i < total_branches; i++)
//   {
//      infile >> roll_size[i];
//      for(j = 0; j < roll_size[i]; j++)
//         infile >> roll_no[i][j];
//   }
//}

void ArrangeRollNo :: readRollNoRow(int i)
{
   for(j = 0; j < roll_size[i]; j++)
   {
      rno[j] = roll_no[i][j];
   }
}

void ArrangeRollNo :: setRollNoRow(int i)
{
   for(j=0; j<roll_size[i]; j++)
   {
   	roll_no[i][j] = rno[j];
   }
}

void ArrangeRollNo :: sortRollNo()
{
   for(i = 0; i < total_branches; i++)
   {
      readRollNoRow(i);      
      sort(rno, rno + roll_size[i]);
      setRollNoRow(i);
   }
}

void ArrangeRollNo :: removeRedundancy()
{
   for(i = 0; i < total_branches; i++)
   {
      readRollNoRow(i);
            
      for(j = 0; j < roll_size[i]; j++)
      {	
         // Removing duplicate values
         if(rno[j] == rno[j+1])// || rno[j+1]==rno[j+2])
         {
            for(k = j; k <= roll_size[i]; k++) 
            {
               rno[k] = rno[k+1];  //shifts each element one position above
     			}
            roll_size[i]--;
            j=0;
         }
      }
      
      setRollNoRow(i);
   }
}

void ArrangeRollNo :: removeNonEligibleRollNo()
{
   for(i = 0; i < total_branches; i++)
   {
      readRollNoRow(i);
            
      for(j = 0; j < roll_size[i]; j++)
      {
         if(rno[j] < 0)	
         {
            int a,b;
            a = rno[j];
            b = -1 * a;
         
            for(k = 0; k < roll_size[i]; k++)
            {
               if(rno[k] == a || rno[k] == b)
               {
                  for (l = k; l <= roll_size[i]; l++) 
                     rno[l] = rno[l+1];  //shifts each element one position above
                     
                  roll_size[i]--;
               }
            }
            j--;
         }      
      }
      
      setRollNoRow(i);
   }
}

void ArrangeRollNo :: showArrangedRollNo()
{
   outfile.open(Rollno_Arranged_out);
   outfile << total_branches << endl;
   for(i = 0; i < total_branches; i++)
   {
      outfile << roll_size[i] << endl;
      for(j = 0; j < roll_size[i]; j++)
         outfile << roll_no[i][j] << " ";
      outfile << endl;
   }
   outfile.close();
   
   outfile.open(Input_Rollno_out);
   outfile << total_branches << endl;
   for(i = 0; i < total_branches; i++)
   {
      outfile << branch_name[i] << " ";
      for(j = 0; j < total_subject[i]; j++)
         outfile << subject_code[i][j];
      outfile << " " << roll_size[i] << endl;
      for(j = 0; j < roll_size[i]; j++)
         outfile << roll_no[i][j] << " ";
      outfile << endl;
   }
   outfile.close();
   
}

void ArrangeRollNo :: Main()
{
   ExapandRollNo::Main();
   sortRollNo();
   removeRedundancy();
   removeNonEligibleRollNo();
   showArrangedRollNo();
}
