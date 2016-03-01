// Time-stamp: <2016-02-29 14:43:33 dmendyke>


// Required header files
//-----------------------------------------------------------------------------
#include "name.hh"  // parsec::name
#include "chance.hh"  // chance::number

// Namespace short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace parsec;  // project NS


// Return a random name
//-----------------------------------------------------------------------------
const string name::random() {

  int size = name::vector.size() - 1;
  return string( name::vector[ chance::number::upto( size ) ] );

};  // end random



// Static vector
//-----------------------------------------------------------------------------
vector< const char* > name::vector( {
    "Aaron", "Admix", "Aegle", "Aking", "Alibi", "Alula", "Ameer", "Amram",
      "Anand", "Anima", "Anise", "Anton", "Apery", "Arcus", "Aston", "Atoll",
      "Attic", "Azana", "Azlon", "Babur", "Banat", "Beach", "Beard", "Belle",
      "Bercy", "Beryl", "Betty", "Bingo", "Biped", "Blanc", "Blaze", "Blimp",
      "Blood", "Blues", "Boggy", "Bouak", "Brawn", "Brute", "Bryan", "Bryce",
      "Bunin", "Butte", "Camag", "Chass", "Chide", "Chivy", "Chorz", "Chuck",
      "Civil", "Cloot", "Coder", "Colet", "Comal", "Combo", "Court", "Creon",
      "Dealt", "Depew", "Diner", "Diwan", "Dodds", "Dolor", "Doted", "Dumps",
      "Edley", "Eridu", "Ervin", "Faker", "Fayum", "Fiver", "Folie", "Folum",
      "Found", "Freya", "Fundi", "Funky", "Glory", "Grace", "Grama", "Guild",
      "Gumma", "Hadst", "Haoma", "Henze", "Hided", "Hilly", "Hurst", "Iapyx",
      "Idona", "Inter", "Izard", "Janus", "Japan", "Jembe", "Jiber", "Josip",
      "Joule", "Jubal", "Juicy", "Kafre", "Kanga", "Kelso", "Khaki", "Kraut",
      "Kthen", "Laden", "Laird", "Lares", "Lasse", "Legal", "Loral", "Lysol",
      "Malay", "Mango", "March", "Matsu", "Mauro", "Medal", "Meryl", "Meter",
      "Minch", "Minim", "Mould", "Mouth", "Mower", "Mrike", "Mudir", "Mamer",
      "Nawab", "Nerva", "Notts", "Odeum", "Oleta", "Orpin", "Osaka", "Ovary",
      "Papaw", "Pardy", "Perdu", "Phyle", "Piled", "Plash", "Plate", "Ploce",
      "Polio", "Pondo", "Poort", "Poser", "Possy", "Potos", "Provo", "Pudgy",
      "Pygmy", "Quote", "Rafer", "Raser", "Recto", "Repad", "Rindy", "River",
      "Roget", "Rumor", "Saugh", "Scale", "Screw", "Sekos", "Senna", "Senza",
      "Serif", "Shady", "Shown", "Sigyn", "Snipe", "Snips", "Soken", "Space",
      "Spale", "Spore", "Stage", "Steed", "Strap", "Strut", "Styks", "Sunni",
      "Tease", "Thess", "Tilth", "Tinea", "Tokyo", "Tyrus", "Upper", "Verdi",
      "Vowel", "Whelk", "Wirra", "Yabby", "Ysaye", "Zilch", "Zoril"
      } );
