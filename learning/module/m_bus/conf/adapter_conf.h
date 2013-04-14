//
//  adapter_conf.h
//  learning
//
//  Created by xiangyun.kongxy on 3/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_adapter_conf_h
#define learning_adapter_conf_h

#include "message_conf.h"
#include "../adapter/adapter.h"
#include "xml_conf.h"

class adapter_loader {
public:
  static adapter* load_adapter_from_xml( const xml_tree *root );
};

#endif
