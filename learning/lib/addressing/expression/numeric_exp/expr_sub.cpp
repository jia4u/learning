//
//  expr_sub.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_sub.h"

expr_sub::~expr_sub()
{

}

expr_sub::expr_sub( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_sub::operation() const
{
  return OPT_SUB;
}

expression* expr_sub::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_sub::calculate( ) const
{
    // override this implement
  return nullptr;
}
