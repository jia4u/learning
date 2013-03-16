//
//  fact.h
//  brain
//
//  Created by losor on 13-2-7.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef brain_fact_h
#define brain_fact_h

#include "status.h"

struct fact {
    object supper;
    object *subject;
    status *_status;
    };
typedef struct fact fact;

#endif
