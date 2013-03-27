//
//  bus_conf.h
//  learning
//
//  Created by xiangyun.kongxy on 3/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_bus_conf_h
#define learning_bus_conf_h

#include "adapter_conf.h"
#include "../bus.h"
#include "xml_conf.h"

class bus_loader {
public:
  static bus* load_buf_from_xml( const xml_tree *root );
};

#endif
