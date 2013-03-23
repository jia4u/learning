//
//  rule.h
//  learning
//
//  Created by losor on 13-2-6.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_rule_h
#define learning_rule_h

#include "object.h"

class rule : public object {
public:
  object *reason;
  object *result;
};

#endif
