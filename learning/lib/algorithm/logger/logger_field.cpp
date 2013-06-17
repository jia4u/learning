//
//  logger_field.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_field.h"

#include <string.h>

logger_field::logger_field( const char *name, char short_name,
             bool enable_fixed_length, int fixed_length )
{
  m_name                = new char[ strlen(name) + 1 ];
  strcpy( m_name, name );
  m_short_name          = short_name;
  m_enable_fixed_length = enable_fixed_length;
  m_fixed_length        = fixed_length;

  if ( m_fixed_length < 0 )
    m_fixed_length = 0;

  if ( m_enable_fixed_length )
    m_cpy_buf = new char[ m_fixed_length + 1 ];
  else
    m_cpy_buf = nullptr;
}

logger_field::~logger_field()
{
  delete[] m_name;

  if ( m_cpy_buf != nullptr )
    delete[] m_cpy_buf;
}

logger_field& logger_field::operator= ( const logger_field &field )
{
  delete[] m_name;

  m_name                = new char[ strlen(field.m_name) + 1 ];
  strcpy( m_name, field.m_name );
  m_short_name          = field.m_short_name;
  m_enable_fixed_length = field.m_enable_fixed_length;
  m_fixed_length        = field.m_fixed_length;

  if ( m_fixed_length < 0 )
    m_fixed_length = 0;

  if ( m_cpy_buf != nullptr )
    delete[] m_cpy_buf;

  if ( m_enable_fixed_length )
    m_cpy_buf = new char[ m_fixed_length + 1 ];
  else
    m_cpy_buf = nullptr;

  return *this;
}

const char* logger_field::get_name() const
{
  return m_name;
}

char logger_field::get_short_name() const
{
  return m_short_name;
}

bool logger_field::is_fixed_length() const
{
  return m_enable_fixed_length;
}

void logger_field::enable_fixed_length()
{
  m_enable_fixed_length = true;

  if ( m_cpy_buf == nullptr )
    m_cpy_buf = new char[ m_fixed_length + 1];
}

void logger_field::disable_fixed_length()
{
  m_enable_fixed_length = false;

  if ( m_cpy_buf != nullptr )
    delete[] m_cpy_buf;
  m_cpy_buf = nullptr;
}

int  logger_field::get_fixed_length() const
{
  return m_fixed_length;
}

void logger_field::set_fixed_length( int len )
{
  if ( len > 0 )
    m_fixed_length = len;
  else
    m_fixed_length = 0;

  if ( m_cpy_buf != nullptr )
    delete[] m_cpy_buf;

  if ( m_enable_fixed_length )
    m_cpy_buf = new char[ m_fixed_length + 1];
}

const char* logger_field::apply_fixed_length( const char *org )
{

  if ( m_enable_fixed_length )
  {
    strncpy( m_cpy_buf, org, m_fixed_length );
    return m_cpy_buf;
  }
  else
  {
    return org;
  }
}
