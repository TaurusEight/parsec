// Time-stamp: <2016-03-02 12:51:51 dmendyke>
#ifndef __NAME_HH__
#define __NAME_HH__


// required header files
//-----------------------------------------------------------------------------
#include <vector>  // std::vector
#include <string>  // std::string



// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {


  // Wrapper around random names
  //---------------------------------------------------------------------------
  class name {

  public:

    static const std::string  random();
    static void shuffle( );

  private:

    static std::vector< const char* > vector;

  };  // end class name


};  // end project NS


#endif  // __NAME_HH__
