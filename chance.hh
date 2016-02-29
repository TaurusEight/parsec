// Time-stamp: <2016-01-27 08:41:32 dmendyke>
#ifndef __CHANCE_HH__
#define __CHANCE_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <random>  // std::mt19937


// NS used with this class
//-----------------------------------------------------------------------------
namespace chance {


  // Wrapper around generating random numbers
  class number {

  public:

    number();  // constructor

    static int single( int = 0x0 );  // random 1 - 6
    static int pair( int = 0x0 );  // random 2 - 12
    static int upto( int );  // random upto parameters

  protected:

  private:

    std::mt19937 generator_;  // random generator

    static int generate( int = 0x5 );  // generate a random number

  };  // end class number


};  // end NS chance



#endif  // __CHANCE_HH__
