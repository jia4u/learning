//
//  logger_field_time.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_field_time.h"
#include <string.h>
#include <time.h>
#include <stdio.h>

const char* logger_field_time::filter_text( const char *org )
{
  return filter_text( -1 );
}

const char* logger_field_time::filter_text( long org )
{
  static char buf[64];

  time_t cur;
  tm *now;
  time( &cur );
  now = gmtime( &cur );

  const char *ptr;
  int len;
  len = 0;
  ptr = m_format;
  while ( *ptr )
  {
    switch ( *ptr )
    {
      case '%':
        switch ( ptr[1] )
        {
          case 'Y':
            len += sprintf( buf+len, "%d", now->tm_year + 1900 );
            break;
          case 'm':
            len += sprintf( buf+len, "%d", now->tm_mon + 1 );
            break;
          case 'd':
            len += sprintf( buf+len, "%d", now->tm_mday );
            break;
          case 'H':
            len += sprintf( buf+len, "%d", now->tm_hour );
            break;
          case 'M':
            len += sprintf( buf+len, "%d", now->tm_min );
            break;
          case 'S':
            len += sprintf( buf+len, "%d", now->tm_sec );
            break;
          default:
            buf[len++] = ptr[1];
            break;
        }
        ptr += 2;
        break;
      default:
        buf[len++] = *ptr;
        ++ptr;
        break;
    }
  }
  buf[len] = 0;
  return apply_fixed_length( buf );
}

logger_field_time::logger_field_time( const char *name, char short_name,
                  bool enable_fixed_length, int fixed_length,
                  const char *format ) :
  logger_field( name, short_name, enable_fixed_length, fixed_length )
{
  m_format = nullptr;
  set_format( format );
}

logger_field_time::~logger_field_time()
{
  delete[] m_format;
}

logger_field_time& logger_field_time::operator= ( const logger_field_time &field )
{
  logger_field::operator=( field );
  return *this;
}

const char* logger_field_time::get_format()
{
  return m_format;
}

void logger_field_time::set_format( const char *format )
{
  if ( m_format != nullptr )
    delete[] m_format;

  int len = 0;
  m_format = new char[ strlen(format) + 1 ];
  while ( *format )
  {
    switch ( *format )
    {
      case '%':
        switch ( format[1] )
        {
          case 'Y':
          case 'm':
          case 'd':
          case 'H':
          case 'M':
          case 'S':
            m_format[len++] = '%';
            m_format[len++] = format[1];
            break;
          default:
            m_format[len++] = format[1];
            break;
        }
        format += 2;
        break;
      default:
        m_format[len++] = *format;
        ++format;
        break;
    }
  }
  m_format[len] = 0;
}
