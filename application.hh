// Time-stamp: <2016-02-28 22:51:39 daniel>
#ifndef __APPLICATION_HH__
#define __APPLICATION_HH__


// Project namespace
//-----------------------------------------------------------------------------
namespace parsec {


  // Wrapper around main object
  //---------------------------------------------------------------------------
  class application {

  public:

    application();
    virtual ~application();

    int run();  // entry into this object

  protected:

  private:


  };  // end class application


};  // end project namespace


#endif  // __APPLICATION_HH__
