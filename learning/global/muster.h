//
//  muster.h
//  learning
//
//  Created by losor on 13-2-15.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_muster_h
#define learning_muster_h

#include "items.h"

struct muster {
  object*  (*get_lastest)         ();
  cluster* (*get_near_seq)        (object*,uint64);
  cluster* (*get_near_num)        (object*,uint32);
  cluster* (*get_related)         (object*);
  cluster* (*get_supper)          (object*);
  cluster* (*get_attr_uuid)       (uint64);
  cluster* (*get_attr_ref_gt)     (uint32);
  cluster* (*get_attr_reg_lt)     (uint32);
  cluster* (*get_attr_visit_gt)   (uint32);
  cluster* (*get_attr_visit_lt)   (uint32);
  cluster* (*get_attr_creator)    (module_id);
  cluster* (*get_attr_type)       (item_type);
};

#endif
