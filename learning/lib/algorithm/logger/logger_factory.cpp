//
//  logger_factory.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_factory.h"
#include "logger_loader.h"

logger* logger_factory::get_logger( const char *name )
{
  logger_manager *manager;
  manager = logger_manager::get_instance();
  
  return manager->get_logger( name );
}

logger* logger_factory::get_Logger( logger_type type, const char *path )
{
  logger_manager *manager;
  logger *logger;
  logger = new class logger( path, type );
  manager = logger_manager::get_instance();

  logger->add_ref();
  manager->add_logger( path, logger );

  return logger;
}

void logger_factory::load_logger_from_xml( xml_tree *root )
{
  logger_loader::load_loggers( root );
}
