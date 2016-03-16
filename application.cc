// Time-stamp: <2016-03-15 17:13:54 dmendyke>


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



bool is_odd( int integer ) {
  bool result = ( integer % 2 ) == 1;
  return result;
};  // end is_odd


//-----------------------------------------------------------------------------
void dump_field( ) {

  string header;

  for ( int row = 0; row < 7; ++row ) {

    is_odd( row ) ? header = "   " : header = "";

    for( int line = 0; line < 5; ++line ) {



      for( int col = 0; col < 7; ++col ) {

        if ( col == 0 ) cout << header;

        switch( line ) {
        case 1: cout << "   " << name::random() << "   "; break;
        case 2: cout << "  " << "tech 12" << "  "; break;
        case 3: cout << "  " << "Prod 06" << "  "; break;
        default: cout << "        "; break;
        };  // end switch

      };  // end for line loop

      cout << endl;

    };  // end for col loop

  };  // end for row

  };  // end dump_field




// Return the application exit code
//-----------------------------------------------------------------------------
int application::run() {

  int result = 0x0;  //

  agent_t red( "Red" ), green( "Green" );

  fleet_t one( red ), two( green );

  one.attach( 20, 12 );
  two.attach( 28, 10 );

  battle_t battle( two, one );
  //  battle.run();


  dump_field();

  cout << endl;

  return result;

};  // end run
