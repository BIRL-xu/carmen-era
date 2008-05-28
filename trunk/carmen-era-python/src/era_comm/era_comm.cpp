#include "era_comm.h"
#include <era_interface.h>

using namespace std;

EraComm * EraComm::_instance = NULL;

//------------------------------------------------------------------------------
// Public Methods
//------------------------------------------------------------------------------

EraComm::~EraComm()
{
  carmen_ipc_disconnect();
}

//------------------------------------------------------------------------------

EraComm &
EraComm::instance()
{
  if ( ! _instance )
    _instance = new EraComm();
  return *_instance;
}

//------------------------------------------------------------------------------

double
EraComm::time()
{
  return carmen_get_time();
}

//------------------------------------------------------------------------------

const char *
EraComm::host()
{
  return carmen_get_host();
}

//------------------------------------------------------------------------------

void
EraComm::listen( double seconds ) {
  IPC_listenClear( static_cast<int>( seconds * 1000 ) );
}

//------------------------------------------------------------------------------
// Private Methods
//------------------------------------------------------------------------------

EraComm::EraComm()
{
  char * arg = "era_comm";
  carmen_ipc_initialize( 1, &arg );
}
