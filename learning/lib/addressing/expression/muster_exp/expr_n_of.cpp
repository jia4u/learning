//
//  expr_n_of.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_n_of.h"

expr_n_of::~expr_n_of()
{

}

expr_n_of::expr_n_of( expression *muster, expression *number )
{
  m_muster = muster;
  m_number = number;
}

enum operation expr_n_of::operation() const
{
  return OPT_N_OF;
}

expression* expr_n_of::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_muster;
    case 1:
      return m_number;
  }

  return nullptr;
}

expr_result* expr_n_of::calculate( ) const
{
    // override this implement
  return nullptr;
}
