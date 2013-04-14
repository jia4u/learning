//
//  loader.cpp
//  learning
//
//  Created by xiangyun.kongxy on 4/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "loader.h"
#include "err_common.h"

module_loader::~module_loader()
{
  if ( m_module != NULL )
    delete m_module;
}

long module_loader::load( xml_tree *root )
{
  m_module = loader_conf::load_modules_from_conf( root );

  if( m_module != NULL )
    return E_OK;
  else
    return E_CONF;
}

long module_loader::start()
{

  return E_OK;
}

long module_loader::pause()
{
  return E_OK;
}

long module_loader::stop()
{
  return E_OK;
}

long module_loader::pause( uint64 module_id )
{
  module_info *info;

  if ( m_module != NULL ) {
    info = m_module->query_module( module_id );
    
    if( info != NULL && info->module != NULL )
      return info->module->pause();
    else
      return E_MODULE_NOT_EXIST;
  }
  else
  {
    return E_NOT_READY;
  }
}

long module_loader::stop( uint64 module_id )
{
  module_info *info;

  if ( m_module != NULL ) {
    info = m_module->query_module( module_id );
    
    if( info != NULL && info->module != NULL )
      return info->module->pause();
    else
      return E_MODULE_NOT_EXIST;
  }
  else
  {
    return E_NOT_READY;
  }
}

