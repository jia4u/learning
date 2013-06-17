//
//  logger_field_thread.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_field_thread__
#define __algorithm__logger_field_thread__

#include "logger_field.h"


class logger_field_thread : public logger_field {

public:
  virtual const char* filter_text( const char *org );
  virtual const char* filter_text( long org );

  logger_field_thread( const char *name = "thread", char short_name = 't',
                      bool enable_fixed_length = false, int fixed_length = 0 );
  virtual ~logger_field_thread(){}
  logger_field_thread& operator= ( const logger_field_thread &field );
};

#endif /* defined(__algorithm__logger_field_thread__) */
