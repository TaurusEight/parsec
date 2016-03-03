// Time-stamp: <2016-03-02 16:45:45 dmendyke>


//
// fleet.cc:  Defines a fleet of ships
//


// Required header files
//-----------------------------------------------------------------------------
#include <ostream>  // std::ostream
#include "fleet.hh"  // parsec::fleet_t
#include "chance.hh"  // chance::number::upto


// Namespace shorthands
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project NS


// Constructor
//-----------------------------------------------------------------------------
fleet_t::fleet_t( const agent_t& agent )
  : agent_( agent ), vector_() {
};  // end constructor


// Copy constructor
//-----------------------------------------------------------------------------
fleet_t::fleet_t( const fleet_t& org )
  : agent_( org.agent_ ), vector_( org.vector_ ) {
};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
fleet_t::~fleet_t( ) {
};  // end destructor


// Add another ship to this fleet
//-----------------------------------------------------------------------------
void fleet_t::attach( ship_t& ship ) {

  vector_.push_back( ship );

};  // end  attach


// Attach a number of new ships to this fleet
//-----------------------------------------------------------------------------
void fleet_t::attach( int count, int tech_level ) {

  for ( int iter = 0; iter < count; ++iter )
    vector_.push_back( ship_t( tech_level ) );

};  // end attach a number of ships


// destroy a ship attached to this fleet
//-----------------------------------------------------------------------------
void fleet_t::destroy( uint64_t id ) {

  auto func = [ id ]( const ship_t& S ){ return S.id() == id; };
  auto iter = find_if( vector_.begin(), vector_.end(), func );

  if ( iter == vector_.end() )
    throw runtime_error( "Requesting ship not in this fleet!" );

  vector_.erase( iter );  // remove this ship

};  // end destroy


// Randomize the ships in this fleet
//-----------------------------------------------------------------------------
void fleet_t::shuffle( ) {

  chance::number::shuffle( vector_.begin(), vector_.end() );

 };  // end shuffle


//-----------------------------------------------------------------------------
const ship_t& fleet_t::operator[]( int index ) const {

  static ship_t empty;

  if ( index >= vector_.size() ) return empty;
  return vector_[ index ];

};  // end operator[]


// Dump the contents of this fleet
//-----------------------------------------------------------------------------
ostream& parsec::operator<<( ostream& out, const fleet_t& fleet ) {

  out << fleet.agent_ << ": " << fleet.vector_.size() << " ships";
  return out;

};  // end operator<<
