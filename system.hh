// Time-stamp: <2016-02-29 17:13:35 dmendyke>
#ifndef __SYSTEM_HH__
#define __SYSTEM_HH__


// Project NS
//-----------------------------------------------------------------------------
namespace parsec {


  // Define a star system
  //---------------------------------------------------------------------------
  class system_t {

  public:

    system_t();  // constructor
    virtual ~system_t();  // destructor

  protected:

    std::string name_;
    std::pair< int, int > location_;
    int tech_level_;  // what is the tech level of this system [08 - 16]
    int production_level_;  // how many ships a turn can be produced
    fleet_t fleet_;  // information about the fleet located here
    std::queue incoming_;  // list of fleets arriving and their times in turns


  };  // end class system_t


};  // end project NS



#endif  // __SYSTEM_HH__
