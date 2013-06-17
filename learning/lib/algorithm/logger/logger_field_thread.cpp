//
//  logger_field_thread.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_field_thread.h"

#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

const char* logger_field_thread::filter_text( const char *org )
{
  return filter_text( -1 );
}

const char* logger_field_thread::filter_text( long org )
{
  long tid;
  static char buf[32];
  tid = syscall( SYS_gettid );
  snprintf( buf, 32, "%ld", tid );

  return buf;
}

logger_field_thread::logger_field_thread( const char *name, char short_name,
                            bool enable_fixed_length, int fixed_length ):
  logger_field( name, short_name, enable_fixed_length, fixed_length )
{

}

logger_field_thread& logger_field_thread::operator= (
                            const logger_field_thread &field )
{
  logger_field::operator=( field );
  return *this;
}
