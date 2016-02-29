// Time-stamp: <2016-02-29 02:05:00 daniel>


//
// application.cc: Main object of this program
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout, std::endl;
#include "application.hh"  // parsec::application
#include "fleet.hh"  // parsec::fleet_t


// NS short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project namespace


// Constructor
//-----------------------------------------------------------------------------
application::application() {

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



// Run a single battle between two fleets
//-----------------------------------------------------------------------------
void application::single_fleet_battle( fleet_t& defensive, fleet_t& agressive ) {

  auto defenders = defensive.defenders();
  auto attackers = agressive.attackers();

  if ( defenders[ 0 ].first > attackers[ 0 ].first ) agressive.destroy( attackers[ 0 ].second );
  else defensive.destroy( defenders[ 0 ].second );

  if ( defenders[ 1 ].first > attackers[ 1 ].first ) agressive.destroy( attackers[ 1 ].second );
  else defensive.destroy( defenders[ 1 ].second );

};  // end single_fleet_battle



// Two fleets will battle
//-----------------------------------------------------------------------------
void application::fleet_battle( fleet_t& defensive, fleet_t& agressive ) {

  while( ( defensive.empty() == false ) && ( agressive.empty() == false ) )
    single_fleet_battle( defensive, agressive );

};  // end fleet_battle
