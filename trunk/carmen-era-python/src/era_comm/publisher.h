#ifndef PUBLISHER
#define PUBLISHER

#include "communications_base.h"

class Publisher : CommunicationsBase
{
public:
  virtual void send() = 0;
};

#endif /*PUBLISHER*/
