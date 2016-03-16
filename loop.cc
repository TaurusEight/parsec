
#include <iostream>
#include <iomanip>

using namespace std;



//-----------------------------------------------------------------------------
void cell( int r, int q ) {

  cout << "{ " << right << setw( 2 ) << r
       << "," << right << setw( 2 ) << q
       << " }";


};  // end cell


//-----------------------------------------------------------------------------
void row( int size, int offset, int R ) {

  //  if ( ( R % 2 ) != 0 ) cout << "  ";

  cout << "{ ";

  for ( int Q = 0; Q < size; ++Q ) {
    cell( Q + offset, R );
    if ( Q  < ( size - 1 ) ) cout << ", ";
  };  // for loop

  cout << " }";
  if ( R < ( size - 1 ) ) cout << "," << endl;

};  // end row


//-----------------------------------------------------------------------------
void loop() {

  int size = 10;
  int other = 0;

  cout << "{ ";
  for ( int R = 0; R < size; ++R ) {
    row( size, other, R );
    if ( ( R % 2 ) != 0 ) --other;
  };  // end loop
  cout << " }" << endl;

};  // end loop


//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  loop();
  return 0x0;

};  // end main
