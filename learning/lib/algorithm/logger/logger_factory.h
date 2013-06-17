//
//  logger_factory.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_factory__
#define __algorithm__logger_factory__

#include "logger_manager.h"
#include "xml_conf.h"

class logger_factory {

public:
  logger* get_logger( const char *name );
  logger* get_Logger( logger_type type, const char *path );

  void load_logger_from_xml( xml_tree *root );
};

#endif /* defined(__algorithm__logger_factory__) */
