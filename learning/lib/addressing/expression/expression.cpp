//
//  expression.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expression.h"

expr_result_type expr_result::type() const
{
  return m_type;
}

int64 expr_result::integer() const
{
  return m_result.integer;
}

const char* expr_result::string() const
{
  return m_result.string;
}

class object* expr_result::object() const
{
  return m_result.object;
}

expr_result::~expr_result()
{

}

expr_result::expr_result( int64 result )
{
  m_type = ERT_INTEGER;
  m_result.integer = result;
}

expr_result::expr_result( const char *result )
{
  m_type = ERT_STRING;
  m_result.string = result;
}

expr_result::expr_result( class object *result )
{
  m_type = ERT_OBJECT;
  m_result.object = result;
}

expression::~expression()
{
  
}
