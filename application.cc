// Time-stamp: <2016-03-02 12:53:35 dmendyke>


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


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project namespace


// Constructor
//-----------------------------------------------------------------------------
application::application() {

  name::shuffle();  // randomize the names

  for ( int iter = 0; iter < 5; ++iter )
    cout << name::random() << endl;


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

  one.attach( 10, 12 );

  two.attach( 16, 10 );

  battle_t battle( two, one );
  battle.run();

  return result;

};  // end run
