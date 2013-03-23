//
//  instruction_inter.h
//  learning
//
//  Created by losor on 3/17/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_instruction_h
#define learning_instruction_h

#include "object.h"
#include "code.h"
#include "addressing.h"

class instruction {
  code m_code;
  addressing m_address;

public:
  long check( object** );
};

#endif
