//
//  logger_manager.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_manager.h"
#include "err_common.h"

logger_manager *logger_manager::m_manager = nullptr;

logger* logger_manager::get_logger( const char *name )
{
  logger * logger = m_loggers[name];

  if ( logger != NULL )
    logger->add_ref();

  return logger;
}

long logger_manager::add_logger( const char *name, class logger *logger )
{
  std::map<std::string, class logger*>::const_iterator i;
  i = m_loggers.find( name );
  if( i != m_loggers.end() )
    return E_EXISTED;

  m_loggers[name] = logger;

  return E_OK;
}

long logger_manager::delete_logger( const char *name )
{
  std::map<std::string, class logger*>::const_iterator i;
  i = m_loggers.find( name );
  if( i == m_loggers.end() )
    return E_NOT_EXIST;

  if ( i->second->get_ref() > 0 )
    return E_REF_COUNT_GREAT_THAN_0;

  delete i->second;
  m_loggers.erase( i );
  
  return E_OK;
}

logger_manager* logger_manager::get_instance()
{
  if ( m_manager == nullptr )
    m_manager = new logger_manager;

  return m_manager;
}
