// Time-stamp: <2016-03-02 16:22:45 dmendyke>
#ifndef __LINE_HH__
#define __LINE_HH__

//
// line.hh:  Defines a Wall of Battle with two ships defending
// and three ships attacking.
//


// Required header files
//-----------------------------------------------------------------------------
#include <array>  // std::array
#include <iosfwd>  // forward declaration of ostream
#include "fleet.hh"  // parsec::fleet_t
#include "combatant.hh"  // parsec::combatant_t


//-----------------------------------------------------------------------------
namespace parsec {

    // Wrapper around the line of battle
  //---------------------------------------------------------------------------
  class battle_line_t {

  public:

    battle_line_t( fleet_t& );
    virtual ~battle_line_t();

    combatant_t operator[]( int );

    friend std::ostream& operator<<( std::ostream&, const battle_line_t& );

  protected:

    void fill_line_();

  private:

    std::array< combatant_t, 0x3 > line_;
    fleet_t& fleet_;

  };  // end class battle_line_t

  std::ostream& operator<<( std::ostream&, const battle_line_t& );

};  // end project NS


#endif  // __LINE_HH__
