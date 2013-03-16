//
//  items.h
//  brain
//
//  Created by losor on 13-2-6.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef brain_items_h
#define brain_items_h

enum item_type {
    item_object     = 1 << 0,
    item_rule       = 1 << 1,
    item_status     = 1 << 2,
    item_fact       = 1 << 3,
    item_language   = 1 << 4,
    };
typedef enum item_type item_type;

#include "object.h"
#include "status.h"
#include "rule.h"
#include "fact.h"
#include "language.h"
#include "cluster.h"

#endif
