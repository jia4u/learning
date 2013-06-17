//
//  logger_style.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_style__
#define __algorithm__logger_style__

#include "logger_field.h"
#include "logger_storage.h"
#include "logger_type.h"
#include "logger_level.h"

class logger_style {

  logger_field *m_field_time;
  logger_field *m_field_thread;
  logger_field *m_field_file;
  logger_field *m_field_line;
  logger_field *m_field_level;
  logger_field *m_field_message;

  char *m_format_debug;
  char *m_format_info;
  char *m_format_warning;
  char *m_format_error;
  char *m_format_panic;
  
  logger_storage *m_storage;

public:
  logger_field* get_field( field_type type ) const;

  const char* get_format( log_level level ) const ;
  long set_format( log_level level, const char *format );

  long set_storage( logger_type type, const char *path );
  logger_storage* get_storage() const;

  logger_style( const char *storage_path, logger_type storage_type = LT_FILE );
  ~logger_style();
};

#endif /* defined(__algorithm__logger_style__) */
