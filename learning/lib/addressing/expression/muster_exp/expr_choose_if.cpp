//
//  expr_choose_if.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_choose_if.h"

expr_choose_if::~expr_choose_if()
{

}

expr_choose_if::expr_choose_if( expression *muster, expression *condition )
{
  m_muster = muster;
  m_condition = condition;
}

enum operation expr_choose_if::operation() const
{
  return OPT_CHOOSE_IF;
}

expression* expr_choose_if::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_muster;
    case 1:
      return m_condition;
  }

  return nullptr;
}

expr_result* expr_choose_if::calculate( ) const
{
    // override this implement
  return nullptr;
}
