//
//  log_storage_file.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/25/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__log_storage_file__
#define __algorithm__log_storage_file__

#include "logger_storage.h"

#include <fstream>

using namespace std;

class logger_storage_file : public logger_storage {

  char *m_buf;
  int m_buf_cap;
  int m_buf_remain;
  ofstream m_stream;

public:
  virtual long write( const char *log, long len = -1 );

  virtual int  get_buffer_size() const;
  virtual void set_buffer_size( int size );

  virtual const char* type();

  virtual ~logger_storage_file();
  logger_storage_file( const char *path );
};

#endif /* defined(__algorithm__log_storage_file__) */
