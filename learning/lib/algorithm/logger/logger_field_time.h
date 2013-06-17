//
//  logger_field_time.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_field_time__
#define __algorithm__logger_field_time__

#include "logger_field.h"

class logger_field_time : public logger_field {
public:
  // %Y: year, %m: month, %d: day, %H: hour, %M: minute, %S: second
  char *m_format;
public:
  virtual const char* filter_text( const char *org );
  virtual const char* filter_text( long org );

  logger_field_time( const char *name = "time", char short_name = 'T',
                    bool enable_fixed_length = false, int fixed_length = 0,
                    const char *format = "%Y-%m-%d %H:%M:%S" );
  virtual ~logger_field_time();
  logger_field_time& operator= ( const logger_field_time &field );

  const char* get_format();
  void set_format( const char *format );
};

#endif /* defined(__algorithm__logger_field_time__) */
