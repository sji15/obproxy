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

#ifndef OBPROXY_SESSION_ACCEPT_H
#define OBPROXY_SESSION_ACCEPT_H

#include "iocore/eventsystem/ob_vconnection.h"
#include "iocore/net/ob_net_def.h"

namespace oceanbase
{
namespace obproxy
{
namespace net
{

class ObSessionAccept : public event::ObContinuation
{
public:
  explicit ObSessionAccept(event::ObProxyMutex *amutex) : event::ObContinuation(amutex)
  {
    SET_HANDLER(&ObSessionAccept::main_event);
  }

  virtual ~ObSessionAccept() { }

  virtual int accept(ObNetVConnection *vc, event::ObMIOBuffer *mio,
                     event::ObIOBufferReader *r) = 0;

private:
  virtual int main_event(int event, void *netvc) = 0;
};

} // end of namespace net
} // end of namespace obproxy
} // end of namespace oceanbase

#endif // OBPROXY_SESSION_ACCEPT_H
