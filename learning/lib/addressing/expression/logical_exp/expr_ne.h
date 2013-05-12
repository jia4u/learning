//
//  expr_ne.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __addressing__expr_ne__
#define __addressing__expr_ne__

#include "expression.h"

class expr_ne : public expression {
protected:
  expression *m_src;
  expression *m_dst;

public:
  virtual ~expr_ne();
  expr_ne( expression *src, expression *dst );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif /* defined(__addressing__expr_ne__) */