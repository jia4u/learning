//
//  expr_or_b.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_or_b.h"

expr_or_b::~expr_or_b()
{

}

expr_or_b::expr_or_b( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_or_b::operation() const
{
  return OPT_OR_B;
}

expression* expr_or_b::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_or_b::calculate( ) const
{
    // override this implement
  return nullptr;
}
