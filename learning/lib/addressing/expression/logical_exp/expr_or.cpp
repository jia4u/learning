//
//  expr_or.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_or.h"

expr_or::~expr_or()
{

}

expr_or::expr_or( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_or::operation() const
{
  return OPT_OR;
}

expression* expr_or::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_or::calculate( ) const
{
    // override this implement
  return nullptr;
}
