#include "expand-rollno.h"

class ArrangeRollNo : public ExapandRollNo
{
   protected:
      int rno[MAX_SIZE], l, m;
   
   public:
   
//      void arrangeInput();
      void readRollNoRow(int, int);
      void setRollNoRow(int, int);
      void sortRollNo();
      void removeRedundancy();
      void removeNonEligibleRollNo();
      void showArrangedRollNo();
      void Main();
};
