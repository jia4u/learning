//
//  logger_level.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef algorithm_logger_level_h
#define algorithm_logger_level_h


const int LOG_LEVEL_COUNT = 5;

enum log_level {
  LL_DEBUG,
  LL_INFO,
  LL_WARNING,
  LL_ERROR,
  LL_PANIC,
};

struct logger_level_info {
  int id;
  const char *name;
};

extern struct logger_level_info logger_level_info[ LOG_LEVEL_COUNT ];

#endif
