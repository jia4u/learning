//
//  expr_nvisit.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_nvisit.h"

expr_nvisit::~expr_nvisit()
{

}

expr_nvisit::expr_nvisit( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_nvisit::operation() const
{
  return OPT_NVISIT;
}

expression* expr_nvisit::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_nvisit::calculate( ) const
{
    // override this implement
  return nullptr;
}
