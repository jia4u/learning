//
//  expr_add.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_add.h"

expr_add::~expr_add()
{

}

expr_add::expr_add( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_add::operation() const
{
  return OPT_ADD;
}

expression* expr_add::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_add::calculate( ) const
{
    // override this implement
  return nullptr;
}
