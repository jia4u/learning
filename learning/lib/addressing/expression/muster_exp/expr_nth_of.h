//
//  expr_nth_of.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __addressing__expr_nth_of__
#define __addressing__expr_nth_of__

#include "expression.h"

class expr_nth_of : public expression {
protected:
  expression *m_muster;
  expression *m_position;

public:
  virtual ~expr_nth_of();
  expr_nth_of( expression *muster, expression *position );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif /* defined(__addressing__expr_nth_of__) */
