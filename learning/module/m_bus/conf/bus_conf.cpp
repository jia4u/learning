//
//  bus_conf.cpp
//  learning
//
//  Created by xiangyun.kongxy on 3/28/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "bus_conf.h"
#include "errdef.h"

bus* bus_loader::load_bus_from_xml( const xml_tree *root )
{
  adapter_manager *adapters;
  adapter *adapter;
  xml_tree *tmp;

  adapters = new adapter_manager( );

  tmp = root->first_node();
  while ( tmp != NULL ) {
    adapter = adapter_loader::load_adapter_from_xml( tmp );
    adapters->add_adapter( adapter );

    tmp = tmp->next_sibling();
  }

  return new bus( adapters );
}
