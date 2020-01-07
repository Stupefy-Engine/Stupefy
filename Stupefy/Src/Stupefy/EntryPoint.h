/****************************************************************************/
/*  EntryPoint.h                                                            */
/****************************************************************************/
/*                          This file is a part of:                         */
/*                              STUPEFY ENGINE                              */
/*                                                                          */
/****************************************************************************/
/*  Copyright[2019] Harshit Bargujar , Sujay Kumar Suman                    */
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
/*  See the License for the specific language governing permissionsand      */
/*  limitations under the License.                                          */
/****************************************************************************/


#pragma once

#include "sfpch.h"

#ifdef SF_PLATFORM_WINDOWS

extern Stupefy::Application* Stupefy::CreateApplication();

int main(int argc, char** argv)
{
	Stupefy::Log::Init();
	SF_CORE_INFO("Initialized");
	SF_CLIENT_INFO("Hello! Welcome to Stupefy...");

	auto app = Stupefy::CreateApplication();
	app->Run();
	delete app;
}

#endif