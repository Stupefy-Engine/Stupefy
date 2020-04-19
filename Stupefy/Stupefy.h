/****************************************************************************/
/*  Stupefy.h                                                             */
/****************************************************************************/
/*                          This file is a part of:                         */
/*                              STUPEFY ENGINE                              */
/*                                                                          */
/****************************************************************************/
/*  Copyright[2020] Harshit Bargujar                                        */
/*                                                                          */
/*  Licensed under the Apache License, Version 2.0 (the "License");         */
/*  you may not use this file except in compliance with the License.        */
/*  You may obtain a copy of the License at                                 */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/
/*  See the License for the specific language governing permissions and     */
/*  limitations under the License.                                          */
/****************************************************************************/


#pragma once

/*==========  CORE DIRECTORY  ==========*/
#include "core/core_common.h"
#include "core/defines.h"
#include "core/typedefs.h"

//MATH DIRECTORY
#include "core/math/math_functions.h"
#include "core/math/matrix3.h"
#include "core/math/quaternions.h"
#include "core/math/vector2.h"
#include "core/math/vector3.h"

/*==========  EDITOR DIRECTORY  ==========*/
//LOGGER DIRECTORY
#include "editor/logger/logger.h"

/*==========  MAIN DIRECTORY  ==========*/
#include "main/main_app.h"
#include "main/entrypoint.h"

/*==========  SYSTEMS DIRECTORY  ==========*/
//RENDERER DIRECTORY
#include "systems/renderer/indexbuffer.h"
#include "systems/renderer/renderer.h"
#include "systems/renderer/shader.h"
#include "systems/renderer/textures.h"
#include "systems/renderer/vertexarray.h"
