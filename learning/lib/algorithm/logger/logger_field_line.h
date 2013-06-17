//
//  logger_field_line.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_field_line__
#define __algorithm__logger_field_line__

#include "logger_field.h"

class logger_field_line : public logger_field {

public:
  virtual const char* filter_text( const char *org );
  virtual const char* filter_text( long org );

  logger_field_line( const char *name = "line", char short_name = 'l',
                    bool enable_fixed_length = false, int fixed_length = 0 );
  virtual ~logger_field_line(){}
  logger_field_line& operator= ( const logger_field_line &field );
};

#endif /* defined(__algorithm__logger_field_line__) */
