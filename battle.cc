// Time-stamp: <2016-03-03 09:32:11 dmendyke>


//
// battle.cc:  Define functions for running a battle
// between two fleets
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout, std::endl
#include "battle.hh"  // parsec::battle_t
#include "line.hh"  // parsec::battle_line_t


// Namespace short-hand
//-----------------------------------------------------------------------------
using namespace std;
using namespace parsec;


// Constructor
//-----------------------------------------------------------------------------
battle_t::battle_t( fleet_t& D, fleet_t& A )
  : defender_( D ), attacker_( A ) {

};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
battle_t::~battle_t() {
};  // end destructor


// Determine the outcome of a single ship to ship fight
//-----------------------------------------------------------------------------
void battle_t::victory_( const combatant_t& def, const combatant_t& agg ) {

  if ( ( def.attack == 0 ) || ( agg.attack == 0 ) ) return;

  if ( def.attack < agg.attack ) {
    defender_.destroy( def.id );
    //    cout << "defender ship " << def.id << " destroyed" << endl;
  } else {
    attacker_.destroy( agg.id );
    //    cout << "aggressor ship " << agg.id << " destroyed" << endl;
  };  // end / else

};  // end victory_


// Run a combat between two lines of battle
//-----------------------------------------------------------------------------
void battle_t::engagement_() {

  battle_line_t defense( defender_ );
  battle_line_t aggressor( attacker_ );

  cout << "defense: " << defense << "/ "
       << "aggressor: " << aggressor << endl;

  victory_( defense[ 0 ], aggressor[ 0 ] );
  victory_( defense[ 1 ], aggressor[ 1 ] );

};  // end engagement_



// Run the battle until one fleet is completely destroyed
//-----------------------------------------------------------------------------
void battle_t::run( ) {

  cout << "Battle Starts!" << endl
       << endl << defender_ << " - " << attacker_ << endl;

  while ( ( defender_.empty() == false ) && ( attacker_.empty() == false ) ) {
    engagement_();
    cout << endl << defender_ << " - " << attacker_ << endl;
  };  // end while loop

  cout << endl;

  if ( defender_.empty() )
    cout << "Victor for the invading fleet!  " << attacker_.agent().id()
         << " wins and has " << attacker_.size() << " ships!" << endl;
  else cout << "Defense holds firm!  " << defender_.agent().id()
            << " wins and has "  << defender_.size()
            << " ships left!" << endl;

};  // end run
