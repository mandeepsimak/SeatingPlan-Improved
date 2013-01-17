#include "arrange-rollno.h"

class SubjectWiseRollNo : public ArrangeRollNo
{
   protected:
      
      int total_code, set_rollno[MIN_SIZE][MAX_SIZE], set_totalrno[MIN_SIZE],
          subject_size;
    
      string set_subcode[MIN_SIZE];
      
   public:
   
      void subjectWiseRollNo();
      void setSubCode();
      void removeRedundantSubCode();
      void showSubjectWiseRollNo();
      void Main();
};
