//
//  expr_ne.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_ne.h"

expr_ne::~expr_ne()
{

}

expr_ne::expr_ne( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_ne::operation() const
{
  return OPT_NE;
}

expression* expr_ne::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_ne::calculate( ) const
{
    // override this implement
  return nullptr;
}
