//
//  logger_field_line.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_field_line.h"
#include <stdio.h>

const char* logger_field_line::filter_text( const char *org )
{
  return apply_fixed_length( org );
}

const char* logger_field_line::filter_text( long org )
{
  char buf[32];
  snprintf( buf, 32, "%ld", org );
  return apply_fixed_length( buf );
}

logger_field_line::logger_field_line( const char *name, char short_name,
                      bool enable_fixed_length, int fixed_length ):
  logger_field( name, short_name, enable_fixed_length, fixed_length )
{
}


logger_field_line& logger_field_line::operator= (
                    const logger_field_line &field )
{
  logger_field::operator=( field );
  return *this;
}
