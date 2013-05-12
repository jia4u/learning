//
//  expr_diff.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_diff.h"

expr_diff::~expr_diff()
{

}

expr_diff::expr_diff( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_diff::operation() const
{
  return OPT_DIFF;
}

expression* expr_diff::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_diff::calculate( ) const
{
    // override this implement
  return nullptr;
}

