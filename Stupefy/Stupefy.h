/****************************************************************************/
/*  Stupefy.h                                                               */
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

/*==========  Core DIRECTORY  ==========*/
#include "Core/CoreCommon.h"
#include "Core/Defines.h"
#include "Core/Typedefs.h"

//MATH DIRECTORY
#include "Core/Math/MathFunctions.h"
#include "Core/Math/Matrix3.h"
#include "Core/Math/Quaternions.h"
#include "Core/Math/Vector2.h"
#include "Core/Math/Vector3.h"

/*==========  EDITOR DIRECTORY  ==========*/
//LOGGER DIRECTORY
#include "Editor/Logger/Logger.h"
#include "Editor/Logger/ColorBoy.h"

/*==========  MAIN DIRECTORY  ==========*/
#include "Main/MainApp.h"
#include "Main/EntryPoint.h"

/*==========  SYSTEMS DIRECTORY  ==========*/
//RENDERER DIRECTORY
#include "Systems/Renderer/IndexBuffer.h"
#include "Systems/Renderer/Renderer.h"
#include "Systems/Renderer/Shader.h"
#include "Systems/Renderer/Textures.h"
#include "Systems/Renderer/VertexArray.h"