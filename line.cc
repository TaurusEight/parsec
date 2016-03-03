// Time-stamp: <2016-03-02 16:23:59 dmendyke>


//
// line.cc:  Define the functions associated with the class
//


// Required header files
//-----------------------------------------------------------------------------
#include <algorithm>  // std::sort
#include <iostream>  // ostream
#include "line.hh"  // parsec::battle_line_t


// Namespace short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard libary
using namespace parsec;  // project NS


// Constructor
//-----------------------------------------------------------------------------
battle_line_t::battle_line_t( fleet_t& fleet )
  : line_( ), fleet_( fleet ) {

  fleet_.shuffle();
  fill_line_();

};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
battle_line_t::~battle_line_t( ) {
};  // end destructor


// Return value at index
//-----------------------------------------------------------------------------
combatant_t battle_line_t::operator[]( int index ) {

  return line_[ index ];

};  // end operator[]



// Select ships for the line of battle
//-----------------------------------------------------------------------------
void battle_line_t::fill_line_() {

  auto func = []( const combatant_t& A, const combatant_t& B ) {
    return A.attack > B.attack;
  };


  line_[ 0 ] = combatant_t( fleet_[ 0 ] );
  line_[ 1 ] = combatant_t( fleet_[ 1 ] );
  line_[ 2 ] = combatant_t( fleet_[ 2 ] );


  sort( line_.begin(), line_.end(), func );

};  // end file_line_



// Dump the content of this line to the output stream
//-----------------------------------------------------------------------------
ostream& parsec::operator<<( ostream& out, const battle_line_t& line ) {

  for( auto iter : line.line_ ) out << iter.attack << "-" << iter.id << " ";
  return out;

};  // end operator<<
