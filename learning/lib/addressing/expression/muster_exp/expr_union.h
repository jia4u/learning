//
//  expr_union.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __addressing__expr_union__
#define __addressing__expr_union__

#include "expression.h"

class expr_union : public expression {
protected:
  expression *m_src;
  expression *m_dst;

public:
  virtual ~expr_union();
  expr_union( expression *src, expression *dst );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif /* defined(__addressing__expr_union__) */
