//
//  main.cpp
//  learning
//
//  Created by losor on 3/16/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "loader.h"
#include "cmd.h"
#include "assertion.h"
#include "err_common.h"

int main(int argc, const char * argv[])
{
  long code;
  char *buf;
  std::ifstream file;
  loader *loader;
  cmd *cmd;
  xml_doc *xml;
  xml_tree *root;

  file.open( "config" );

  buf = new char[1024*1024*10+1];
  check_null( buf, E_ALLOCATE );
  file.read( buf, 1024*1024*10 );

  xml = new xml_doc();
  check_null( xml, E_ALLOCATE );
  xml->parse<0>( buf );

  root = xml->first_node();
  check_null( root, E_CONF );

  loader = new class loader();
  check_null( loader, E_ALLOCATE );
  
  code = loader->load( root );
  check_code( code, (int)code );
  loader->start();
  check_code( code, (int)code );

  cmd = new class cmd( loader );
  check_null( cmd, E_ALLOCATE );
  cmd->run();

  delete cmd;
  loader->stop();
  delete loader;
  delete buf;
  xml->clear();
  delete xml;
  
  return 0;
}

