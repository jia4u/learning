//
//  logger_loader.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_loader__
#define __algorithm__logger_loader__

#include "xml_conf.h"
#include "logger_manager.h"

class logger_loader {
  static logger* load_logger( xml_tree *root );

public:
  static int load_loggers( xml_tree *root );
};

#endif /* defined(__algorithm__logger_loader__) */
