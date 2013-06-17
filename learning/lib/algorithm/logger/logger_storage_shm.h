//
//  log_storage_shm.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__log_storage_shm__
#define __algorithm__log_storage_shm__

#include "logger_storage.h"

class logger_storage_shm : public logger_storage {

public:
  virtual long write( const char *log, long len = -1 );

  virtual int  get_buffer_size() const;
  virtual void set_buffer_size( int size );

  virtual const char* type();

  virtual ~logger_storage_shm();
  logger_storage_shm( const char *path );
};

#endif /* defined(__algorithm__log_storage_shm__) */
