// Time-stamp: <2016-02-28 23:46:25 daniel>
#ifndef __FLEET_HH__
#define __FLEET_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <map>  // std::map
#include "agent.hh"  // parsec::agent_t
#include "ship.hh"  // parsec::ship_t


// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {


  // Wrapper around a fleet - uses std::map
  //---------------------------------------------------------------------------
  class fleet_t {

  public:

    fleet_t( const agent_t& );  // main constructor
    fleet_t( const fleet_t& );  // copy constructor
    virtual ~fleet_t();  // destructor

    void attach( ship_t& );  // add a ship to this fleet
    void attach( int, int );  // add a number of ships
    void destroy( uint64_t );  // destroy a ship in this fleet

    friend std::ostream& operator<<( std::ostream&, const fleet_t& );

  protected:

  private:

    const agent_t& agent_;
    std::map< uint64_t, ship_t > map_;

  };  // end class fleet_t

  // dump this fleet to the output stream
  std::ostream& operator<<( std::ostream&, const fleet_t& );

};  // end parsec - project NS

#endif  // __FLEET_HH__
