#include "expand-rollno.h"

class ArrangeRollNo : public ExapandRollNo
{
   protected:
      int rno[MAX_SIZE], l;
   
   public:
   
//      void arrangeInput();
      void readRollNoRow(int);
      void setRollNoRow(int);
      void sortRollNo();
      void removeRedundancy();
      void removeNonEligibleRollNo();
      void showArrangedRollNo();
      void Main();
};
