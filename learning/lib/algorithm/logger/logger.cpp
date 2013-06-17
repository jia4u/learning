//
//  logger.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger.h"
#include "../string/string_move.h"

#include <stdio.h>

logger_style* logger::get_conf() const
{
  return m_style;
}

void logger::debug( const char* file, int line, const char *format, ... )
{
  va_list para;
  va_start( para, format );
  log( LL_DEBUG, file, line, format, para );
  va_end( para );
}

void logger::info( const char* file, int line, const char *format, ... )
{
  va_list para;
  va_start( para, format );
  log( LL_INFO, file, line, format, para );
  va_end( para );
}

void logger::warning( const char* file, int line, const char *format, ... )
{
  va_list para;
  va_start( para, format );
  log( LL_WARNING, file, line, format, para );
  va_end( para );
}

void logger::error( const char* file, int line, const char *format, ... )
{
  va_list para;
  va_start( para, format );
  log( LL_ERROR, file, line, format, para );
  va_end( para );
}

void logger::panic( const char* file, int line, const char *format, ... )
{
  va_list para;
  va_start( para, format );
  log( LL_PANIC, file, line, format, para );
  va_end( para );
}

void logger::release()
{
  --m_ref;
}

void logger::add_ref()
{
  ++m_ref;
}

int logger::get_ref() const
{
  return m_ref;
}

void logger::log( log_level level, const char *file, int line,
                 const char *format, va_list para)
{
  char buf[ MAX_LOG_LENGTH ];
  char msg[ MAX_LOG_LENGTH ];
  const char *inter_format;

  vsnprintf( msg, MAX_LOG_LENGTH, format, para );
  inter_format = m_style->get_format( level );

  if ( inter_format != nullptr )
  {
    int len = 0;
    while ( *inter_format )
    {
      logger_field *field;
      switch ( *inter_format )
      {
        case '%':
          switch ( inter_format[1] )
          {
            case 'T':
              field = m_style->get_field( FT_TIME );
              len += alg::strcpy( buf + len, field->filter_text( -1 ) );
              break;
            case 't':
              field = m_style->get_field( FT_THREAD );
              len += alg::strcpy( buf + len, field->filter_text( -1 ) );
              break;
            case 'F':
              field = m_style->get_field( FT_FILE );
              len += alg::strcpy( buf + len, field->filter_text( file ) );
              break;
            case 'L':
              field = m_style->get_field( FT_LEVEL );
              len += alg::strcpy( buf + len, field->filter_text( level ) );
              break;
            case 'l':
              field = m_style->get_field( FT_LINE );
              len += alg::strcpy( buf + len, field->filter_text( line ) );
              break;
            case 'M':
              field = m_style->get_field( FT_MESSAGE );
              len += alg::strcpy( buf + len, field->filter_text( msg ) );
              break;
            default:
              buf[ len++ ] = inter_format[1];
              break;
          }
          inter_format += 2;
          break;
        default:
          buf[ len++ ] = *inter_format;
          ++inter_format;
          break;
      }
    }
  }
}

logger::logger( const char *path, logger_type type )
{
  m_style = new logger_style( path, type );
}

logger::~logger()
{
  delete m_style;
}
