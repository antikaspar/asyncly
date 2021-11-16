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

#include "asyncly/executor/CurrentExecutor.h"

#include <memory>

namespace asyncly {

class IExecutor;

namespace detail {

class TaskCurrentExecutorGuard : public ICurrentExecutorWrapper {
  public:
    explicit TaskCurrentExecutorGuard(const std::weak_ptr<IExecutor>& executor);
    ~TaskCurrentExecutorGuard() override;
    std::shared_ptr<IExecutor> get_current_executor() override;

  private:
    const std::weak_ptr<asyncly::IExecutor>& executor_;
    asyncly::detail::ICurrentExecutorWrapper* last_executor_wrapper_rawptr_;
};
} // namespace detail
} // namespace asyncly
