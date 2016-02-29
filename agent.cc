// Time-stamp: <2016-02-28 22:29:31 daniel>


//
// agent.cc:  Member functions for the class parsec::agent_t
//


// Required header files
//-----------------------------------------------------------------------------
#include <string>  // std::string
#include "agent.hh"  // parsec::agent_t


// Namespace shorthand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project NS


// Constructor
//-----------------------------------------------------------------------------
agent_t::agent_t( const char* id ) : id_( id ) {
};  // end constructor


// destructor
//-----------------------------------------------------------------------------
agent_t::~agent_t( ) {
};  // end destructor


// Return the name of this agent
//-----------------------------------------------------------------------------
const string& agent_t::id() const {

  return id_;

};  // end id


// dump the name of the agent
//-----------------------------------------------------------------------------
ostream& parsec::operator<<( ostream& out, const agent_t& agent ) {

  out << agent.id_;
  return out;

};  // end operator<<
