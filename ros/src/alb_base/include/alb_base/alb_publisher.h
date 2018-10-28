//
// Created by whymatter on 21.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_ALB_PUBLISHER_H
#define CAM_DIRECT_CAPTURE_ALB_PUBLISHER_H

#include <boost/shared_ptr.hpp>

namespace alb {
    namespace base {
        template<class T>
        class AlbPublisher {
        public:
            AlbPublisher() = default;

            AlbPublisher(const AlbPublisher<T> &other) = default; // think about it first
            ~AlbPublisher() = default;

            virtual void Publish(const T &message) = 0;

            virtual void Publish(const ::boost::shared_ptr<T> &message) = 0;
        };
    }
}

#endif //CAM_DIRECT_CAPTURE_ALB_PUBLISHER_H
