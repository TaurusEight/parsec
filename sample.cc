

#include <iostream>
#include <array>
#include <algorithm>
#include "chance.hh"



using namespace std;  // standard library


typedef pair< int, int > combat_t;

typedef array< combat_t, 0x3 > battle_line_t;



enum role_t { defender, attacker };



//-----------------------------------------------------------------------------
combat_t generate_combat_type( ) {

  static int count = 0x0;
  return make_pair( chance::number::single(), ++count );

};  // end


struct combat_victor_t {
  inline bool operator() ( const combat_t& one, const combat_t& two ) {
    return one.first > two.first;
  };  // end operator()
};  // end combat_victor_t


//-----------------------------------------------------------------------------
battle_line_t generate_battle_line( role_t role ) {

  static combat_t empty( make_pair( 0x0, 0x0 ) );

  battle_line_t results( {
      generate_combat_type(), generate_combat_type(),
        ( role == defender ? empty : generate_combat_type() ) } );

  sort( results.begin(), results.end(), combat_victor_t() );
  return results;

};  // end generate


//-----------------------------------------------------------------------------
void dump( const battle_line_t& bl ) {

  for( auto iter : bl ) cout << iter.first << " : " << iter.second << endl;
  cout << endl;

};  // end dump


//-----------------------------------------------------------------------------
void battle( battle_line_t& at, battle_line_t& def ) {

  if ( def[ 0 ].first >= at[ 0 ].first )
    cout << "Attacker lost one " << at[ 0 ].second << endl;
  else cout << "Defender lost one " << def[ 0 ].second << endl;

  if ( def[ 1 ].first >= at[ 1 ].first )
    cout << "Attacker lost one " << at[ 1 ].second << endl;
  else cout << "Defender lost one " << def[ 1 ].second << endl;

};  // end battle


// Entry into application
//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  battle_line_t attackers( generate_battle_line( attacker ) );
  battle_line_t defenders( generate_battle_line( defender ) );

  cout << "attacker fleet:" << endl;
  dump( attackers );

  cout << "defender fleet:" << endl;
  dump( defenders );


  battle( attackers, defenders );

};  // end main
