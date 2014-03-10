/*
 * (C) Copyright 2014 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#include "DispatcherImpl.hpp"
#include "MediaPipelineImpl.hpp"
#include "HubPortImpl.hpp"

#define GST_CAT_DEFAULT kurento_dispatcher_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "KurentoDispatcherImpl"

#define FACTORY_NAME "dispatcher"

namespace kurento
{

DispatcherImpl::DispatcherImpl (
  std::shared_ptr<MediaObjectImpl> parent,
  int garbagePeriod) :
  HubImpl (FACTORY_NAME, parent, garbagePeriod)
{
}

std::shared_ptr<MediaObject>
Dispatcher::Factory::createObject (std::shared_ptr<MediaPipeline>
                                   parent,
                                   int garbagePeriod)
{
  std::shared_ptr <MediaObject> obj (new DispatcherImpl (
                                       std::dynamic_pointer_cast<MediaObjectImpl> (parent), garbagePeriod) );

  return obj;
}

DispatcherImpl::StaticConstructor
DispatcherImpl::staticConstructor;

DispatcherImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

} /* kurento */