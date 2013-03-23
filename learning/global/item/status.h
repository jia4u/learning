//
//  status.h
//  learning
//
//  Created by losor on 13-2-6.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_status_h
#define learning_status_h

#include "object.h"

class status : public object {
public:
  object *time;
  object *location;
  object *subject;
  object *action;
  object *related;
};

#endif
