#include "expand-rollno.h"

void ExapandRollNo :: expandInput()
{
   readRoomsInput(Input_Rooms);
   readRollNoInput(Input_Rollno);
   readSubjectCode(Input_SubjectCode);
}

void ExapandRollNo :: addSeperator()
{
   string a="0";
   
   for(j = 0; j < total_branches; j++)
   {
      int size = string_rollno[j].size() + 1;
      char largchar[size]; // = roll[i].c_str();//"1-10 12 34 15 20 25-30";
      
      strcpy(largchar, string_rollno[j].c_str());
      char* chars_array = strtok(largchar, " ");
      a="0";
      while(chars_array)
      {
         if(chars_array!="-")
         {
            a.append(",");
            a.append(chars_array);//atoi (chars_array));//n++;
         }
         chars_array = strtok(NULL, " ");
      }
      string_rollno[j] = a;
   }
}

void ExapandRollNo :: expandRollNo()//string rollno)
{
   outfile.open(Rollno_Expand_out);
   
   for(i = 0; i < total_branches; i++)
   {
      istringstream rollno(string_rollno[i]);
      deque<int> v;
      
      bool success = expandRollNumberList(rollno, back_inserter(v));
      
      if (success)
      {
         roll_size[i] = v.size()-1;
         copy(v.begin(), v.end()-1, ostream_iterator<int>(outfile, " "));

         outfile << v.back() << endl;
      }
      else
         outfile << "an error occured." << endl;
   }
   outfile.close();
}

template<typename OutIter>
bool ExapandRollNo :: expandRollNumberList(istream& is, OutIter out)
{
   int number;
   // the list always has to start with a number
   while (is >> number)
   {
      *out++ = number;

      char c;
      if (is >> c)
         switch(c)
         {
            case ',':
               continue;
            case '-':
            {
               int number2;
               if (is >> number2)
               {
                  if (number2 < number)
                     return false;
                  while (number < number2)
                     *out++ = ++number;
                  char c2;
                  if (is >> c2)
                     if (c2 == ',')
                        continue;
                     else
                        return false;
                  else
                     return is.eof();
               }
               else
                  return false;
            }
            default:
               return is.eof();
         }
      else
         return is.eof();
   }
   // if we get here, something went wrong (otherwise we would have
   // returned from inside the loop)
   return false;
}

void ExapandRollNo :: removeZero()
{
   infile.open(Rollno_Expand_out);
   
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < roll_size[i] + 1; j++)
         infile >> roll_no[i][j];
   }
   
   infile.close();
   
   for(i = 0; i < total_branches; i++)
   {
      for(j=0; j < roll_size[i]-1; j++)
      {
         roll_no[i][j] = roll_no[i][j+1];
      }
      roll_size[i]--;
   }
}

void ExapandRollNo :: showExpandRollNo()
{
   outfile.open(Rollno_Expand_out);
   outfile << total_branches << endl;
   for(i = 0; i < total_branches; i++)
   {
      outfile << roll_size[i] << endl;
      for(j = 0; j < roll_size[i]; j++)
         outfile << roll_no[i][j] << " ";
      outfile << endl;
   }
   outfile.close();
}

void ExapandRollNo :: Main()
{
   expandInput();
   addSeperator();
   expandRollNo();
   removeZero();
   showExpandRollNo();
}
