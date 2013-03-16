//
//  status.h
//  brain
//
//  Created by losor on 13-2-6.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef brain_status_h
#define brain_status_h

#include "object.h"

struct status {
    object supper;
    object *action;
    object *_object;
    };
typedef struct status status;

#endif
