//
//  logger_field_file.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __algorithm__logger_field_file__
#define __algorithm__logger_field_file__

#include "logger_field.h"

const int MAX_LOG_LENGTH            = 10240;
const int MAX_PATH_LENGTH           = 1024;
const int MAX_FILE_LENGTH           = 144;
const int MAX_FILE_NAME_LENGTH      = 128;
const int MAX_FILE_EXT_LENGTH       = 16;

class logger_field_file : public logger_field {
protected:
    // %P%F%E
  char *m_format;
  
public:
  virtual const char* filter_text( const char *org );
  virtual const char* filter_text( long org );

  logger_field_file( const char *name = "file", char short_name = 'F',
                    bool enable_fixed_length = false, int fixed_length = 0,
                    const char *format = "%F%E" );
  virtual ~logger_field_file();
  logger_field_file& operator= ( const logger_field_file &field );

  const char* get_format() const;
  void set_format( const char *format );

protected:
  void parse_full_path( const char *fullpath,
                       char *buf_for_path, int buf_for_path_len,
                       char *buf_for_filename, int buf_for_filename_len,
                       char *buf_for_ext,  int buf_for_ext_len );
};

#endif /* defined(__algorithm__logger_field_file__) */
