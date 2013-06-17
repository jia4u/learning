//
//  logger_field_message.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_field_message.h"
#include <string.h>

const char* logger_field_message::filter_text( const char *org )
{
  return apply_fixed_length( org );
}

const char* logger_field_message::filter_text( long org )
{
  return "";
}

logger_field_message::logger_field_message( const char *name, char short_name,
                     bool enable_fixed_length, int fixed_length ):
  logger_field( name, short_name, enable_fixed_length, fixed_length )
{

}

logger_field_message& logger_field_message::operator= (
                                 const logger_field_message &field )
{
  logger_field::operator=( field );

  return *this;
}
