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
#include "code.h"
#include "addressing.h"

class instruction : public object {
public:
  code opt;
  
  /// opd[*], they are real instances, not references
  addressing *opd;
};

#endif
