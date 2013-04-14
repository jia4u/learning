//
//  module_load_info.cpp
//  learning
//
//  Created by xiangyun.kongxy on 4/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "module_info.h"
#include "assertion.h"
#include "err_common.h"

#include <dlfcn.h>

long module_info::finish_load( )
{
  libaray = dlopen( load_info->bin_path.c_str(), RTLD_LAZY );
  check_null( libaray, E_LOAD_LIBRARY );

  init = (init_module)dlsym( libaray, load_info->func_init.c_str() );
  check_null( init, E_LOAD_FUNCTION );

  module = init( load_info->conf );
  check_null( module, E_CALL_INIT_MODULE );
  
  return E_OK;
}
