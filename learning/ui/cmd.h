//
//  cmd.h
//  learning
//
//  Created by xiangyun.kongxy on 4/14/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_cmd_h
#define learning_cmd_h

#include "loader.h"

class cmd {
  loader *m_loader;

public:
  cmd( loader *loader );
  long run( );
};

#endif
