// Time-stamp: <2016-03-07 10:21:45 dmendyke>
#ifndef __HEX_HH__
#define __HEX_HH__



// Project Namespace
//-----------------------------------------------------------------------------
namespace parsec {


  // Wrapper around a single hex
  //---------------------------------------------------------------------------
  class hex_t {

  public:

    hex_t( int = 0, int = 0 );
    virtual ~hex_t();

    int distance( const hex_t& ) const;

  protected:


  private:

    int q_;  // the 'x' axial
    int r_;  // the 'y' axial


    friend int distance_between( const hex_t&, const hex_t& );
    static int distance_between( const hex_t&, const hex_t& );

  };  // end hex_t


};  // end project NS parsec


#endif  // __HEX_HH__
