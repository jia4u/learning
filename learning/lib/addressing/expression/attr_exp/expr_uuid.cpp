//
//  expr_uuid.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_uuid.h"

expr_uuid::~expr_uuid()
{

}

expr_uuid::expr_uuid( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_uuid::operation() const
{
  return OPT_UUID;
}

expression* expr_uuid::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_uuid::calculate( ) const
{
    // override this implement
  return nullptr;
}
