//
//  expr_like.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_like.h"

expr_like::~expr_like()
{

}

expr_like::expr_like( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_like::operation() const
{
  return OPT_LIKE;
}

expression* expr_like::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_like::calculate( ) const
{
    // override this implement
  return nullptr;
}
