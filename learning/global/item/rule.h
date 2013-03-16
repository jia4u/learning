//
//  rule.h
//  brain
//
//  Created by losor on 13-2-6.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef brain_rule_h
#define brain_rule_h

#include "object.h"

struct rule {
    object supper;
    object *predicate;
    object *subject;
    object *_object;
    };
typedef struct rule rule;

#endif
