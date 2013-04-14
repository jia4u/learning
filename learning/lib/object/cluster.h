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
  RELATE_AND_EACH,
  RELATE_AND_TOGETHER,
  RELATE_OR_EXIST,
  RELATE_OR_ATLEAST,
  RELATE_MUSTER,
};

class cluster : public object {
public:
  relation relation;
  object **obj;
};

#endif
