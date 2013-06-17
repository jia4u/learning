//
//  logger_style.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_style.h"
#include "err_common.h"
#include "logger_storage.h"

#include <string.h>

logger_field* logger_style::get_field( field_type type ) const
{
  switch ( type )
  {
    case FT_TIME:
      return m_field_time;
    case FT_THREAD:
      return m_field_thread;
    case FT_FILE:
      return m_field_file;
    case FT_LINE:
      return m_field_line;
    case FT_LEVEL:
      return m_field_level;
    case FT_MESSAGE:
      return m_field_message;
    default:
      return nullptr;
  }
}

const char* logger_style::get_format( log_level level ) const
{
  switch ( level )
  {
    case LL_DEBUG:
      return m_format_debug;
    case LL_INFO:
      return m_format_info;
    case LL_WARNING:
      return m_format_warning;
    case LL_ERROR:
      return m_format_error;
    case LL_PANIC:
      return m_format_panic;
    default:
      return nullptr;
  }
}

long logger_style::set_format( log_level level, const char *format )
{
  char *tmp;
  tmp = new char[ strlen( format ) + 1 ];

  int len = 0;
  while ( *format )
  {
    switch ( *format )
    {
      case '%':
        switch ( format[1] )
      {
        case 'T':
        case 't':
        case 'F':
        case 'l':
        case 'L':
        case 'M':
          tmp[len++] = '%';
          tmp[len++] = format[1];
          break;
        default:
          tmp[len++] = format[1];
          break;
      }
        format += 2;
        break;
      default:
        tmp[len++] = *format;
        ++format;
        break;
    }
  }
  
  switch ( level )
  {
    case LL_DEBUG:
      if ( m_format_debug != nullptr )
        delete[] m_format_debug;
      m_format_debug = tmp;
      break;
    case LL_INFO:
      if ( m_format_info != nullptr )
        delete[] m_format_info;
      m_format_info = tmp;
      break;
    case LL_WARNING:
      if ( m_format_warning != nullptr )
        delete[] m_format_warning;
      m_format_warning = tmp;
      break;
    case LL_ERROR:
      if ( m_format_error != nullptr )
        delete[] m_format_error;
      m_format_error = tmp;
      break;
    case LL_PANIC:
      if ( m_format_panic != nullptr )
        delete[] m_format_panic;
      m_format_debug = tmp;
      break;
    default:
      return E_NO_SUCH_LOG_LEVEL;
  }
  return E_OK;
}

long logger_style::set_storage( logger_type type, const char *path )
{
  switch ( type )
  {
    case LT_FILE:
      delete m_storage;
      m_storage = new logger_storage_file( path );
      break;
    case LT_MEMORY:
      delete m_storage;
      m_storage = new logger_storage_shm( path );
      break;
    default:
      return E_UNKNOW_STORAGE;
  }
  return E_OK;
}

logger_storage* logger_style::get_storage() const
{
  return m_storage;
}

logger_style::logger_style( const char *storage_path, logger_type storage_type )
{
  m_field_time    = new logger_field_time();
  m_field_thread  = new logger_field_thread();
  m_field_file    = new logger_field_file();
  m_field_line    = new logger_field_line();
  m_field_level   = new logger_field_level();
  m_field_message = new logger_field_message();

  m_format_debug    = nullptr;
  m_format_info     = nullptr;
  m_format_warning  = nullptr;
  m_format_error    = nullptr;
  m_format_panic    = nullptr;

  set_format( LL_DEBUG,   "%L %T %t %F:%l %M" );
  set_format( LL_INFO,    "%L %T %M" );
  set_format( LL_WARNING, "%L %T %M" );
  set_format( LL_ERROR,   "%L %T %F:%l %M" );
  set_format( LL_PANIC,   "%L %T %t %F:%l %M" );

  m_storage = nullptr;
  set_storage( storage_type, storage_path );
}

logger_style::~logger_style()
{
  delete m_field_time;
  delete m_field_thread;
  delete m_field_file;
  delete m_field_line;
  delete m_field_level;
  delete m_field_message;

  delete[] m_format_debug;
  delete[] m_format_info;
  delete[] m_format_warning;
  delete[] m_format_error;
  delete[] m_format_panic;

  delete m_storage;
}

