// Time-stamp: <2016-03-02 16:44:34 dmendyke>
#ifndef __BATTLE_HH__
#define __BATTLE_HH__



// Required header files
//-----------------------------------------------------------------------------
#include "fleet.hh"  // parsec::fleet_t
#include "combatant.hh"  // parsec::combatant_t


// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {



  // Wrapper around a single battle between two fleets
  //---------------------------------------------------------------------------
  class battle_t {

  public:

    battle_t( fleet_t&, fleet_t& );
    virtual ~battle_t( );

    void run();  // Run the fight until one fleet is destroyed

  protected:

    void victory_( const combatant_t&, const combatant_t& );
    void engagement_( );  // fight a single combat

  private:

    fleet_t& defender_;
    fleet_t& attacker_;

  };  // end class battle_t


};  // end project NS



#endif  // __BATTLE_HH__
