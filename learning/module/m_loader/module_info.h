//
//  module_load_info.h
//  learning
//
//  Created by xiangyun.kongxy on 4/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_module_load_info_h
#define learning_module_load_info_h

#include "module.h"
#include "int.h"

#include <vector>
#include <string>

struct module_load_info {
  uint64 uuid;
  std::string name;
  std::string bin_path;
  std::string func_init;
  std::vector<uint64> depend;
  xml_tree *conf;
};


struct module_info {
  module_load_info *load_info;
  void *libaray;
  init_module init;
  module *module;

  long finish_load( );
};

#endif
