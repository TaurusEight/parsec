// Time-stamp: <2016-03-02 15:03:31 dmendyke>
#ifndef __CHANCE_HH__
#define __CHANCE_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <random>  // std::mt19937
#include <algorithm>  // std::shuffle

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

    template< typename I >
    static void shuffle( I begin, I end ) {
      std::random_device random_device;
      std::mt19937 engine( random_device() );
      std::shuffle( begin, end, engine );
    };  // end shuffle

  protected:

  private:

    std::mt19937 generator_;  // random generator

    static int generate( int = 0x5 );  // generate a random number

  };  // end class number


};  // end NS chance



#endif  // __CHANCE_HH__
