#include "strategy.h"

Strategy :: Strategy()
{
    total_seats = total_students = total_group_seats = 0;
}

void Strategy :: totalSeats(int strategy)
{
    for(i = 0; i < total_centres; i++)
    {
        for(j = 0; j < total_rooms[i]; j++)
        {
            room_size[i][j] = rows[i][j] * cols[i][j];
            total_seats += room_size[i][j];
            total_group_seats += room_size[i][j] / strategy;
        }
    }
}

void Strategy :: totalStudents()
{
    for(i = 0; i < total_code; i++)
    {
        total_students += sub_totalrno[i];
    }
}

void Strategy :: checkValidation(int strategy)
{
    totalSeats(strategy);
    totalStudents();
    
    cout << "\n\t Total Seats = " << total_seats << endl
         << "\t Total Students = " << total_students << endl
         << "\t Total Group Seats = " << total_group_seats;
    
    if(total_seats < total_students)
        cout << "\t Add More rooms!" << endl;
    else
        cout << "\n \t Condition Valid" << endl;
}
        
void Strategy :: chooseStrategy()
{
    do
    {
        system("clear");
    
        cout<<"Select Strategy and enter your choice"<<endl
            <<"\n1. Group of classes"<<endl
            <<"\tA\tA\tA\t"<<endl
            <<"\tA\tA\tA\t"<<endl
            <<"\n2. Group of classes"<<endl
            <<"\tA\tB\tA\t"<<endl
            <<"\tB\tA\tB\t"<<endl
            <<"\n3. Group of classes"<<endl
            <<"\tA\tC\tA\t"<<endl
            <<"\tB\tA\tB\t"<<endl
            <<"\tC\tB\tC\t"<<endl
            <<"\n4. Group of classes"<<endl
            <<"\tA\tC\tA\t"<<endl
            <<"\tB\tD\tB\t"<<endl
            <<"\tC\tA\tC\t"<<endl
            <<"\tD\tB\tD\t"<<endl
            <<"\nEnter your choice:\n";
        
        cin >> strategy_choice;
        switch(strategy_choice)
        {
            case 1:
                checkValidation(strategy_choice);
                break;
            case 2:
                checkValidation(strategy_choice);
                break;
            case 3:
                checkValidation(strategy_choice);
                break;
            case 4:
                checkValidation(strategy_choice);
                break;
            /*	case 2:
                checkValidation(strategyChoice);
                break;
            */
            default:
                cout<<"Oops!!! Wrong choice\n Enter your choice Again\n";
        }

    }while(strategy_choice < 1 || strategy_choice > 4);
}

void Strategy :: Main()
{
    SubjectWiseRollNo :: Main();
    chooseStrategy();
}
