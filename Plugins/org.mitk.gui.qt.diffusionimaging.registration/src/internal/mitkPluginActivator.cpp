/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#include "mitkPluginActivator.h"

#include "src/internal/QmitkDiffusionRegistrationView.h"
#include "src/internal/QmitkSimpleRigidRegistrationView.h"
#include "src/internal/QmitkDwiRegistrationPerspective.h"


ctkPluginContext* mitk::PluginActivator::m_Context = nullptr;

ctkPluginContext* mitk::PluginActivator::GetContext()
{
  return m_Context;
}

void mitk::PluginActivator::start(ctkPluginContext* context)
{
  BERRY_REGISTER_EXTENSION_CLASS(QmitkDiffusionRegistrationView, context)
  BERRY_REGISTER_EXTENSION_CLASS(QmitkSimpleRigidRegistrationView, context)
  BERRY_REGISTER_EXTENSION_CLASS(QmitkDwiRegistrationPerspective, context)
  m_Context = context;
}

void mitk::PluginActivator::stop(ctkPluginContext* context)
{
  Q_UNUSED(context)
  m_Context = nullptr;
}
