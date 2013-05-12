//
//  expr_const.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_const.h"

expr_const_number::expr_const_number( int64 number )
{
  m_number = number;
}

expr_const_number::~expr_const_number()
{

}

enum operation expr_const_number::operation() const
{
  return OPT_CONST_NUMBER;
}

expression* expr_const_number::paramenter( int nth ) const
{
  return nullptr;
}

expr_result* expr_const_number::calculate() const
{
  return new expr_result( m_number );
}

expr_const_string::expr_const_string( const char *string )
{
  m_string = string;
}

expr_const_string::~expr_const_string()
{

}

enum operation expr_const_string::operation() const
{
  return OPT_CONST_STRING;
}

expression* expr_const_string::paramenter( int nth ) const
{
  return nullptr;
}

expr_result* expr_const_string::calculate() const
{
  return new expr_result( m_string );
}

expr_const_all::~expr_const_all()
{

}

enum operation expr_const_all::operation() const
{
  return OPT_CONST_OBJ_ALL;
}

expression* expr_const_all::paramenter( int nth ) const
{
  return nullptr;
}

expr_result* expr_const_all::calculate() const
{
  return nullptr;
}

expr_const_cur::~expr_const_cur()
{

}

enum operation expr_const_cur::operation() const
{
  return OPT_CONST_OBJ_CUR;
}

expression* expr_const_cur::paramenter( int nth ) const
{
  return nullptr;
}

expr_result* expr_const_cur::calculate() const
{
  return nullptr;
}

expr_const_rest::~expr_const_rest()
{

}

enum operation expr_const_rest::operation() const
{
  return OPT_CONST_OBJ_CUR;
}

expression* expr_const_rest::paramenter( int nth ) const
{
  return nullptr;
}

expr_result* expr_const_rest::calculate() const
{
  return nullptr;
}

