//
//  expr_nth_of.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_nth_of.h"

expr_nth_of::~expr_nth_of()
{

}

expr_nth_of::expr_nth_of( expression *muster, expression *position )
{
  m_muster = muster;
  m_position = position;
}

enum operation expr_nth_of::operation() const
{
  return OPT_NTH_OF;
}

expression* expr_nth_of::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_muster;
    case 1:
      return m_position;
  }

  return nullptr;
}

expr_result* expr_nth_of::calculate( ) const
{
    // override this implement
  return nullptr;
}
