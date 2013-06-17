//
//  loader.cpp
//  learning
//
//  Created by xiangyun.kongxy on 4/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "loader.h"
#include "loader_conf.h"
#include "err_common.h"
#include "assertion.h"

module_loader::~module_loader()
{
  if ( m_module != NULL )
    delete m_module;
}

extern "C" module_loader* init_module_loader( xml_tree *root )
{
  module_loader *loader;
  module_manager *mgr;

  mgr = loader_conf::load_modules_from_conf( root );
  check_null( mgr, NULL );

  loader = new module_loader( );
  check_null( loader, NULL );
  loader->set_manager( mgr );
  
  return loader;
}

void module_loader::set_manager( module_manager *mgr )
{
  m_module = mgr;
}

void* module_loader::get_resource( uint64 res_id )
{
  return NULL;
}

void module_loader::set_depend( module *depend, uint64 module_id )
{

}

long module_loader::start()
{
  module_manager::const_iterator i;
  long code;

  check_null( m_module, E_NOT_READY );

  for ( i = m_module->begin(); i != m_module->end(); ++i ) {
    check_null( i->second, E_NOT_EXIST );
    check_null( i->second->module, E_NOT_EXIST );

    code = i->second->module->start();
    check_code( code, E_MODULE_START );
  }
  
  return E_OK;
}

long module_loader::pause()
{
  module_manager::const_iterator i;
  long code;

  check_null( m_module, E_NOT_READY );

  for ( i = m_module->begin(); i != m_module->end(); ++i ) {
    check_null( i->second, E_NOT_EXIST );
    check_null( i->second->module, E_NOT_EXIST );

    code = i->second->module->pause();
    check_code( code, E_MODULE_START );
  }

  return E_OK;
}

long module_loader::stop()
{
  module_manager::const_iterator i;
  long code;

  check_null( m_module, E_NOT_READY );

  for ( i = m_module->begin(); i != m_module->end(); ++i ) {
    check_null( i->second, E_NOT_EXIST );
    check_null( i->second->module, E_NOT_EXIST );

    code = i->second->module->stop();
    check_code( code, E_MODULE_START );
  }

  return E_OK;
}

