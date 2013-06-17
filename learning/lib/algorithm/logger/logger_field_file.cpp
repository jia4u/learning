//
//  logger_field_file.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_field_file.h"
#include "../string/string_move.h"
#include "../string/string_cut.h"

#include <string.h>
#include <stdio.h>

const char* logger_field_file::filter_text( const char *org )
{
  static char buf[MAX_LOG_LENGTH];
  static char path[MAX_PATH_LENGTH];
  static char filename[MAX_FILE_NAME_LENGTH];
  static char ext[MAX_FILE_EXT_LENGTH];
  const char *ptr;
  int len = 0;

  parse_full_path( org, path, MAX_PATH_LENGTH,
                  filename, MAX_FILE_NAME_LENGTH, ext, MAX_FILE_EXT_LENGTH );

  ptr = m_format;
  while ( *ptr )
  {
    switch ( *ptr )
    {
    case '%':
        switch ( ptr[1] )
        {
        case 'P':
            len += alg::strcpy( buf + len, path );
            break;
        case 'F':
            len += alg::strcpy( buf + len, filename );
            break;
        case 'E':
            len += alg::strcpy( buf + len, ext );
            break;
        default:
            buf[ len++ ] = ptr[1];
            break;
        }
        ptr += 2;
        break;
    default:
        buf[ len++ ] = *ptr;
        ++ptr;
        break;
    }
  }
  buf[len] = 0;

  return apply_fixed_length( buf );
}

const char* logger_field_file::filter_text( long org )
{
  return "";
}

logger_field_file::logger_field_file( const char *name, char short_name,
                  bool enable_fixed_length, int fixed_length,
                  const char *format ):
  logger_field( name, short_name, enable_fixed_length, fixed_length )
{
  m_format = nullptr;
  set_format( format );
}

logger_field_file::~logger_field_file()
{
  delete[] m_format;
}

logger_field_file& logger_field_file::operator= (
                  const logger_field_file &field )
{
  logger_field::operator=( field );

  return *this;
}

const char* logger_field_file::get_format() const
{
  return m_format;
}

void logger_field_file::set_format( const char *format )
{
  size_t len;

  if ( format == nullptr )
    format = "%F%E";

  len = strlen( format );
  if ( m_format != nullptr )
    delete[] m_format;
  m_format = new char[ len + 1 ];

  len = 0;
  while ( *format )
  {
    switch ( *format )
    {
    case '%':
        switch ( format[1] )
        {
        case 'P':
        case 'F':
        case 'E':
            m_format[ len ] = '%';
            m_format[ len+1 ] = format[1];
            len += 2;
            break;
        default:
            m_format[ len++ ] = format[1];
            break;
        }
        format += 2;
        break;
    default:
        m_format[ len++ ] = *format;
        ++format;
        break;
    }
  }
  m_format[ len ] = 0;
}

void logger_field_file::parse_full_path( const char *fullpath,
                     char *buf_for_path, int buf_for_path_len,
                     char *buf_for_filename, int buf_for_filename_len,
                     char *buf_for_ext,  int buf_for_ext_len )
{
  static char file[MAX_FILE_LENGTH];

  alg::strspl_right( fullpath, '/', file, MAX_FILE_LENGTH,
                    buf_for_path, buf_for_path_len );
  alg::strspl_right( file, '.', buf_for_ext, buf_for_ext_len,
                    buf_for_filename, buf_for_filename_len );
}
