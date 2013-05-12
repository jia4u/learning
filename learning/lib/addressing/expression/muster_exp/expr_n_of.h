//
//  expr_n_of.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __addressing__expr_n_of__
#define __addressing__expr_n_of__

#include "expression.h"

class expr_n_of : public expression {
protected:
  expression *m_muster;
  expression *m_number;

public:
  virtual ~expr_n_of();
  expr_n_of( expression *muster, expression *number );

  virtual enum operation operation() const;
  virtual expression* paramenter( int nth ) const;
  virtual expr_result* calculate( ) const;
};

#endif /* defined(__addressing__expr_n_of__) */
