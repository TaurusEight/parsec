// Time-stamp: <2016-02-29 13:53:37 dmendyke>


//
// application.cc: Main object of this program
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout, std::endl;
#include "application.hh"  // parsec::application
#include "fleet.hh"  // parsec::fleet_t
#include "name.hh"  // parsec::name


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project namespace


// Constructor
//-----------------------------------------------------------------------------
application::application() {

  for ( int iter = 0; iter < 20; ++iter )
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

  one.attach( 3, 12 );

  two.attach( 4, 10 );

  cout << endl << one << endl << two << endl;

  return result;

};  // end run
