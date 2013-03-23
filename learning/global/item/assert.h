//
//  predicate.h
//  learning
//
//  Created by xiangyun.kongxy on 3/23/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_predicate_h
#define learning_predicate_h

#include "object.h"
#include "instruction.h"

class assert : public object {
public:
  instruction *opt;
  object **obj;
};

#endif
