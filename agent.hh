// Time-stamp: <2016-02-28 22:27:27 daniel>
#ifndef __AGENT_HH__
#define __AGENT_HH__



//
// agent.hh:  This class defines the value associated with a player
//


// Required header files
//-----------------------------------------------------------------------------
#include <string>  // std::string
#include <iosfwd>  // forward decloration of ostream


// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {


  // Wrapper around a player
  //---------------------------------------------------------------------------
  class agent_t {

  public:

    agent_t( const char* );
    virtual ~agent_t();

    const std::string& id() const;

    friend std::ostream& operator<<( std::ostream&, const agent_t& );

  protected:

  private:

    std::string id_;

  };  // end class agent_t

  std::ostream& operator<<( std::ostream&, const agent_t& );

};  // end project NS


#endif   // _AGENT_HH__
