//
//  adapter_manager.cpp
//  learning
//
//  Created by xiangyun.kongxy on 3/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "adapter_manager.h"
#include "errdef.h"

adapter_manager::~adapter_manager()
{
  std::map<uint64, adapter*>::iterator i;

  while ( m_adapter.size() > 0 )
    remove_adapter( m_adapter[0]->uuid() );
  
}

long adapter_manager::add_adapter( adapter *adapter )
{
  if ( m_adapter.end() != m_adapter.find( adapter->uuid() ) )
    return E_BUS_ADAPTER_EXISTED;

  m_adapter[adapter->uuid()] = adapter;

  return E_OK;
}

long adapter_manager::remove_adapter( uint64 id )
{
  if ( m_adapter.end() != m_adapter.find( id ))
    return E_BUS_ADAPTER_NOT_EXIST;

  m_adapter.erase( id );

  return E_OK;
}

adapter* adapter_manager::query_adapter( uint64 id )
{
  return m_adapter[id];
}
