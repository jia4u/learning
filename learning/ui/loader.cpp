//
//  loader.cpp
//  learning
//
//  Created by xiangyun.kongxy on 4/14/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "loader.h"
#include "assertion.h"
#include "err_common.h"
#include "debug.h"

#include <dlfcn.h>
#include <string>

long loader::load( xml_tree *root )
{
  std::string bin;
  std::string init;
  xml_tree *tmp;
  xml_tree *loader = NULL;
  xml_tree *modules = NULL;

  tmp = root->first_node();
  while ( tmp != NULL ) {
    if ( strcmp( tmp->name(), "loader" ) == 0 )
      loader = tmp;
    else if ( strcmp( tmp->name(), "modules" ) == 0 )
      modules = tmp;

    tmp = tmp->next_sibling();
  }

  check_null( loader, E_CONF );
  check_null( modules, E_CONF );

  tmp = loader->first_node();
  while ( tmp != NULL ) {
    if ( strcmp( tmp->name(), "binary" ) == 0 )
      bin = tmp->value();
    else if ( strcmp( tmp->name(), "init" ) == 0 )
      init = tmp->value();

    tmp = tmp->next_sibling();
  }

  void *library;
  init_module init_func;

  library = dlopen( bin.c_str(), RTLD_NOW );
  check_null( library, E_LOAD_LIBRARY );

  init_func = (init_module)dlsym( library, init.c_str() );
  check_null( init_func, E_LOAD_FUNCTION );

  m_loader = init_func( modules );
  
  return E_OK;
}

long loader::start()
{
  check_null( m_loader, E_NOT_READY );

  return m_loader->start();
}

long loader::pause()
{
  check_null( m_loader, E_NOT_READY );

  return m_loader->pause();
}

long loader::stop()
{
  check_null( m_loader, E_NOT_READY );

  return m_loader->stop();
}
