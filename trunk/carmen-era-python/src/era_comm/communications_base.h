#ifndef COMMUNICATIONS_BASE_H
#define COMMUNICATIONS_BASE_H

#include "era_comm.h"

class CommunicationsBase
{
public:
  CommunicationsBase();
protected:
  EraComm & _era_comm;
};

#endif /*COMMUNICATIONS_BASE_H*/
