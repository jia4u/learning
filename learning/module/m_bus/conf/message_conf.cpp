//
//  message_conf.cpp
//  learning
//
//  Created by xiangyun.kongxy on 3/28/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "message_conf.h"

message_manager* message_loader::load_messages_from_xml(
      const xml_tree *root )
{
  message_manager *messages;
  message message;
  xml_tree *tmp;

  messages = new message_manager( );

  tmp = root->first_node();
  while ( tmp != NULL ) {
    message = load_message_from_xml( tmp );
    messages->register_msg( message );

    tmp = tmp->next_sibling();
  }

  return messages;
}

message message_loader::load_message_from_xml( const xml_tree *root )
{
  message message;
  xml_tree *tmp;

  tmp = root->first_node();
  while ( tmp != NULL ) {
    if ( strcmp( tmp->name(), "id" ) == 0 )
      message.uuid = atoll( tmp->value() );
    else if ( strcmp( tmp->name(), "type" ) == 0 )
      message.type = (message_type)atoi( tmp->value() );
    else if ( strcmp( tmp->name(), "name" ) )
      message.name = tmp->value();
    else if ( strcmp( tmp->value(), "description" ) )
      message.desc = tmp->value();

    tmp = tmp->next_sibling();
  }

  return message;
}

