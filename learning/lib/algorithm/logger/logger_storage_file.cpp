//
//  log_storage_file.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_storage_file.h"

long logger_storage_file::write( const char *log, long len )
{
  if ( m_buf_remain > len )
  {
    strncat( m_buf, log, len );
    m_buf_remain -= len;
  }
  else if ( m_buf_cap > 0 )
  {
    m_stream << m_buf;
    m_buf_remain = m_buf_cap;

    m_stream.write( log, len );
  }
  else
  {
    m_stream.write( log, len );
  }

  return len;
}

int  logger_storage_file::get_buffer_size() const
{
  return m_buf_cap;
}

void logger_storage_file::set_buffer_size( int size )
{
  if ( m_buf_remain < m_buf_cap )
    m_stream << m_buf;

  if ( m_buf != nullptr )
    delete[] m_buf;

  m_buf_cap = size;
  m_buf_remain = size;
  if ( m_buf_cap > 0 )
    m_buf = new char[ m_buf_cap + 1 ];
}

const char* logger_storage_file::type()
{
  return "file";
}

logger_storage_file::~logger_storage_file()
{
  if ( m_buf != nullptr )
    delete[] m_buf;
}

logger_storage_file::logger_storage_file( const char *path )
{
  m_buf_cap     = 0;
  m_buf_remain  = 0;
  m_buf         = nullptr;
  m_stream.open( path );
}
