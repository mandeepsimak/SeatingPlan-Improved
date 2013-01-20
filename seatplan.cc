#include "seatplan.h"

void SeatPlan :: setRollNo(int strategy)
{
    s = 0;
    for(i = 0; i < strategy; i++)
    {
        seat_size[i] = 0;
    }
    
    for(i = 0; i < total_code; i++)
    {
        if(s == strategy)
            s = 0;
        
        start = seat_size[s];
        index = index_value[i];
        end = sub_totalrno[index];
        
        for(j = 0; j < end; j++)
        {
            seat_rollno[s][start + j] = sub_rollno[i][j];
        }
        
        seat_size[s] += end;
        s++;
    }
    
    for( i = 0; i < strategy; i++)
    {
        for(j = 0; j < seat_size[i]; j++)
        {
            cout << seat_rollno[i][j] << "\t";
        }
        cout << endl;
    }
}

void SeatPlan :: seatingPlan(int strategy)
{
    setRollNo(strategy);
    
    // centre = total centre, room = total room[], row = rows[][], col = cols[][]
    
    
}
