//
//  logger_level.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 6/2/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_level.h"

struct logger_level_info logger_level_info[ LOG_LEVEL_COUNT ] = {
  { LL_DEBUG,   "debug"    },
  { LL_INFO,    "info"     },
  { LL_WARNING, "warning"  },
  { LL_ERROR,   "error"    },
  { LL_PANIC,   "panic"    },
};
