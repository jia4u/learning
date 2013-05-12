//
//  expr_le.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_le.h"

expr_le::~expr_le()
{

}

expr_le::expr_le( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_le::operation() const
{
  return OPT_LE;
}

expression* expr_le::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_le::calculate( ) const
{
    // override this implement
  return nullptr;
}
