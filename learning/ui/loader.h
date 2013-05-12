//
//  loader.h
//  learning
//
//  Created by xiangyun.kongxy on 4/14/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_loader_h
#define learning_loader_h

#include "module.h"

class loader {
  module *m_loader;

public:
  long load( xml_tree *root );
  long start();
  long pause();
  long stop();
};

#endif
