// Time-stamp: <2016-03-01 15:55:27 dmendyke>
#ifndef __SHIP_HH__
#define __SHIP_HH__


// Required headers
//-----------------------------------------------------------------------------
#include <cstdint>  // uint64_t
#include <iosfwd>  // std::ostream


// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {


  // Wrapper around a single ship
  //---------------------------------------------------------------------------
  class ship_t {

  public:

    explicit ship_t( );  // not to be called by compiler
    ship_t( int );  // main constructor
    ship_t( const ship_t& );  // copy constructor
    virtual ~ship_t();

    int operator()() const;  // return the attack value for this ship
    operator int() const;  // return the id of this ship

    bool operator==( const ship_t& ) const;
    bool operator!=( const ship_t& ) const;

    int id() const { return id_; };

    friend std::ostream& operator<<( std::ostream&, const ship_t& );

  protected:

  private:

    uint64_t id_;  // unique ID of this ship
    int techlevel_;  // tech level of this

    static uint64_t id_counter;

  };  // end class ship_t


  // Dump this ship to the ostream
  std::ostream& operator<<( std::ostream&, const ship_t& );


};  // end project NS


#endif  // __SHIP_HH__
