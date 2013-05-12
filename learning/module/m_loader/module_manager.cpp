//
//  module_manager.cpp
//  learning
//
//  Created by xiangyun.kongxy on 4/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "module_manager.h"
#include "err_common.h"

module_manager::~module_manager()
{
  while ( m_module.size() > 0 )
    remove_module( m_module.begin()->first );
}

long module_manager::add_module( uint64 id, module_info *info )
{
  if ( m_module.find( id ) == m_module.end() ) {
    m_module[id] = info;
    return E_OK;
  }
  else {
    return E_MODULE_EXISTED;
  }
}

long module_manager::remove_module( uint64 id )
{
  std::map<uint64, module_info*>::const_iterator i;

  i = m_module.find( id );
  if ( i != m_module.end() ) {
    delete i->second->module;
    delete i->second->load_info;
    delete i->second;
    m_module.erase( i );

    return E_OK;
  }
  else {
    return E_MODULE_NOT_EXIST;
  }

}

module_info* module_manager::query_module( uint64 id )
{
  return m_module[id];
}

module_manager::const_iterator module_manager::begin() const
{
  return m_module.begin();
}

module_manager::const_iterator module_manager::end() const
{
  return m_module.end();
}
