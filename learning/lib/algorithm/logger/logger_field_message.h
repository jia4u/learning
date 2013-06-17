//
//  logger_field_message.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_field_message__
#define __algorithm__logger_field_message__

#include "logger_field.h"

class logger_field_message : public logger_field {
  
public:
  virtual const char* filter_text( const char *org );
  virtual const char* filter_text( long org );

  logger_field_message( const char *name = "message", char short_name = 'M',
                       bool enable_fixed_length = false, int fixed_length = 0 );
  virtual ~logger_field_message(){}
  logger_field_message& operator= ( const logger_field_message &field );

};

#endif /* defined(__algorithm__logger_field_message__) */
