#include "subject-wise-rollno.h"

void SubjectWiseRollNo :: setSubCode()
{
   subject_size = 0;
   for(i = 0; i < total_branches; i++)
   {
      subject_size += total_subject[i];
   }
   i = 0;
   // Putting values of subject code into another array set_subcode
   //for(i = 0; i < subject_size; i++)
   {
      for(j = 0; j < total_branches; j++)
      {
         for(k = 0; k < total_subject[j]; k++)
          {
            set_subcode[i] = subject_code[j][k];
            i++;
         }
      }
   }
    
}

void SubjectWiseRollNo :: removeRedundantSubCode()
{
   // Removing redundancy from set_subcode array
   total_code = total_branches;
       
   for(k = 0; k < total_code; k++)
   {
      for(i = k+1; i < total_code; i++)
      {
         if(set_subcode[i] == set_subcode[k])
         {
            for(j = i; j < total_code; j++)
            {
               set_subcode[j] = set_subcode[j+1];   
            }
            total_code--;  
         }
      }
   }
}

void SubjectWiseRollNo :: subjectWiseRollNo()
{
   setSubCode();
          
   removeRedundantSubCode();
       
   for(i = 0; i < total_code; i++)
   {
      set_totalrno[i] = 0;
   }
    
   // Adding roll nos
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_code; j++)
      {
         for(l = 0; l < total_subject[i]; l++)
         {
            if(set_subcode[j] == subject_code[i][l])
            {
               for(k = 0; k < roll_size[i][l]; k++)
               {
                  set_rollno[j][(k + set_totalrno[j])] = roll_no[i][l][k];
               }
               set_totalrno[j] += roll_size[i][l];
            }
         }
      }
   }
    
}

void SubjectWiseRollNo :: showSubjectWiseRollNo()
{
   outfile.open(Subjectwise_Rollno_out);
   outfile << total_code << endl;
   for(i = 0; i < total_code; i++)//SizeOfArray(set_rollno)
   {
      //        outfile<<'\n'<<set_subcode[i]<<endl;
      outfile << set_subcode[i] << " " << set_totalrno[i] << ' ';
      
      for(j = 0; j < set_totalrno[i]; j++)//SizeOfArray(set_rollno[0])
         outfile<<set_rollno[i][j]<<"\t";
      outfile<<endl;
   }
   outfile.close();
}

void SubjectWiseRollNo :: Main()
{
   ArrangeRollNo :: Main();
   subjectWiseRollNo();
   showSubjectWiseRollNo();
}
