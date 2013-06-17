//
//  logger_field.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_field__
#define __algorithm__logger_field__

class logger_field {
protected:
  char *m_name;
  char m_short_name;
  bool m_enable_fixed_length;
  int  m_fixed_length;

protected:
  char *m_cpy_buf;
  
public:
  virtual const char* filter_text( const char *org ) = 0;
  virtual const char* filter_text( long org ) = 0;

  logger_field( const char *name, char short_name,
               bool enable_fixed_length, int fixed_length );
  virtual ~logger_field();
  logger_field& operator= ( const logger_field &field );

  virtual const char* get_name() const;
  virtual char get_short_name() const;
  virtual bool is_fixed_length() const;
  virtual void enable_fixed_length();
  virtual void disable_fixed_length();
  virtual int  get_fixed_length() const;
  virtual void set_fixed_length( int len );

protected:
  const char* apply_fixed_length( const char *org );
  
};

const int LOG_FIELD_COUNT = 6;

enum field_type {
  FT_TIME,
  FT_THREAD,
  FT_FILE,
  FT_LINE,
  FT_LEVEL,
  FT_MESSAGE,
};

#include "logger_field_time.h"
#include "logger_field_thread.h"
#include "logger_field_file.h"
#include "logger_field_line.h"
#include "logger_field_level.h"
#include "logger_field_message.h"

#endif /* defined(__algorithm__logger_field__) */
