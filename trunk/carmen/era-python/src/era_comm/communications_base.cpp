#include "communications_base.h"

//------------------------------------------------------------------------------

CommunicationsBase::CommunicationsBase()
  : _era_comm( EraComm::instance() )
{
}
