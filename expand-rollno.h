#include "read-input.h"

class ExapandRollNo : public ReadInput
{
   protected:
      int roll_no[MIN_SIZE][MAX_SIZE], roll_size[MIN_SIZE];
      
   public:
      void expandInput();
      void addSeperator();
      void expandRollNo();//string);
      template<typename OutIter>
      bool expandRollNumberList(istream& is, OutIter out);
      void removeZero();
      void showExpandRollNo();
      void Main();
};
