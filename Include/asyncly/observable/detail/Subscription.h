/*
 * Copyright 2019 LogMeIn
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "asyncly/observable/Subscription.h"

#include "asyncly/observable/detail/SharedSubscriptionContext.h"

namespace asyncly::detail {

template <typename T> class Subscription : public asyncly::Subscription::Unsubscribable {
  public:
    Subscription(const std::shared_ptr<detail::SharedSubscriptionContext<T>>& context);
    void cancel() override;

  private:
    std::shared_ptr<detail::SharedSubscriptionContext<T>> context;
};

template <typename T> void Subscription<T>::cancel()
{
    if (context == nullptr) {
        return;
    }

    context->onSubscriptionCancelled();
    context.reset();
}

template <typename T>
Subscription<T>::Subscription(const std::shared_ptr<detail::SharedSubscriptionContext<T>>& ccontext)
    : context{ ccontext }
{
}
} // namespace asyncly::detail
