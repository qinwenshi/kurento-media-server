/*
 * (C) Copyright 2013 Kurento (http://kurento.org/)
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

#include "utils.hpp"

#include "KmsMediaErrorCodes_constants.h"

namespace kurento
{


KmsMediaServerException
createKmsMediaServerException (std::string description)
{
  KmsMediaServerException mse = KmsMediaServerException ();
  mse.__set_errorCode (g_KmsMediaErrorCodes_constants.MEDIA_ERROR);
  mse.__set_description (description);

  return mse;
}

KmsMediaServerException
createKmsMediaServerException (int errorCode, std::string description)
{
  KmsMediaServerException mse = KmsMediaServerException ();
  mse.__set_errorCode (errorCode);
  mse.__set_description (description);

  return mse;
}

} // kurento