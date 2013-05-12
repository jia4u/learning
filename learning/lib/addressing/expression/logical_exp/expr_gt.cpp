//
//  expr_gt.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_gt.h"

expr_gt::~expr_gt()
{

}

expr_gt::expr_gt( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_gt::operation() const
{
  return OPT_GT;
}

expression* expr_gt::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_gt::calculate( ) const
{
    // override this implement
  return nullptr;
}
