/****************************************************************************/
/*  EntryPoint.h                                                            */
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

extern Stupefy::Application* Stupefy::CreateApplication();

int main(int argc,char* argv)
{
	Stupefy::Logger::Log("Initializing Stupefy Engine: v%d.0", 1);
	Stupefy::Logger::Trace("Checking Trace");
	Stupefy::Logger::Debug("Checking Debug");
	Stupefy::Logger::Warn("Checking Warn");
	Stupefy::Logger::Error("Checking Error");
	//Stupefy::Logger::Fatal("Checking Fatal");
	auto app = Stupefy::CreateApplication();
	app->Run();
	delete app;
}