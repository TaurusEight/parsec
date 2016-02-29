// Time-stamp: <2016-02-17 16:56:09 dmendyke>


// Required header files
//-----------------------------------------------------------------------------
#include "name.hh"  // gal::name


// Namespace short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace gal;  // project NS


// Return a random name
//-----------------------------------------------------------------------------
const string name::random() const {

  return name::vector[ 0 ];

};  // end random



// Static vector
//-----------------------------------------------------------------------------
vector< const char* > name::vector( {
    "aaron", "admix", "aegle", "aking", "alibi", "alula", "ameer", "amram",
      "anand", "anima", "anise", "anton", "apery", "arcus", "aston", "atoll",
      "attic", "azana", "azlon", "babur", "banat", "beach", "beard", "belle",
      "bercy", "beryl", "betty", "bingo", "biped", "blanc", "blaze", "blimp",
      "blood", "blues", "boggy", "bouak", "brawn", "brute", "bryan", "bryce",
      "bunin", "butte", "camag", "chass", "chide", "chivy", "chorz", "chuck",
      "civil", "cloot", "coder", "colet", "comal", "combo", "court", "creon",
      "dealt", "depew", "diner", "diwan", "dodds", "dolor", "doted", "dumps",
      "edley", "eridu", "ervin", "faker", "fayum", "fiver", "folie", "folum",
      "found", "freya", "fundi", "funky", "glory", "grace", "grama", "guild",
      "gumma", "hadst", "haoma", "henze", "hided", "hilly", "hurst", "iapyx",
      "idona", "inter", "izard", "janus", "japan", "jembe", "jiber", "josip",
      "joule", "jubal", "juicy", "kafre", "kanga", "kelso", "khaki", "kraut",
      "kthen", "laden", "laird", "lares", "lasse", "legal", "loral", "lysol",
      "malay", "mango", "march", "matsu", "mauro", "medal", "meryl", "meter",
      "minch", "minim", "mould", "mouth", "mower", "mrike", "mudir", "namer",
      "nawab", "nerva", "notts", "odeum", "oleta", "orpin", "osaka", "ovary",
      "papaw", "pardy", "perdu", "phyle", "piled", "plash", "plate", "ploce",
      "polio", "pondo", "poort", "poser", "possy", "potos", "provo", "pudgy",
      "pygmy", "quote", "rafer", "raser", "recto", "repad", "rindy", "river",
      "roget", "rumor", "saugh", "scale", "screw", "sekos", "senna", "senza",
      "serif", "shady", "shown", "sigyn", "snipe", "snips", "soken", "space",
      "spale", "spore", "stage", "steed", "strap", "strut", "sucks", "sunni",
      "tease", "thess", "tilth", "tinea", "tokyo", "tyrus", "upper", "verdi",
      "vowel", "whelk", "wirra", "yabby", "ysaye", "zilch", "zoril"
      } );
