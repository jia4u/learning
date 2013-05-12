//
//  expr_child.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_child.h"

expr_child::~expr_child()
{

}

expr_child::expr_child( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_child::operation() const
{
  return OPT_CHILD;
}

expression* expr_child::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_child::calculate( ) const
{
    // override this implement
  return nullptr;
}
