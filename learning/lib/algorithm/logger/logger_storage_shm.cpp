//
//  log_storage_shm.cpp
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "logger_storage_shm.h"

long logger_storage_shm::write( const char *log, long len )
{
  return len;
}

int  logger_storage_shm::get_buffer_size() const
{
  return 0;
}

void logger_storage_shm::set_buffer_size( int size )
{

}

const char* logger_storage_shm::type()
{
  return "shm";
}

logger_storage_shm::~logger_storage_shm()
{

}

logger_storage_shm::logger_storage_shm( const char *path )
{

}
