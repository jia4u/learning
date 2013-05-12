//
//  expr_nref.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_nref.h"

expr_nref::~expr_nref()
{

}

expr_nref::expr_nref( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_nref::operation() const
{
  return OPT_NREF;
}

expression* expr_nref::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_nref::calculate( ) const
{
    // override this implement
  return nullptr;
}
