//
//  loader_conf.cpp
//  learning
//
//  Created by xiangyun.kongxy on 4/14/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "loader_conf.h"

module_manager* loader_conf::load_modules_from_conf( xml_tree *root )
{
  module_manager *mgr;
  xml_tree *tmp;

  mgr = new module_manager();

  tmp = root->first_node();
  while ( tmp != NULL ) {
    if ( strcmp( tmp->name(), "module" ) == 0 ) {
      module_load_info *info;
      module_info *module;

      info              = load_module_from_conf( tmp );
      module            = new module_info( );
      module->load_info = info;
      
      module->finish_load();
      mgr->add_module( info->uuid, module );
    }
    tmp = tmp->next_sibling();
  }

  return mgr;
}

module_load_info* loader_conf::load_module_from_conf( xml_tree *root )
{
  xml_tree *tmp;
  module_load_info *info;
  info = new module_load_info( );

  tmp = root->first_node();
  while ( tmp != NULL ) {
    if ( strcmp( tmp->name(), "name" ) == 0 )
      info->name = tmp->value();
    else if ( strcmp( tmp->name(), "id" ) == 0 )
      info->uuid = atol( tmp->value() );
    else if ( strcmp( tmp->name(), "binary" ) == 0 )
      info->bin_path = tmp->value();
    else if ( strcmp( tmp->name(), "init" ) == 0 )
      info->func_init = tmp->value();
    else if ( strcmp( tmp->name(), "depend" ) == 0 )
      info->depend.push_back( atol( tmp->value() ) );
    else if ( strcmp( tmp->name(), "conf" ) == 0 )
      info->conf = tmp;
    
    tmp = tmp->next_sibling();
  }

  return info;
}
