//
//  logger_field_level.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_field_level.h"
#include "logger_level.h"

#include <stdio.h>

const char* logger_field_level::filter_text( const char *org )
{
  return apply_fixed_length( org );
}

const char* logger_field_level::filter_text( long org )
{
  char buf[32];
  int i;
  for ( i = 0; i < LOG_LEVEL_COUNT; ++i )
  {
    if ( logger_level_info[i].id == org )
    {
      snprintf( buf, 32, "%s", logger_level_info[i].name );
      break;
    }
  }
  return apply_fixed_length( buf );
}

logger_field_level::logger_field_level( const char *name, char short_name,
                    bool enable_fixed_length, int fixed_length ):
  logger_field( name, short_name, enable_fixed_length, fixed_length )
{

}

logger_field_level& logger_field_level::operator= (
                    const logger_field_level &field )
{
  logger_field::operator=( field );

  return *this;
}
