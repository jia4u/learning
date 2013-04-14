//
//  fact.h
//  learning
//
//  Created by losor on 13-2-7.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_fact_h
#define learning_fact_h

#include "cluster.h"

class fact : public object {
public:
  object *pred;
  cluster **obj;
};

#endif
