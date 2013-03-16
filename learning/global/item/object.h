//
//  object.h
//  brain
//
//  Created by losor on 13-2-6.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef brain_object_h
#define brain_object_h

#include "int.h"
#include "module.h"
#include "items.h"

struct object {
    uint64 uuid;
    uint32 nref;
    uint32 nvisit;
    module_id creator;
    item_type type;
    };
typedef struct object object;

#endif
