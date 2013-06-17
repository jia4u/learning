//
//  logger.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger__
#define __algorithm__logger__

#include "logger_style.h"
#include "logger_storage.h"
#include "logger_type.h"

#include "int.h"

#include <cstdarg>

class logger {
  logger_style *m_style;
  int m_ref;

public:
  logger_style* get_conf() const;

  virtual void debug  ( const char* file, int line, const char *format, ... );
  virtual void info   ( const char* file, int line, const char *format, ... );
  virtual void warning( const char* file, int line, const char *format, ... );
  virtual void error  ( const char* file, int line, const char *format, ... );
  virtual void panic  ( const char* file, int line, const char *format, ... );

  void release();
  void add_ref();
  int get_ref() const;

public:
  logger( const char *path, logger_type type = LT_FILE );
  virtual ~logger();

protected:
  virtual void log( log_level level, const char *file, int line,
                   const char *format, va_list para);
};

#endif /* defined(__algorithm__logger__) */
