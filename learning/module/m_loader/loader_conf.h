//
//  loader_conf.h
//  learning
//
//  Created by xiangyun.kongxy on 4/7/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_loader_conf_h
#define learning_loader_conf_h

#include "module_manager.h"
#include "xml_conf.h"

class loader_conf {

public:
  static module_manager* load_modules_from_conf( xml_tree *root );
  static module_load_info* load_module_from_conf( xml_tree *rrot );
};

#endif
