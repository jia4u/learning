//
//  expr_negative.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_negative.h"

expr_negative::~expr_negative()
{

}

expr_negative::expr_negative( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_negative::operation() const
{
  return OPT_NEGATIVE;
}

expression* expr_negative::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_negative::calculate( ) const
{
    // override this implement
  return nullptr;
}
