// Time-stamp: <2016-03-07 10:22:53 dmendyke>


//
// application.cc: Main object of this program
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout, std::endl;
#include "application.hh"  // parsec::application
#include "fleet.hh"  // parsec::fleet_t
#include "line.hh"  // parsec::battle_line_t
#include "name.hh"  // parsec::name
#include "battle.hh"  // parsec::battle_t
#include "hex.hh"  // parsec::hex_t


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project namespace


// Constructor
//-----------------------------------------------------------------------------
application::application() {

  name::shuffle();  // randomize the names


};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
application::~application() {
};  // end destructor


// Return the application exit code
//-----------------------------------------------------------------------------
int application::run() {

  int result = 0x0;  //

  agent_t red( "Red" ), green( "Green" );

  fleet_t one( red ), two( green );

  one.attach( 20, 12 );

  two.attach( 28, 10 );

  battle_t battle( two, one );
  battle.run();

  hex_t A( 0, -3 ), B( -3, 3 );
  cout << endl << "Distance: " << A.distance( B ) << endl;


  return result;

};  // end run
