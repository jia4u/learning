//
//  expr_ge.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_ge.h"

expr_ge::~expr_ge()
{

}

expr_ge::expr_ge( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_ge::operation() const
{
  return OPT_GE;
}

expression* expr_ge::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_ge::calculate( ) const
{
    // override this implement
  return nullptr;
}
