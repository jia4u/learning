//
//  cmd.cpp
//  learning
//
//  Created by xiangyun.kongxy on 4/14/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "cmd.h"
#include "err_common.h"

#include <iostream>
#include <string>

cmd::cmd( loader *loader )
{
  m_loader = loader;
}

long cmd::run( )
{
  std::string cmd;

  std::cin >> cmd;

  while ( cmd != "quit" ) {
    
  }

  return E_OK;
}
