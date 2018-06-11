#include "TES3WorldControllerLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "NICamera.h"
#include "NINode.h"

#include "TES3GameSetting.h"
#include "TES3GlobalVariable.h"
#include "TES3InputController.h"
#include "TES3Script.h"
#include "TES3WeatherController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		void bindTES3WorldController() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::WorldControllerRenderCamera.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WorldControllerRenderCamera>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("renderer", sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return makeLuaObject(self.renderer); }));
				usertypeDefinition.set("root", sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return makeLuaObject(self.root); }));
				usertypeDefinition.set("cameraRoot", sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return makeLuaObject(self.cameraRoot); }));
				usertypeDefinition.set("camera", sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return makeLuaObject(self.camera); }));

				// Finish up our usertype.
				state.set_usertype("tes3worldControllerRenderCamera", usertypeDefinition);
			}

			// Binding for TES3::WorldController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WorldController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("aiDistance", &TES3::WorldController::aiDistance);
				usertypeDefinition.set("canQuickSaveAndRest", &TES3::WorldController::canUseQuickSaveAndRest);
				usertypeDefinition.set("characterRenderTarget", &TES3::WorldController::characterRenderTarget);
				usertypeDefinition.set("charGenState", &TES3::WorldController::gvarCharGenState);
				usertypeDefinition.set("countMusicTracksBattle", &TES3::WorldController::countMusicTracksBattle);
				usertypeDefinition.set("countMusicTracksExplore", &TES3::WorldController::countMusicTracksExplore);
				usertypeDefinition.set("cursorOff", &TES3::WorldController::cursorOff);
				usertypeDefinition.set("day", &TES3::WorldController::gvarDay);
				usertypeDefinition.set("daysPassed", &TES3::WorldController::gvarDaysPassed);
				usertypeDefinition.set("deadFloatScale", &TES3::WorldController::deadFloatScale);
				usertypeDefinition.set("deltaTime", &TES3::WorldController::deltaTime);
				usertypeDefinition.set("difficulty", &TES3::WorldController::difficulty);
				usertypeDefinition.set("flagEventMenuModeOff", &TES3::WorldController::flagEventMenuModeOff);
				usertypeDefinition.set("flagEventMenuModeOn", &TES3::WorldController::flagEventMenuModeOn);
				usertypeDefinition.set("flagLevitationDisabled", &TES3::WorldController::flagLevitationDisabled);
				usertypeDefinition.set("flagMenuMode", &TES3::WorldController::flagMenuMode);
				usertypeDefinition.set("flagTeleportingDisabled", &TES3::WorldController::flagTeleportingDisabled);
				usertypeDefinition.set("fogOfWarController", &TES3::WorldController::fogOfWarController);
				usertypeDefinition.set("helpDelay", &TES3::WorldController::helpDelay);
				usertypeDefinition.set("hour", &TES3::WorldController::gvarGameHour);
				usertypeDefinition.set("hudStyle", &TES3::WorldController::hudStyle);
				usertypeDefinition.set("inputController", &TES3::WorldController::inputController);
				usertypeDefinition.set("instance", &TES3::WorldController::Win32_hInstance);
				usertypeDefinition.set("lastFrameTime", &TES3::WorldController::lastFrameTimeMillis);
				usertypeDefinition.set("listAllActors", &TES3::WorldController::allActors);
				usertypeDefinition.set("listChargableItems", &TES3::WorldController::chargableItems);
				usertypeDefinition.set("lstGlobalScripts", &TES3::WorldController::globalScripts);
				usertypeDefinition.set("maxFPS", &TES3::WorldController::maxFPS);
				usertypeDefinition.set("menuAlpha", &TES3::WorldController::menuAlpha);
				usertypeDefinition.set("menuController", &TES3::WorldController::menuController);
				usertypeDefinition.set("month", &TES3::WorldController::gvarMonth);
				usertypeDefinition.set("monthsToRespawn", &TES3::WorldController::gvarMonthsToRespawn);
				usertypeDefinition.set("mouseSensitivityX", &TES3::WorldController::horzSensitivity);
				usertypeDefinition.set("mouseSensitivityY", &TES3::WorldController::mouseSensitivity);
				usertypeDefinition.set("musicState", &TES3::WorldController::musicState);
				usertypeDefinition.set("parentWindowHandle", &TES3::WorldController::Win32_hWndParent);
				usertypeDefinition.set("projectionDistance", &TES3::WorldController::projectionDistance);
				usertypeDefinition.set("scriptGlobals", &TES3::WorldController::scriptGlobals);
				usertypeDefinition.set("shaderWaterReflectTerrain", &TES3::WorldController::shaderWaterReflectsTerrain);
				usertypeDefinition.set("shaderWaterReflectUpdate", &TES3::WorldController::shaderWaterReflectUpdate);
				usertypeDefinition.set("shadows", &TES3::WorldController::bShadows);
				usertypeDefinition.set("showSubtitles", &TES3::WorldController::showSubtitles);
				usertypeDefinition.set("splashscreenCamera", &TES3::WorldController::splashscreenCamera);
				usertypeDefinition.set("stopGameLoop", &TES3::WorldController::stopGameLoop);
				usertypeDefinition.set("systemTime", &TES3::WorldController::systemTimeMillis);
				usertypeDefinition.set("timescale", &TES3::WorldController::gvarTimescale);
				usertypeDefinition.set("uiInventoryData", &TES3::WorldController::uiInventoryData);
				usertypeDefinition.set("useBestAttack", &TES3::WorldController::useBestAttack);
				usertypeDefinition.set("viewHeight", &TES3::WorldController::viewHeight);
				usertypeDefinition.set("viewWidth", &TES3::WorldController::viewWidth);
				usertypeDefinition.set("weatherController", &TES3::WorldController::weatherController);
				usertypeDefinition.set("werewolfFOV", &TES3::WorldController::werewolfFOV);
				usertypeDefinition.set("windowHandle", &TES3::WorldController::Win32_hWnd);
				usertypeDefinition.set("worldCamera", &TES3::WorldController::worldCamera);
				usertypeDefinition.set("year", &TES3::WorldController::gvarYear);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("nodeCursor", sol::readonly_property([](TES3::WorldController& self) { return makeLuaObject(self.nodeCursor); }));

				// Finish up our usertype.
				state.set_usertype("tes3worldController", usertypeDefinition);
			}
		}
	}
}
