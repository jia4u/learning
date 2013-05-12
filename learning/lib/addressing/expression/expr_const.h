//
//  expr_const.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef addressing_expr_const_h
#define addressing_expr_const_h

#include "expression.h"

class expr_const_number : public expression {
protected:
  int64 m_number;

public:
  virtual ~expr_const_number();
  expr_const_number( int64 number );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

class expr_const_string : public expression {
protected:
  const char *m_string;

public:
  virtual ~expr_const_string();
  expr_const_string( const char *string );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

class expr_const_all : public expression {

public:
  virtual ~expr_const_all();

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

class expr_const_cur : public expression {

public:
  virtual ~expr_const_cur();

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

class expr_const_rest : public expression {

public:
  virtual ~expr_const_rest();

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif
