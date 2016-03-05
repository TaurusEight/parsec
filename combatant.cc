// Time-stamp: <2016-03-03 09:24:01 dmendyke>


// Required header files
//-----------------------------------------------------------------------------
#include "combatant.hh"  // parsec::combatant_t



// NS short hand
//-----------------------------------------------------------------------------
using namespace parsec;


// Constructor
//-----------------------------------------------------------------------------
combatant_t::combatant_t( int ship_attack, uint64_t ship_id )
  : attack( ship_attack ), id( ship_id ) {

};  // end combatant_t constructor


// Other constructor
//-----------------------------------------------------------------------------
combatant_t::combatant_t( const ship_t& ship )
  : combatant_t( 0x0, ship.id() ) {

  if ( id != 0x0 ) attack = ship();

};  // end other constructor


// Compare two combatant attack values
//-----------------------------------------------------------------------------
//combatant_t::operator()( const combatant_t& def, const combatant_t& att ) {
//  return def.attack > att.attack;
//};  // end operator()
