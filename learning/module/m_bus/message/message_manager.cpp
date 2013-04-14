//
//  message_manager.cpp
//  learning
//
//  Created by xiangyun.kongxy on 3/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "message_manager.h"
#include "errdef.h"

long message_manager::register_msg( const message &msg )
{
  if ( m_msg.end() != m_msg.find( msg.uuid ) )
    return E_BUS_MESSAGE_EXISTED;

  m_msg[ msg.uuid ] = msg;

  return E_OK;
}

long message_manager::unregister_msg( uint64 id )
{
  if ( m_msg.end() != m_msg.find( id ) ) {
    m_msg.erase( id );
    
    return E_OK;
  }

  return E_BUS_MESSAGE_NOT_EXIST;
}

long message_manager::query_msg( uint64 id, message &message )
{
  if ( m_msg.end() != m_msg.find( id ) ) {
    message = m_msg[id];
    
    return E_OK;
  }

  return E_BUS_MESSAGE_NOT_EXIST;
}
