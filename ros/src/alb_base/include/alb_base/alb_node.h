//
// Created by whymatter on 20.10.18.
//

#pragma once

#include <string>
#include <boost/function.hpp>

namespace alb {
    namespace base {
        template<class T>
        class AlbNode {
        public:
            explicit AlbNode(T &nodeHandle)
                    : nodeHandle_{nodeHandle} {

            }

            virtual ~AlbNode() = default;

            void RunCyclic() {
                while (!this->nodeHandle_.Abort()) {
                    this->CyclicStep();
                    this->nodeHandle_.InternalCyclicStep();
                }
            }

            virtual void CyclicStep() = 0;

            virtual void Initialize() = 0;

            template<typename M>
            typename T::template Publisher<M>
            Advertise(std::string topicName, uint32_t queueSize = 1) {
                return this->nodeHandle_.template Advertise<M>(topicName, queueSize);
            }

            template<typename M>
            typename T::Subscriber
            Subscribe(std::string topicName, const boost::function<void (const boost::shared_ptr<M const>&)>& callback, uint32_t queueSize = 1) {
                return this->nodeHandle_.template Subscribe<M>(topicName, callback, queueSize);
            }


        protected:
            T &nodeHandle_;
        };
    }
}
