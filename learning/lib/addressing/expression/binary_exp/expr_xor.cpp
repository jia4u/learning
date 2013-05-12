//
//  expr_xor.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_xor.h"

expr_xor::~expr_xor()
{

}

expr_xor::expr_xor( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_xor::operation() const
{
  return OPT_XOR;
}

expression* expr_xor::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_xor::calculate( ) const
{
    // override this implement
  return nullptr;
}
