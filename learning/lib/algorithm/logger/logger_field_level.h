//
//  logger_field_level.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_field_level__
#define __algorithm__logger_field_level__

#include "logger_field.h"


class logger_field_level : public logger_field {

public:
  virtual const char* filter_text( const char *org );
  virtual const char* filter_text( long org );

  logger_field_level( const char *name = "level", char short_name = 'L',
                     bool enable_fixed_length = false, int fixed_length = 0 );
  virtual ~logger_field_level(){}
  logger_field_level& operator= ( const logger_field_level &field );
};

#endif /* defined(__algorithm__logger_field_level__) */
