//
//  adapter.cpp
//  learning
//
//  Created by xiangyun.kongxy on 3/28/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "adapter.h"
#include "errdef.h"

adapter::adapter( int64 uuid, message_manager *cap )
{
  m_uuid = uuid;
  m_cap = cap;
  m_instance = NULL;
}

adapter::~adapter()
{
  if ( m_cap != NULL ) 
    delete m_cap;
  
}

uint64 adapter::uuid() const
{
  return m_uuid;
}

message_manager* adapter::get_capacity( ) const
{
  return m_cap;
}

bus_compatible* adapter::get_instance( ) const
{
  return m_instance;
}

void adapter::set_instance( bus_compatible *instance )
{
  m_instance = instance;
}

long adapter::push_message( const event &msg )
{
  if ( m_instance != NULL )
    return m_instance->push_message( msg );

  return E_BUS_ADAPTER_HAS_NO_INSTANCE;
}

long adapter::push_request( const event &req, long timeout )
{
  if ( m_instance != NULL )
    return m_instance->push_request( req, timeout );

  return E_BUS_ADAPTER_HAS_NO_INSTANCE;
}

long adapter::push_response( const event &response, const event &src )
{
  if ( m_instance != NULL )
    return m_instance->push_response( response, src );

  return E_BUS_ADAPTER_HAS_NO_INSTANCE;
}
