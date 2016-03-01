// Time-stamp: <2016-03-01 06:25:56 daniel>


//
// fleet.cc:  Defines a fleet of ships
//


// Required header files
//-----------------------------------------------------------------------------
#include <ostream>  // std::ostream
#include "fleet.hh"  // parsec::fleet_t


// Namespace shorthands
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project NS


// Constructor
//-----------------------------------------------------------------------------
fleet_t::fleet_t( const agent_t& agent )
  : agent_( agent ), map_() {
};  // end constructor


// Copy constructor
//-----------------------------------------------------------------------------
fleet_t::fleet_t( const fleet_t& org )
  : agent_( org.agent_ ), map_( org.map_ ) {
};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
fleet_t::~fleet_t( ) {
};  // end destructor


// Add another ship to this fleet
//-----------------------------------------------------------------------------
void fleet_t::attach( ship_t& ship ) {

  map_.insert( pair< uint64_t, ship_t >( ship.id(), ship ) );

};  // end  attach


// Attach a number of new ships to this fleet
//-----------------------------------------------------------------------------
void fleet_t::attach( int count, int tech_level ) {

  ship_t ship;

  for( int iter = 0; iter < count; ++iter )
    attach( ship = ship_t( tech_level ) );

};  // end attach a number of ships


// destroy a ship attached to this fleet
//-----------------------------------------------------------------------------
void fleet_t::destroy( uint64_t id ) {

  map_.erase( id );

};  // end destroy


// Return the reference to a random ship from this fleet
//-----------------------------------------------------------------------------
ship_t fleet_t::random_ship_( ) const {

  auto iter = begin();  // first element in this fleet

  advance( iter, chance::number::upto( size() - 1 ) );
  return iter->second;

};  // end random_ship_


// Create a line of battle
//-----------------------------------------------------------------------------
vector< ship_t > line_of_battle( ) const {

  vector< ship_t > lob;

  lob.push_back( random_ship_() );
  lob.push_back( random_ship_() );
  lob.push_back( random_ship_() );

  return lob;

};  // end


// Dump the contents of this fleet
//-----------------------------------------------------------------------------
ostream& parsec::operator<<( ostream& out, const fleet_t& fleet ) {

  out << "Fleet owned by " << fleet.agent_ << endl;
  for( auto& iter : fleet.map_ )
    out << iter.second;
  out << endl;

  return out;

};  // end operator<<
