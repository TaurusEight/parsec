// Time-stamp: <2016-01-27 11:41:51 dmendyke>


//
// chance.cc:
//


// Required header files
//-----------------------------------------------------------------------------
#include <chrono>  // std::chrono
#include "chance.hh"  // chance::number


// NS short hands
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace chance;  // NS used with this random genrator


// class constructor
//-----------------------------------------------------------------------------
number::number() : generator_( ) {

  unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
  generator_.seed( seed );

};  // end constructor


// Roll a single die
//-----------------------------------------------------------------------------
int number::generate( int high ) {

  static number number_;
  uniform_int_distribution<> distribution( 0, high );
  return distribution( number_.generator_ );

};  // end generate


// Return a single die roll
//-----------------------------------------------------------------------------
int number::single( int modifier ) {

  return number::generate() + 1 + modifier;

};  // end one2six


// Return roll of two dice
//-----------------------------------------------------------------------------
int number::pair( int modifier ) {

  return number::single() + number::single( modifier );

};  // end two2twelve


// Return a random number from zero to 'high'
//-----------------------------------------------------------------------------
int number::upto( int high ) {

  return number::generate( high );

};  // end upto
