//
//  cluster.h
//  brain
//
//  Created by losor on 13-2-7.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef brain_cluster_h
#define brain_cluster_h

#include "object.h"

struct cluster {
    object supper;
    object *relation;
    object **objects;
    };
typedef struct cluster cluster;

#endif
