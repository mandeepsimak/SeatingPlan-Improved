#include "strategy.h"

void Strategy :: Strategy()
{
   total_seats = total_students = group_seats = 0;
   min = 3265;
	max = 0;
}

void Strategy :: chooseStrategy()
{
   do
	{
	   system("clear");

		cout<<"Select Strategy and enter your choice"<<endl
			<<"1. Group of classes"<<endl
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

		cin >> choice;
		
		switch(choice)
		{
			case 1:
				checkStrategyConditions(choice);
				break;
				
			case 2:
				checkStrategyConditions(choice);
				break;
				
			case 3:
				checkStrategyConditions(choice);
				break;
				
			case 4:
				checkStrategyConditions(choice);
				break;
				
			default:
			cout<<"Oops!!! Wrong choice\n Enter your choice Again\n";

		}

	}while(choice < 1 || choice > 4);
}

void Strategy :: checkStrategyConditions(int choice)
{
	groups = choice;
	int selection, sum = 0;
	if(total_branches < groups)
	{
		cout << "\n\nSorry!\nStrategy not possible because this strategy requires minimum " 
		     << groups << " classes\n";
	}
	else
	{
		group_seats = total_seats / groups;
		cout << "\ngroup seats= " << group_seats;
				group_students = maxStudent(groups);
				if( group_students > group_seats)
				{
//					do
//					{					
//						cout <<"\n\n\nstrategy is not possible bcz of less rooms\n";
//						cout << "Would you like follow:\n1.\tStrict strategy \n2." 
//							<<"\tStudents at consecutive places of same subject\n Enter choice";
//						cin >> selection;
//					}while(selection !=1 && selection !=2);

//						if(selection == 1)
//						{
//						outFile << groupStudents - groupSeats <<" More seats are required\n";
//						cout << groupStudents - groupSeats <<" More seats are required\n";
//						float	extraRooms=(float) (groupStudents - groupSeats) / (32/groups);
//						int extroom = extraRooms + 0.5;
//						cout <<"\n Add  " << extroom << " more room to follow this stretegy.\n"; //<<" Rooms of 8 * 4 to follow this strategy where"
////								<<" 8 is rows and 4 is columns\n\n";
//						}

//						if(selection == 2)
//						{

//							for( i=0; i<groups; i++)
//							{
//								sum += groupArray[i];
//							}
//							if( roomsCapacity() >= sum)
//							{
//								cout << "\nTotal Students: " << sum;
//								cout << "\ncongratulations!!! you can get results now.";


//								RNO.get_details();
//    							RNO.seat_alot(strategyChoice);
//   							RNO.show_details();

//							}
//							else
//							{
//								cout<<"\nSorry :-( \nYou need to enter more rooms to follow this strategy";
//							}
//						}


				}
				else
				{

					RNO.get_details();
    				RNO.seat_alot(strategyChoice);
   					RNO.show_details();
   					
   					   					
   				cout << "\n Sitting Plan is done.\n \n Check '" << FinalAllotment_out << "' file.\n\n" << endl;
   				

				}


			}
}

int Strategy :: maxStudent(int groups)
{
   
	for(i = 0; i < groups; i++)
	{
		group_array[i] = set_totalrno[i];
		if(group_array[i] < min)
		{
			min = group_array[i];
			min_pos = i;	
		}	
		if(group_array[i] > max)
			max = group_array[i];			
	}

	for(i = groups; i<total_branches; i++)
	{
		group_array[min_pos] += set_totalrno[i];
		min = max;
		for(j=0; j < groups; j++)
		{
			if(group_array[j] <= min)
			{
				min = group_array[j];
				min_pos = j;
			}
			if(group_array[j] > max)
				max = group_array[j];
		}
	}

	cout <<"\n Min group students = " << min <<"\tMax group students =" << max;
	return(max);
}

void Strategy :: totalStudents()
{
   for(i = 0; i < total_branches; i++)
   {
      total_students += set_totalrno[i];
   }
}

void Strategy :: totalSeats()
{
   for(i = 0; i < total_rooms; i++)
   {
      total_seats += ( rows[i] * cols[i] );
   }
}

void Strategy :: Main()
{
   SubjectWiseRollNo :: Main();
   totalSeats();
   totalStudents();
   chooseStrategy();
}
