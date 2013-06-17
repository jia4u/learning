//
//  logger_manager.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_manager__
#define __algorithm__logger_manager__

#include <map>
#include <string>

#include "logger.h"

class logger_manager {
  std::map<std::string, logger*> m_loggers;
  static logger_manager *m_manager;

public:
  logger* get_logger( const char *name );
  long    add_logger( const char *name, class logger *logger );
  long    delete_logger( const char *name );

  static logger_manager* get_instance();
  
private:
  logger_manager() {}
};

#endif /* defined(__algorithm__logger_manager__) */
