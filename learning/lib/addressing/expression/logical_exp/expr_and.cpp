//
//  expr_and.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_and.h"

expr_and::~expr_and()
{

}

expr_and::expr_and( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_and::operation() const
{
  return OPT_AND;
}

expression* expr_and::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_and::calculate( ) const
{
    // override this implement
  return nullptr;
}
