//
//  adapter_conf.cpp
//  learning
//
//  Created by xiangyun.kongxy on 3/28/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "adapter_conf.h"
#include "errdef.h"
#include <string>

adapter* adapter_loader::load_adapter_from_xml( const xml_tree *root )
{
  message_manager *messages = NULL;
  xml_tree *tmp;
  std::string id;

  tmp = root->first_node();

  while ( tmp != NULL ) {
    if ( strcmp( tmp->name(), "id" ) == 0 )
      id = tmp->value();
    else
      messages = message_loader::load_messages_from_xml( tmp );

    tmp = tmp->next_sibling();
  }

  return new adapter( atol( id.c_str() ), messages );
}

