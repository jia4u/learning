//
//  instruction_inter.h
//  learning
//
//  Created by losor on 3/17/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_instruction_h
#define learning_instruction_h

#include "items.h"

class instruction : public object {
public:
  virtual object* execute() = 0;

};

#endif
