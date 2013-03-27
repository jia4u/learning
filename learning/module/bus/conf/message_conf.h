//
//  message_conf.h
//  learning
//
//  Created by xiangyun.kongxy on 3/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_message_conf_h
#define learning_message_conf_h

#include "../message/message.h"
#include "../message/message_manager.h"
#include "xml_conf.h"

class message_loader {
public:
  static message_manager* load_messages_from_xml( const xml_tree *root );
  static message load_message_from_xml( const xml_tree *root );
};

#endif
