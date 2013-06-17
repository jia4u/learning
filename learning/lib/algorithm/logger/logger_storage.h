//
//  logger_storage.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_storage__
#define __algorithm__logger_storage__

class logger_storage {

public:
  virtual long write( const char *log, long len = -1 ) = 0;

  virtual int  get_buffer_size() const = 0;
  virtual void set_buffer_size( int size ) = 0;

  virtual const char* type() = 0;
  
  virtual ~logger_storage(){}
};

#include "logger_storage_file.h"
#include "logger_storage_shm.h"

#endif /* defined(__algorithm__logger_storage__) */
