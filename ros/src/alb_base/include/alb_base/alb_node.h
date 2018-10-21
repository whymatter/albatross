//
// Created by whymatter on 20.10.18.
//

#ifndef PROJECT_ALB_NODE_H
#define PROJECT_ALB_NODE_H

namespace alb {
    namespace base {
        class AlbNode {
        public:
            AlbNode();
            ~AlbNode();
            virtual void CyclicStep() = 0;
            virtual void RunCyclic() = 0;
            virtual void Initialize() = 0;
        };
    }
}

#endif //PROJECT_ALB_NODE_H
