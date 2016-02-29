// Time-stamp: <2016-02-28 23:58:47 daniel>


//
// ship.cc:  Member function bodies for class 'ship_t'
//


// Required header files
//-----------------------------------------------------------------------------
#include <ostream>  // std::ostream
#include "chance.hh"  // chance::number::upto
#include "ship.hh"  // parsec::ship_t


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project NS


// Static value holding current count of all ships
//-----------------------------------------------------------------------------
uint64_t ship_t::id_counter = 0x1;


// Empty constructor
//-----------------------------------------------------------------------------
ship_t::ship_t( ) : id_( 0x0 ), techlevel_( 0x0 ) {
};  // end constructor


// Constructor
//-----------------------------------------------------------------------------
ship_t::ship_t( int tl )
  : id_( ship_t::id_counter++ ), techlevel_( tl ) {
};  // end constructor

// Copy constructor
//-----------------------------------------------------------------------------
ship_t::ship_t( const ship_t& org )
  : id_( org.id_ ), techlevel_( org.techlevel_ ) {
};  // end copy constructor

// Destructor
//-----------------------------------------------------------------------------
ship_t::~ship_t() {
};  // end destructor


// Return this ship as an ID
//-----------------------------------------------------------------------------
ship_t::operator int() const { return id_; };


// Treat this object as a function
//-----------------------------------------------------------------------------
int ship_t::operator()() const {

  int upper = 0x6 + ( techlevel_ - 10 );
  return chance::number::upto( upper ) + 1;

};  // end operator()


// Dump the ship to outstream
//-----------------------------------------------------------------------------
ostream& parsec::operator<<( ostream& out, const ship_t& ship ) {

  out << "Ship: " << ship.id()
      << " at tech level " << ship.techlevel_ << endl;

  return out;

};  // end operator<<
