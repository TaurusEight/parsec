// Time-stamp: <2016-03-16 15:27:27 dmendyke>
#ifndef __UNIVERSE_HH__
#define __UNIVERSE_HH__


//
// universe.hh:
//


// Required Header Files
//-----------------------------------------------------------------------------
#include <array>  // std::array
#include "metric/point.hh"  // metric::point


// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {


  // Wrapper around the actual battle field of the game
  //---------------------------------------------------------------------------
  class universe {

  public:

    universe();
    virtual ~universe();

    void create_( int, int );


  protected:

  private:

    static const int MAX_SIZE = 10;
    static const metric::point index[ MAX_SIZE ][ MAX_SIZE ];

  };  // end class universe



};  // end NS parsec


#endif  // __UNIVERSE_HH__
