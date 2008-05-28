#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "communications_base.h"

class Subscriber : CommunicationsBase
{
public:
  virtual bool changed() = 0;
};

#endif /*SUBSCRIBER_H*/
