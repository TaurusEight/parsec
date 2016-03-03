// Time-stamp: <2016-03-01 17:03:08 dmendyke>
#ifndef __COMBATANT_HH__
#define __COMBATANT_HH__


// Required header files
//-----------------------------------------------------------------------------
#include "ship.hh"  // parsec::ship_t


// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {

  // Stats for a single ship in combat
  //---------------------------------------------------------------------------
  struct combatant_t {

    combatant_t( int = 0x0, uint64_t = 0x0 );
    combatant_t( const ship_t& );
    //    static bool operator()( const combatant_t&, const combatant_t& );

    int attack;
    uint64_t id;

  };  // end

};  // end project NS



#endif  // __COMBATANT_HH__
