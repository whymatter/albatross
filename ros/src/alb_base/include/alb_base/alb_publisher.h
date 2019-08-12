//
// Created by whymatter on 21.10.18.
//

#pragma once

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
