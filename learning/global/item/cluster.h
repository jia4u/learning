//
//  cluster.h
//  learning
//
//  Created by losor on 13-2-7.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_cluster_h
#define learning_cluster_h

#include "object.h"

enum relation {
  AND_EACH,
  AND_TOGETHER,
  OR_EXIST,
  OR_ATLEAST,
  UNDEFINED,
};

class cluster : public object {
public:
  object *relation;
  object **obj;
};

#endif
