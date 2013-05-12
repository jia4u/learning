//
//  bus.cpp
//  learning
//
//  Created by xiangyun.kongxy on 3/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "bus.h"
#include "conf/bus_conf.h"
#include "errdef.h"

bus::bus( adapter_manager *adapter )
{
  m_adapter = adapter;
}

bus::~bus()
{
  delete m_adapter;
}

void* bus::get_resource( uint64 res_id )
{
  return NULL;
}

void bus::set_depend( module *depend, uint64 module_id )
{
  adapter *adapter;
  adapter = m_adapter->query_adapter( module_id );

  if ( adapter != NULL )
    adapter->set_instance( (bus_compatible*)depend );

}

long bus::start()
{
  return 0;
}

long bus::pause()
{
  return 0;
}

long bus::stop()
{
  delete this;
  
  return 0;
}

long bus::push_message( const event &msg )
{
  adapter *adapter;
  adapter = m_adapter->query_adapter( msg.dst_module );

  if( adapter != NULL )
    return adapter->push_message( msg );

  return E_BUS_MODULE_NOT_FOUND;
}

long bus::push_request( const event &req, long timeout )
{
  adapter *adapter;
  adapter = m_adapter->query_adapter( req.dst_module );

  if( adapter != NULL )
    return adapter->push_request( req, timeout );

  return E_BUS_MODULE_NOT_FOUND;
}

long bus::push_response( const event &response, const event &src )
{
  adapter *adapter;
  adapter = m_adapter->query_adapter( response.dst_module );

  if( adapter != NULL )
    return adapter->push_response( response, src );
  
  return E_BUS_MODULE_NOT_FOUND;
}

extern "C" module* init_bus( const xml_tree *root )
{
  return bus_loader::load_bus_from_xml( root );
}

