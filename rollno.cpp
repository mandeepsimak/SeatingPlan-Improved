#include "rollno.h"

int RollNo :: A;
int RollNo :: B;
int RollNo :: Z;

RollNo :: RollNo()
{
    n = 0;
    row = col = 0;
    X = Y = 0;// Z = A = B = 0;
    C = D = 0;
}

void RollNo :: get_details()
{
    infile.open(Subjectwise_Rollno_out);
    infile>>total_branches;
    for(i = 0; i < total_branches; i++)
    {
    	
        infile >> subjectCode[i] >> total_rno[i];
        for(j = 0; j < total_rno[i]; j++)
        {
            infile>>rollno[i][j];
        }
    }
    infile.close();
    infile.open(Input_Rooms);
    infile>>total_rooms;
    for( i = 0; i < total_rooms; i++)
    {
        infile>>room_no[i]>>rows[i]>>cols[i];
    }
    infile.close();
}

void RollNo :: arrange_rollno(int strategy)
{
    if(n == 0)
    {
    	A=-1;
    	B=-1;
    	C=-1;
    	D=-1;
    	outfile.open("demo.txt");
        for(i = 0; i < strategy; i++)
        {
            for(j = 0; j < total_rno[n]; j++)
            {
                set_rollno[i][j] = rollno[n][j];
                
                outfile<<" " <<set_rollno[i][j];
            }
            set_trno[i] = total_rno[n];
            n++;
            outfile << "\n";
        }
		outfile.close();
    }
    else if(n < total_branches)
    {
        for(j = 0; j < total_rno[n]; j++)
        {
            set_rollno[Z][j] = rollno[n][j];
        }
        set_trno[Z] = total_rno[n];
        n++;
    }
    else
    {
        if( Z == 0 )
        {
            A = 0;
            set_trno[Z] = 0;
            set_rollno[Z][A] = 0;
        }
    
        if( Z == 1 )
        {
            B = 0;
            set_trno[Z] = 0;
            set_rollno[Z][B] = 0;
        }
        if( Z == 2 )
        {
            C = 0;
            set_trno[Z] = 0;
            set_rollno[Z][C] = 0;
        }
    
        if( Z == 3 )
        {
            D = 0;
            set_trno[Z] = 0;
            set_rollno[Z][D] = 0;
        }
    }
}

void RollNo :: next_rollno(int strategy)
{
    if( Z == 0 )
    {
        if(A >= set_trno[Z]-1)
        {
            arrange_rollno(strategy);
            A = 0;
        }
        else
            A++;
    }
    
    if( Z == 1 )
    {
        if(B >= set_trno[Z]-1)
        {
            arrange_rollno(strategy);
            B = 0;
        }
        else
            B++;
    }
    if( Z == 2 )
    {
        if(C >= set_trno[Z])
        {
            arrange_rollno(strategy);
            C = 0;
        }
        else
            C++;
    }
    
    if( Z == 3 )
    {
        if(D >= set_trno[Z])
        {
            arrange_rollno(strategy);
            D = 0;
        }
        else
            D++;
    }
    
    
}

void RollNo :: seat_alot(int strategy)
{
    arrange_rollno(strategy);
    for(z = 0; z < total_rooms; z++)
    {
        row = rows[z];
        col = cols[z];  
        
        for(x = 0; x < col; x++)
        {
          if((x % 2) != 0)
          {
             if(strategy == 2)
               Z = 1;
             if(strategy > 2)
               Z = 2;
          }
          else
             Z = 0;
          
            for(y = 0; y < row; y++)
            {
               
                switch(Z)
                {
                    case 0:
                        next_rollno(strategy);
                        seat[z][x][y] = set_rollno[Z][A];
//                        outfile << "\n\n" << seat[z][y][x] <<"\t" <<set_rollno[Z][A] <<"\t "<< Z  <<" "<<A;
                        Z++;
                        break;
                    
                    case 1:
                        next_rollno(strategy);
                        seat[z][x][y] = set_rollno[Z][B];
//                        outfile << "\n\n" << seat[z][y][x] <<"\t" <<set_rollno[Z][B] <<"\t "<< Z  <<" "<<B;
                        Z++;
                        break;
                    
                     case 2:
                        next_rollno(strategy);
                        seat[z][x][y] = set_rollno[Z][C];
//                        outfile << "\n\n" << seat[z][y][x] <<"\t" <<set_rollno[Z][C] <<"\t "<< Z  <<" "<<C;
                        Z++;
                        break;
                    
                    case 3:
                        next_rollno(strategy);
                        seat[z][x][y] = set_rollno[Z][D];
//                        outfile << "\n\n" << seat[z][y][x] <<"\t" <<set_rollno[Z][C] <<"\t "<< Z  <<" "<<C;
                        Z++;
                        break;
                }
                if(Z > (strategy-1))
                    Z = 0;

            }
        }
    }
}

string RollNo :: branch(int rno)
{
	string brnch = " ";

   if(rno == 0)
      brnch = " ";
   
   else
   {
      for(int m = 0; m < total_branches; m++)
      {
         for(int n = 0; n < total_rno[i]; n++)
         {
            if (rno == rollno[m][n])
            {
               brnch = subjectCode[m];
               break;
            }
         }
      }
   }
  
	return brnch;
}


void RollNo :: count_rollno()
{
//	for(x=0;x<t_branches;x++)
//	{
//		count[x]=0;
//	}
}

void RollNo :: show_details()
{

    outfile.open(FinalAllotment_out);
//    outfile << "Final Allocation\n";

   outfile << total_rooms << endl;
    for(i = 0; i < total_rooms; i++)
    {
    	
//    	outfile <<"\n\n=============== Room No: "<<room_no[i]<<" ===============\n\n";


//      for(x = 0; x < rows[i]; x++)
//      {
//         outfile<< "\t   " << (x+1) ;
//      }
      outfile << room_no[i] << " " << rows[i]  << " " << cols[i] << endl;

        for(x = 0; x < rows[i]; x++)
        {
//            outfile << (x+1)<< "\t";
            for(y = 0; y < cols[i]; y++)
            {
//                outfile << branch(seat[i][y][x]) << " " << seat[i][y][x]<<"\t\t";
                outfile << seat[i][y][x]<<"\t";
               
            }

            outfile <<"\n";
        }
    }
    outfile.close();
}
