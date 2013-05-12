//
//  addr_direct.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef addressing_addr_direct_h
#define addressing_addr_direct_h

#include "addressing.h"

class addr_direct : public addressing
{
protected:
  uint64 m_address;

public:
  virtual addressing_type type() const;

  addr_direct( uint64 address );
  virtual ~addr_direct();
};

#endif
