// Time-stamp: <2016-03-03 09:26:28 dmendyke>
#ifndef __FLEET_HH__
#define __FLEET_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <vector>  // std::map
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

    auto begin() { return vector_.begin(); };
    auto end() { return vector_.end(); };
    auto empty() { return vector_.empty(); };
    auto size() { return vector_.size(); };

    void shuffle();

    const agent_t& agent() const { return agent_; };

    const ship_t& operator[]( int ) const;
    friend std::ostream& operator<<( std::ostream&, const fleet_t& );

  protected:

  private:

    const agent_t& agent_;
    std::vector< ship_t > vector_;

  };  // end class fleet_t

  // dump this fleet to the output stream
  std::ostream& operator<<( std::ostream&, const fleet_t& );


};  // end parsec - project NS

#endif  // __FLEET_HH__
