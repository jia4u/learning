//
//  expr_mod.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_mod.h"

expr_mod::~expr_mod()
{

}

expr_mod::expr_mod( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_mod::operation() const
{
  return OPT_MOD;
}

expression* expr_mod::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_mod::calculate( ) const
{
    // override this implement
  return nullptr;
}
