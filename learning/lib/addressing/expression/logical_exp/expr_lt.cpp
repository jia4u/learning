//
//  expr_lt.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_lt.h"

expr_lt::~expr_lt()
{

}

expr_lt::expr_lt( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_lt::operation() const
{
  return OPT_LT;
}

expression* expr_lt::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_lt::calculate( ) const
{
    // override this implement
  return nullptr;
}
