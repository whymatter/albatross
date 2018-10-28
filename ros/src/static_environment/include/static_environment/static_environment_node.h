//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_STATIC_ENVIRONMENT_NODE_H
#define PROJECT_STATIC_ENVIRONMENT_NODE_H

#include "alb_base/alb_node.h"

namespace alb {
 namespace static_environment {
  template<class TNode>
  class StaticEnvironmentNode : public alb::base::AlbNode<TNode> {
  public:
      explicit StaticEnvironmentNode(TNode &nodeHandle) : alb::base::AlbNode<TNode>(nodeHandle) {

      }

      void Initilaize() override {}

      void CyclicStep() override {}
  };
 }
}

#endif //PROJECT_STATIC_ENVIRONMENT_NODE_H
