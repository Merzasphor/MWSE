#include "TES3WorldControllerLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NICamera.h"
#include "NINode.h"

#include "TES3AudioController.h"
#include "TES3Fader.h"
#include "TES3GameSetting.h"
#include "TES3GlobalVariable.h"
#include "TES3InputController.h"
#include "TES3Script.h"
#include "TES3Sound.h"
#include "TES3UIMenuController.h"
#include "TES3WeatherController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		void bindTES3WorldController() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::WorldControllerRenderCamera.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WorldControllerRenderCamera>("tes3worldControllerRenderCamera");
				usertypeDefinition["new"] = sol::no_constructor;

				// Access to other objects that need to be packaged.
				usertypeDefinition["renderer"] = sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return self.renderer; });
				usertypeDefinition["root"] = sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return self.root; });
				usertypeDefinition["cameraRoot"] = sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return self.cameraRoot; });

				// Legacy support for substructures.
				usertypeDefinition["camera"] = sol::readonly_property([](TES3::WorldControllerRenderCamera& self) { return self.cameraData.camera; });
			}

			// Binding for TES3::WorldController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WorldController>("tes3worldController");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["activeQuests"] = &TES3::WorldController::journalController;
				usertypeDefinition["aiDistance"] = &TES3::WorldController::aiDistance;
				usertypeDefinition["armCamera"] = &TES3::WorldController::armCamera;
				usertypeDefinition["audioController"] = sol::readonly_property(&TES3::WorldController::audioController);
				usertypeDefinition["blindnessFader"] = sol::readonly_property(&TES3::WorldController::blindnessFader);
				usertypeDefinition["canQuickSaveAndRest"] = &TES3::WorldController::canUseQuickSaveAndRest;
				usertypeDefinition["characterRenderTarget"] = &TES3::WorldController::characterRenderTarget;
				usertypeDefinition["charGenState"] = &TES3::WorldController::gvarCharGenState;
				usertypeDefinition["countMusicTracksBattle"] = &TES3::WorldController::countMusicTracksBattle;
				usertypeDefinition["countMusicTracksExplore"] = &TES3::WorldController::countMusicTracksExplore;
				usertypeDefinition["cursorOff"] = &TES3::WorldController::cursorOff;
				usertypeDefinition["day"] = &TES3::WorldController::gvarDay;
				usertypeDefinition["daysPassed"] = &TES3::WorldController::gvarDaysPassed;
				usertypeDefinition["deadFloatScale"] = &TES3::WorldController::deadFloatScale;
				usertypeDefinition["deltaTime"] = &TES3::WorldController::deltaTime;
				usertypeDefinition["difficulty"] = &TES3::WorldController::difficulty;
				usertypeDefinition["enchantedItemEffect"] = &TES3::WorldController::enchantedItemEffect;
				usertypeDefinition["enchantedItemEffectCreated"] = &TES3::WorldController::enchantedItemEffectCreated;
				usertypeDefinition["enchantedItemEffectTextures"] = &TES3::WorldController::enchantedItemEffectTextures;
				usertypeDefinition["flagEventMenuModeOff"] = &TES3::WorldController::flagEventMenuModeOff;
				usertypeDefinition["flagEventMenuModeOff"] = &TES3::WorldController::flagEventMenuModeOff;
				usertypeDefinition["flagEventMenuModeOn"] = &TES3::WorldController::flagEventMenuModeOn;
				usertypeDefinition["flagLevitationDisabled"] = &TES3::WorldController::flagLevitationDisabled;
				usertypeDefinition["flagMenuMode"] = &TES3::WorldController::flagMenuMode;
				usertypeDefinition["flagTeleportingDisabled"] = &TES3::WorldController::flagTeleportingDisabled;
				usertypeDefinition["fogOfWarController"] = &TES3::WorldController::fogOfWarController;
				usertypeDefinition["helpDelay"] = &TES3::WorldController::helpDelay;
				usertypeDefinition["hitFader"] = sol::readonly_property(&TES3::WorldController::hitFader);
				usertypeDefinition["hour"] = &TES3::WorldController::gvarGameHour;
				usertypeDefinition["hudStyle"] = &TES3::WorldController::hudStyle;
				usertypeDefinition["inputController"] = &TES3::WorldController::inputController;
				usertypeDefinition["instance"] = &TES3::WorldController::Win32_hInstance;
				usertypeDefinition["inventoryData"] = &TES3::WorldController::inventoryData;
				usertypeDefinition["lastFrameTime"] = &TES3::WorldController::lastFrameTimeMillis;
				usertypeDefinition["listAllActors"] = &TES3::WorldController::allActors;
				usertypeDefinition["listChargableItems"] = &TES3::WorldController::chargableItems;
				usertypeDefinition["lstGlobalScripts"] = &TES3::WorldController::globalScripts;
				usertypeDefinition["maxFPS"] = &TES3::WorldController::maxFPS;
				usertypeDefinition["menuAlpha"] = &TES3::WorldController::menuAlpha;
				usertypeDefinition["menuCamera"] = &TES3::WorldController::menuCamera;
				usertypeDefinition["menuController"] = &TES3::WorldController::menuController;
				usertypeDefinition["month"] = &TES3::WorldController::gvarMonth;
				usertypeDefinition["monthsToRespawn"] = &TES3::WorldController::gvarMonthsToRespawn;
				usertypeDefinition["mouseSensitivityX"] = &TES3::WorldController::horzSensitivity;
				usertypeDefinition["mouseSensitivityY"] = &TES3::WorldController::mouseSensitivity;
				usertypeDefinition["musicSituation"] = &TES3::WorldController::musicSituation;
				usertypeDefinition["parentWindowHandle"] = &TES3::WorldController::Win32_hWndParent;
				usertypeDefinition["projectionDistance"] = &TES3::WorldController::projectionDistance;
				usertypeDefinition["scriptGlobals"] = &TES3::WorldController::scriptGlobals;
				usertypeDefinition["shaderWaterReflectTerrain"] = &TES3::WorldController::shaderWaterReflectsTerrain;
				usertypeDefinition["shaderWaterReflectUpdate"] = &TES3::WorldController::shaderWaterReflectUpdate;
				usertypeDefinition["shadowCamera"] = &TES3::WorldController::shadowCamera;
				usertypeDefinition["shadows"] = &TES3::WorldController::bShadows;
				usertypeDefinition["showSubtitles"] = &TES3::WorldController::showSubtitles;
				usertypeDefinition["splashscreenCamera"] = &TES3::WorldController::splashscreenCamera;
				usertypeDefinition["stopGameLoop"] = &TES3::WorldController::stopGameLoop;
				usertypeDefinition["sunglareFader"] = sol::readonly_property(&TES3::WorldController::sunglareFader);
				usertypeDefinition["systemTime"] = &TES3::WorldController::systemTimeMillis;
				usertypeDefinition["timescale"] = &TES3::WorldController::gvarTimescale;
				usertypeDefinition["transitionFader"] = sol::readonly_property(&TES3::WorldController::transitionFader);
				usertypeDefinition["useBestAttack"] = &TES3::WorldController::useBestAttack;
				usertypeDefinition["viewHeight"] = &TES3::WorldController::viewHeight;
				usertypeDefinition["viewWidth"] = &TES3::WorldController::viewWidth;
				usertypeDefinition["weatherController"] = &TES3::WorldController::weatherController;
				usertypeDefinition["werewolfFader"] = sol::readonly_property(&TES3::WorldController::werewolfFader);
				usertypeDefinition["werewolfFOV"] = &TES3::WorldController::werewolfFOV;
				usertypeDefinition["windowHandle"] = &TES3::WorldController::Win32_hWnd;
				usertypeDefinition["worldCamera"] = &TES3::WorldController::worldCamera;
				usertypeDefinition["year"] = &TES3::WorldController::gvarYear;

				// Access to other objects that need to be packaged.
				usertypeDefinition["criticalDamageSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundCriticalDamage; });
				usertypeDefinition["defaultLandSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundDefaultLand; });
				usertypeDefinition["defaultLandWaterSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundDefaultLandWater; });
				usertypeDefinition["drowningDamageSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundDrowningDamage; });
				usertypeDefinition["drownSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundDrown; });
				usertypeDefinition["handToHandHit2Sound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundHandToHandHit2; });
				usertypeDefinition["handToHandHitSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundHandToHandHit; });
				usertypeDefinition["healthDamageSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundHealthDamage; });
				usertypeDefinition["heavyArmorHitSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundHeavyArmorHit; });
				usertypeDefinition["itemRepairSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundItemRepair; });
				usertypeDefinition["lightArmorHitSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundLightArmorHit; });
				usertypeDefinition["mediumArmorHitSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundMediumArmorHit; });
				usertypeDefinition["menuClickSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundMenuClick; });
				usertypeDefinition["menuSizeSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundMenuSize; });
				usertypeDefinition["missSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundMiss; });
				usertypeDefinition["nodeCursor"] = sol::readonly_property([](TES3::WorldController& self) { return self.nodeCursor; });
				usertypeDefinition["weaponSwishSound"] = sol::readonly_property([](TES3::WorldController& self) { return self.soundWeaponSwish; });

				// Basic function binding.
				usertypeDefinition["applyEnchantEffect"] = &TES3::WorldController::applyEnchantEffect;
			}
		}
	}
}
