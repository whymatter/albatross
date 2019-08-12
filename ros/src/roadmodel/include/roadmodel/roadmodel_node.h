//
// Created by whymatter on 10.08.19.
//

#pragma once

#include <boost/bind.hpp>

#include "alb_base/alb_node.h"

namespace alb {
 namespace roadmodel {
  template<class TNode>
  class RoadmodelNode : public alb::base::AlbNode<TNode> {
  public:
      explicit RoadmodelNode(TNode &nodeHandle)
              : alb::base::AlbNode<TNode>(nodeHandle) {

      }

      void Initialize() override {}

      void CyclicStep() override {}

  private:
  };
 }
}
