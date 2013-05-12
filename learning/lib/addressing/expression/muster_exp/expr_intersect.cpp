//
//  expr_intersect.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_intersect.h"

expr_intersect::~expr_intersect()
{

}

expr_intersect::expr_intersect( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_intersect::operation() const
{
  return OPT_INTERSECT;
}

expression* expr_intersect::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_intersect::calculate( ) const
{
    // override this implement
  return nullptr;
}
