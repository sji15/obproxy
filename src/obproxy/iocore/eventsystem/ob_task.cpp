/**
 * Copyright (c) 2021 OceanBase
 * OceanBase Database Proxy(ODP) is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#define USING_LOG_PREFIX PROXY_EVENT

#include "iocore/eventsystem/ob_event_system.h"

using namespace oceanbase::common;

namespace oceanbase
{
namespace obproxy
{
namespace event
{
ObEventThreadType ET_TASK = ET_CALL;
ObTasksProcessor g_task_processor;

// Note that if the number of task_threads is 0, all continuations scheduled for
// ET_TASK ends up running on ET_CALL (which is the net-threads).
int ObTasksProcessor::start(const int64_t task_threads, const int64_t stacksize)
{
  int ret = OB_SUCCESS;
  if (OB_FAIL(g_event_processor.spawn_event_threads(task_threads, "ET_TASK", stacksize, ET_TASK))) {
    LOG_WARN("fail to spawn event threads for ET_TASK", K(ret));
  }
  return ret;
}
} // end of namespace event
} // end of namespace obproxy
} // end of namespace oceanbase
