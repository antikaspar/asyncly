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

#include <memory>

#include "asyncly/ExecutorTypes.h"
#include "asyncly/task/Cancelable.h"
#include "asyncly/task/Task.h"

namespace asyncly {

typedef std::function<clock_type::time_point()> ClockNowFunction;

class IScheduler {
  public:
    virtual ~IScheduler() = default;
    virtual clock_type::time_point now() const = 0;
    virtual std::shared_ptr<Cancelable>
    execute_at(const IExecutorWPtr& executor, const clock_type::time_point& absTime, Task&&) = 0;
    virtual std::shared_ptr<Cancelable>
    execute_after(const IExecutorWPtr& executor, const clock_type::duration& relTime, Task&&) = 0;
};
} // namespace asyncly
