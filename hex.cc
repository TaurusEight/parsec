// Time-stamp: <2016-03-07 10:21:08 dmendyke>



//
// hex.cc:
//



// Required header files
//-----------------------------------------------------------------------------
#include <cmath>  // std::abs
#include "hex.hh"  // parsec::hex


// Namespace Short Hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project NS


// Constructor
//-----------------------------------------------------------------------------
hex_t::hex_t( int q, int r ) : q_( q ), r_( r ) {
};  // end hex_t


// Destructor
//-----------------------------------------------------------------------------
hex_t::~hex_t( ) {
};  // end destructor


// Find the distance between this hex and another hex
//-----------------------------------------------------------------------------
int hex_t::distance( const hex_t& other ) const {

  return hex_t::distance_between( *this, other );

};  // end distance


// Calculate the distance between hex A and hex B
//-----------------------------------------------------------------------------
int hex_t::distance_between( const hex_t& A, const hex_t& B ) {

  return ( abs( A.q_ - B.q_ )
           + abs( A.q_ + A.r_ - B.q_ - B.r_ )
           + abs( A.r_ - B.r_ ) ) / 2;

};  // end distance
