#include "MGEUtilLua.h"

#include "MGEApi.h"
#include "MGEPostShaders.h"
#include "TES3Game.h"

#include "LuaManager.h"
#include "LuaUtil.h"
#include "Log.h"

namespace mwse::lua {

	//
	// Distant Land config struct.
	//

	void bindMGEDistantLandRenderConfig() {
		// Get our lua state.
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		// mge::DistantLandRenderConfig
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<mge::DistantLandRenderConfig>("mgeDistantLandRenderConfig");
			usertypeDefinition["new"] = sol::no_constructor;

			// Properties.
			usertypeDefinition["aboveWaterFogEnd"] = &mge::DistantLandRenderConfig::AboveWaterFogEnd;
			usertypeDefinition["aboveWaterFogStart"] = &mge::DistantLandRenderConfig::AboveWaterFogStart;
			usertypeDefinition["belowWaterFogEnd"] = &mge::DistantLandRenderConfig::BelowWaterFogEnd;
			usertypeDefinition["belowWaterFogStart"] = &mge::DistantLandRenderConfig::BelowWaterFogStart;
			usertypeDefinition["drawDist"] = &mge::DistantLandRenderConfig::DrawDist;
			usertypeDefinition["farStaticEnd"] = &mge::DistantLandRenderConfig::FarStaticEnd;
			usertypeDefinition["farStaticMinSize"] = &mge::DistantLandRenderConfig::FarStaticMinSize;
			usertypeDefinition["interiorFogEnd"] = &mge::DistantLandRenderConfig::InteriorFogEnd;
			usertypeDefinition["interiorFogStart"] = &mge::DistantLandRenderConfig::InteriorFogStart;
			usertypeDefinition["nearStaticEnd"] = &mge::DistantLandRenderConfig::NearStaticEnd;
			usertypeDefinition["fogOffsetDist"] = &mge::DistantLandRenderConfig::FogOffsetDist;
			usertypeDefinition["fogDist"] = &mge::DistantLandRenderConfig::FogDist;
			usertypeDefinition["veryFarStaticEnd"] = &mge::DistantLandRenderConfig::VeryFarStaticEnd;
			usertypeDefinition["veryFarStaticMinSize"] = &mge::DistantLandRenderConfig::VeryFarStaticMinSize;
			usertypeDefinition["waterCaustics"] = &mge::DistantLandRenderConfig::WaterCaustics;
			usertypeDefinition["waterReflect"] = &mge::DistantLandRenderConfig::WaterReflect;
			usertypeDefinition["waterWaveHeight"] = &mge::DistantLandRenderConfig::WaterWaveHeight;
			usertypeDefinition["wind"] = &mge::DistantLandRenderConfig::Wind;
			// Note that DistantLandRenderConfig::ShadowResolution does not appear, as it is not configurable.
		}
	}

	//
	// General functions.
	//

	auto mge_getVersion() {
		return mge::api->getMGEVersion();
	}

	auto mge_getLightingMode() {
		return int(mge::api->lightingModeGet());
	}

	auto mge_setLightingMode(sol::optional<sol::table> params) {
		auto mode = mge::LightingMode::Vertex;
		if (getOptionalParam<bool>(params, "interiorOnly", false)) {
			mode = mge::LightingMode::PerPixelInteriorOnly;
		}
		else if (getOptionalParam<bool>(params, "dynamic", false)) {
			mode = mge::LightingMode::PerPixelAll;
		}

		mge::api->lightingModeSet(mode);
	}

	auto mge_reloadDistantLand() {
		mge::api->reloadDistantLand();
	}

	//
	// HUD-related functions.
	//

	static std::string selectedHUDName;

	auto mge_resetHUD() {
		mge::api->hudReset();
	}

	auto mge_disableHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		mge::api->hudSetEnabled(hudName, false);
	}

	auto mge_enableHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		mge::api->hudSetEnabled(hudName, true);
	}

	auto mge_freeHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		mge::api->hudFree(hudName);
	}

	auto mge_fullscreenHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		mge::api->hudFullscreen(hudName);
	}

	auto mge_loadHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto texture = getOptionalParam<const char*>(params, "texture", nullptr);
		if (!hudName || !texture) {
			throw std::invalid_argument("hud or texture argument missing.");
		}

		mge::api->hudLoad(hudName, texture);

		if (getOptionalParam<bool>(params, "enable", false)) {
			mge::api->hudSetEnabled(hudName, true);
		}
	}

	auto mge_positionHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto x = getOptionalParam(params, "x", 0.0f);
		auto y = getOptionalParam(params, "y", 0.0f);
		mge::api->hudPosition(hudName, x, y);
	}

	auto mge_scaleHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto x = getOptionalParam(params, "x", 0.0f);
		auto y = getOptionalParam(params, "y", 0.0f);
		mge::api->hudScale(hudName, x, y);
	}

	auto mge_selectHUD(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		selectedHUDName = hudName;
	}

	auto mge_unselectHUD(sol::optional<sol::table> params) {
		selectedHUDName.clear();
	}

	auto mge_setHUDEffect(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto effect = getOptionalParam<const char*>(params, "effect", nullptr);

		if (!effect) {
			throw std::invalid_argument("effect argument missing.");
		}

		mge::api->hudSetEffect(hudName, effect);
	}

	auto mge_setHUDEffectFloat(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto variable = getOptionalParam<const char*>(params, "variable", nullptr);
		auto value = getOptionalParam<float>(params, "value");

		if (!value) {
			throw std::invalid_argument("value argument missing.");
		}

		mge::api->hudSetFloat(hudName, variable, value.value());
	}

	auto mge_setHUDEffectInt(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto variable = getOptionalParam<const char*>(params, "variable", nullptr);
		auto value = getOptionalParam<int>(params, "value");

		if (!value) {
			throw std::invalid_argument("value argument missing.");
		}

		mge::api->hudSetInt(hudName, variable, value.value());
	}

	auto mge_setHUDEffectVector4(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto variable = getOptionalParam<const char*>(params, "variable", nullptr);
		sol::table values = getOptionalParam<sol::table>(params, "value", sol::nil);

		if (values == sol::nil && values.size() != 4) {
			throw std::invalid_argument("value argument must be a length 4 array.");
		}

		float valueBuffer[4];
		for (size_t i = 0; i < 4; i++) {
			valueBuffer[i] = values[i];
		}
		mge::api->hudSetVector4(hudName, variable, valueBuffer);
	}

	auto mge_setHUDTexture(sol::optional<sol::table> params) {
		auto hudName = getOptionalParam<const char*>(params, "hud", nullptr);
		auto texture = getOptionalParam<const char*>(params, "texture", nullptr);
		if (!texture) {
			throw std::invalid_argument("texture argument missing.");
		}

		mge::api->hudSetTexture(hudName, texture);
	}

	//
	// Shader related functions.
	//

	sol::table mge_shaders(sol::this_state ts) {
		sol::state_view state(ts);
		sol::table shaders = state.create_table();

		for (size_t i = 0; true; i++) {
			auto s = mge::api->shaderListShaders(i);
			if (s) {
				shaders[i + 1] = mge::ShaderHandleLua(s);
			}
			else {
				break;
			}
		}

		return shaders;
	}

	std::string mge_shadersDebug(sol::this_state ts) {
		std::string out = "";
		for (size_t i = 0; true; i++) {
			auto s = mge::api->shaderListShaders(i);
			if (s) {
				char line[256];
				std::snprintf(line, sizeof(line), "%p %s\n", s, mge::api->shaderGetName(s));
				out += line;
			}
			else {
				break;
			}
		}

		return out;
	}

	sol::object mge_shaderFind(const char* id, sol::this_state ts) {
		if (id) {
			auto handle = mge::api->shaderGetShader(id);
			if (handle) {
				return sol::make_object(ts, mge::ShaderHandleLua(handle));
			}
		}
		return sol::nil;
	}

	sol::object mge_shaderLoad(sol::optional<sol::table> params, sol::this_state ts) {
		auto id = getOptionalParam<const char*>(params, "name", nullptr);

		if (id) {
			auto handle = mge::api->shaderLoad(id);
			if (handle) {
				return sol::make_object(ts, mge::ShaderHandleLua(handle));
			}
		}
		else {
			throw std::invalid_argument("shader argument missing.");
		}
		return sol::nil;
	}

	//
	// Camera-related functions.
	//

	auto mge_getFoV() {
		return mge::api->cameraGetFoV();
	}

	auto mge_setFoV(float fov) {
		mge::api->cameraSetFoV(fov);
	}

	auto mge_getThirdPersonOffset() {
		TES3::Vector3 offset;
		mge::api->cameraThirdPersonGetOffset(&offset.x);
		return offset;
	}

	auto mge_setThirdPersonOffset(sol::object param) {
		auto offset = param.as<TES3::Vector3*>();
		if (offset) {
			mge::api->cameraThirdPersonSetOffset(&offset->x);
		}
	}

	//
	// Zoom-related functions.
	//

	auto mge_getZoomEnabled() {
		return mge::api->zoomGetEnabled();
	}

	auto mge_setZoomEnabled(bool value) {
		mge::api->zoomSetEnabled(value);
	}

	auto mge_setZoom(float value) {
		mge::api->zoomSetZoom(value);
	}

	auto mge_getZoom() {
		return mge::api->zoomGetZoom();
	}

	auto mge_zoomIn(sol::optional<sol::table> params) {
		float amount = getOptionalParam<float>(params, "amount", 0.0625f);
		mge::api->zoomIn(amount);
	}

	auto mge_zoomOut(sol::optional<sol::table> params) {
		float amount = getOptionalParam<float>(params, "amount", 0.0625f);
		mge::api->zoomOut(amount);
	}

	auto mge_setZoomContinuous(sol::optional<sol::table> params) {
		float rate = getOptionalParam<float>(params, "rate", 1.0f);
		float targetRate = getOptionalParam<float>(params, "targetRate", rate);
		mge::api->zoomSetZoomContinuous(rate, targetRate);
	}

	auto mge_stopZoom() {
		mge::api->zoomStop();
	}

	auto mge_getCameraShakeEnabled() {
		return mge::api->cameraShakeGetEnabled();
	}

	auto mge_setCameraShakeEnabled(bool value) {
		mge::api->cameraShakeSetEnabled(value);
	}

	auto mge_getCameraShakeMagnitude(float value) {
		return mge::api->cameraShakeGetMagnitude();
	}

	auto mge_setCameraShakeMagnitude(float value) {
		mge::api->cameraShakeSetMagnitude(value);
	}

	auto mge_getCameraShakeAcceleration(float value) {
		return mge::api->cameraShakeGetAcceleration();
	}

	auto mge_setCameraShakeAcceleration(float value) {
		mge::api->cameraShakeSetAcceleration(value);
	}

	//
	// Other MGE XE rendering functions.
	//

	auto mge_setWeatherScattering(sol::optional<sol::table> params) {
		auto inscatter = getOptionalParamVector3(params, "inscatter");
		auto outscatter = getOptionalParamVector3(params, "outscatter");

		if (inscatter && outscatter) {
			mge::api->weatherScatteringSet(&inscatter.value().x, &outscatter.value().x);
			return true;
		}
		else {
			throw std::invalid_argument("inscatter and outscatter must be 3-vectors.");
		}
		return false;
	}

	auto mge_getWeatherScattering(sol::this_state ts) {
		float inscatter[3], outscatter[3];
		mge::api->weatherScatteringGet(inscatter, outscatter);

		sol::state_view state = ts;
		sol::table in = state.create_table_with(1, inscatter[0], 2, inscatter[1], 3, inscatter[2]);
		sol::table out = state.create_table_with(1, outscatter[0], 2, outscatter[1], 3, outscatter[2]);
		sol::table scattering = state.create_table_with("inscatter", in, "outscatter", out);
		return scattering;
	}

	auto mge_getWeatherDLFog(int weatherID, sol::this_state ts) {
		float fogDistMult, fogOffset;
		mge::api->weatherDistantFogGet(weatherID, &fogDistMult, &fogOffset);

		sol::state_view state = ts;
		return state.create_table_with("distance", fogDistMult, "offset", fogOffset);
	}

	auto mge_setWeatherDLFog(sol::optional<sol::table> params) {
		auto weatherID = getOptionalParam<int>(params, "weather", -1);
		auto fogDistMult = getOptionalParam<float>(params, "distance", -1.0f);
		auto fogOffset = getOptionalParam<float>(params, "offset", -1.0f);

		if (weatherID < 0) {
			throw std::invalid_argument("weather parameter required.");
		}
		if (fogDistMult < 0) {
			throw std::invalid_argument("distance parameter required.");
		}
		if (fogOffset < 0) {
			throw std::invalid_argument("offset parameter required.");
		}

		mge::api->weatherDistantFogSet(weatherID, fogDistMult, fogOffset);
	}

	auto mge_getWeatherPPLLight(int weatherID, sol::this_state ts) {
		float sunMult, ambMult;
		mge::api->weatherPerPixelLightGet(weatherID, &sunMult, &ambMult);

		sol::state_view state = ts;
		return state.create_table_with("sun", sunMult, "ambient", ambMult);
	}

	auto mge_setWeatherPPLLight(sol::optional<sol::table> params) {
		auto weatherID = getOptionalParam<int>(params, "weather", -1);
		auto sunMult = getOptionalParam<float>(params, "sun", -1.0f);
		auto ambMult = getOptionalParam<float>(params, "ambient", -1.0f);

		if (weatherID < 0) {
			throw std::invalid_argument("weather parameter required.");
		}
		if (sunMult < 0) {
			throw std::invalid_argument("sun parameter required.");
		}
		if (ambMult < 0) {
			throw std::invalid_argument("ambient parameter required.");
		}

		mge::api->weatherPerPixelLightSet(weatherID, sunMult, ambMult);
	}

	auto mge_getWeatherDLFog_legacy(int weatherID) {
		float fogDistMult, fogOffset;
		mge::api->weatherDistantFogGet(weatherID, &fogDistMult, &fogOffset);
		return std::make_tuple(fogDistMult, fogOffset);
	}

	auto mge_setWeatherDLFog_legacy(int weatherID, float fogDistMult, float fogOffset) {
		mge::api->weatherDistantFogSet(weatherID, fogDistMult, fogOffset);
	}

	auto mge_getWeatherPPLLight_legacy(int weatherID) {
		float sunMult, ambMult;
		mge::api->weatherPerPixelLightGet(weatherID, &sunMult, &ambMult);
		return std::make_tuple(sunMult, ambMult);
	}

	auto mge_setWeatherPPLLight_legacy(int weatherID, float sunMult, float ambMult) {
		mge::api->weatherPerPixelLightSet(weatherID, sunMult, ambMult);
	}

	//
	// Expose it all to lua.
	//

	bool isMGEAPIAvailable() {
		return mge::api != nullptr;
	}

	void bindMGEUtil() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		sol::table lua_mge = state["mge"];

		// General functions.
		lua_mge["getVersion"] = mge_getVersion;

		// Distant land functions.
		bindMGEDistantLandRenderConfig();
		lua_mge["distantLandRenderConfig"] = mge::api->getDistantLandRenderConfig();
		lua_mge["reloadDistantLand"] = mge_reloadDistantLand;

		lua_mge["getLightingMode"] = mge_getLightingMode;
		lua_mge["setLightingMode"] = mge_setLightingMode;

		// Rendering feature functions.
		struct MgeRenderFeatures {
			std::unordered_map <std::string, mge::RenderFeature> names;

			MgeRenderFeatures() {
				names["FPSCounter"] = mge::RenderFeature::FPSCounter;
				names["DisplayMessages"] = mge::RenderFeature::DisplayMessages;
				names["PauseRenderingInMenus"] = mge::RenderFeature::PauseRenderingInMenus;
				names["NoMWMGEBlending"] = mge::RenderFeature::NoMWMGEBlending;
				names["NoMWSunglare"] = mge::RenderFeature::NoMWSunglare;
				names["Shaders"] = mge::RenderFeature::Shaders;
				names["TransparencyAA"] = mge::RenderFeature::TransparencyAA;
				names["UpdateHDR"] = mge::RenderFeature::UpdateHDR;
				names["ExponentialFog"] = mge::RenderFeature::ExponentialFog;
				names["AtmosphericScattering"] = mge::RenderFeature::AtmosphericScattering;
				names["Grass"] = mge::RenderFeature::Grass;
				names["Shadows"] = mge::RenderFeature::Shadows;
				names["DistantWater"] = mge::RenderFeature::DistantWater;
				names["DistantLand"] = mge::RenderFeature::DistantLand;
				names["DistantStatics"] = mge::RenderFeature::DistantStatics;
				names["ReflectiveWater"] = mge::RenderFeature::ReflectiveWater;
				names["ReflectNear"] = mge::RenderFeature::ReflectNear;
				names["ReflectInterior"] = mge::RenderFeature::ReflectInterior;
				names["ReflectSky"] = mge::RenderFeature::ReflectSky;
				names["BlurReflections"] = mge::RenderFeature::BlurReflections;
				names["DynamicRipples"] = mge::RenderFeature::DynamicRipples;
				names["CrosshairAutoHide"] = mge::RenderFeature::CrosshairAutoHide;
			}

			sol::object get(const std::string& id, sol::this_state ts) const {
				auto it = names.find(id);
				if (it == names.end()) { return sol::nil; }

				return sol::make_object(ts, mge::api->featureGetEnabled(it->second));
			}

			void set(const std::string& id, bool value) const {
				auto it = names.find(id);
				if (it == names.end()) { return; }

				mge::api->featureSetEnabled(it->second, value);
			}
		};
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<MgeRenderFeatures>("mgeRenderFeatures");
			usertypeDefinition["new"] = sol::no_constructor;

			usertypeDefinition[sol::meta_function::index] = &MgeRenderFeatures::get;
			usertypeDefinition[sol::meta_function::new_index] = &MgeRenderFeatures::set;
		}
		lua_mge["render"] = MgeRenderFeatures();

		// Shader-related functions.
		struct MgeShadersConfig {};
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<MgeShadersConfig>("mgeShadersConfig");
			usertypeDefinition["new"] = sol::no_constructor;

			// Properties.
			usertypeDefinition["list"] = sol::readonly_property(&mge_shaders);
			usertypeDefinition["debug"] = sol::readonly_property(&mge_shadersDebug);

			// Functions.
			usertypeDefinition["find"] = &mge_shaderFind;
			usertypeDefinition["load"] = &mge_shaderLoad;
		}
		lua_mge["shaders"] = MgeShadersConfig();

		// Camera functions.
		struct MgeCameraConfig {};
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<MgeCameraConfig>("mgeCameraConfig");
			usertypeDefinition["new"] = sol::no_constructor;

			// Properties.
			usertypeDefinition["fov"] = sol::property(&mge_getFoV, &mge_setFoV);
			usertypeDefinition["shakeAcceleration"] = sol::property(&mge_getCameraShakeAcceleration, &mge_setCameraShakeAcceleration);
			usertypeDefinition["shakeEnable"] = sol::property(&mge_getCameraShakeEnabled, &mge_setCameraShakeEnabled);
			usertypeDefinition["shakeMagnitude"] = sol::property(&mge_getCameraShakeMagnitude, &mge_setCameraShakeMagnitude);
			usertypeDefinition["stopZoom"] = mge_stopZoom;
			usertypeDefinition["thirdPersonOffset"] = sol::property(&mge_getThirdPersonOffset, &mge_setThirdPersonOffset);
			usertypeDefinition["zoom"] = sol::property(&mge_getZoom, &mge_setZoom);
			usertypeDefinition["zoomContinuous"] = mge_setZoomContinuous;
			usertypeDefinition["zoomEnable"] = sol::property(&mge_getZoomEnabled, &mge_setZoomEnabled);
			usertypeDefinition["zoomIn"] = mge_zoomIn;
			usertypeDefinition["zoomOut"] = mge_zoomOut;
		}
		lua_mge["camera"] = MgeCameraConfig();

		// MGE XE weather functions.
		struct MgeWeatherConfig {};
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<MgeWeatherConfig>("mgeWeatherConfig");
			usertypeDefinition["new"] = sol::no_constructor;

			// Functions.
			usertypeDefinition["getDistantFog"] = &mge_getWeatherDLFog;
			usertypeDefinition["setDistantFog"] = &mge_setWeatherDLFog;
			usertypeDefinition["getPerPixelLighting"] = &mge_getWeatherPPLLight;
			usertypeDefinition["setPerPixelLighting"] = &mge_setWeatherPPLLight;
			usertypeDefinition["getScattering"] = &mge_getWeatherScattering;
			usertypeDefinition["setScattering"] = &mge_setWeatherScattering;
		}
		lua_mge["weather"] = MgeWeatherConfig();

		// Macro functions with on-screen notifications.
		sol::table lua_macros = state.create_table();
		lua_mge["macros"] = lua_macros;

		lua_macros["decreaseFOV"] = mge::macros->DecreaseFOV;
		lua_macros["decreaseViewRange"] = mge::macros->DecreaseViewRange;
		lua_macros["decreaseZoom"] = mge::macros->DecreaseZoom;
		lua_macros["disableMusic"] = mge::macros->DisableMusic;
		lua_macros["haggleLess1"] = mge::macros->HaggleLess1;
		lua_macros["haggleLess10"] = mge::macros->HaggleLess10;
		lua_macros["haggleLess100"] = mge::macros->HaggleLess100;
		lua_macros["haggleLess1000"] = mge::macros->HaggleLess1000;
		lua_macros["haggleLess10000"] = mge::macros->HaggleLess10000;
		lua_macros["haggleMore1"] = mge::macros->HaggleMore1;
		lua_macros["haggleMore10"] = mge::macros->HaggleMore10;
		lua_macros["haggleMore100"] = mge::macros->HaggleMore100;
		lua_macros["haggleMore1000"] = mge::macros->HaggleMore1000;
		lua_macros["haggleMore10000"] = mge::macros->HaggleMore10000;
		lua_macros["increaseFOV"] = mge::macros->IncreaseFOV;
		lua_macros["increaseViewRange"] = mge::macros->IncreaseViewRange;
		lua_macros["increaseZoom"] = mge::macros->IncreaseZoom;
		lua_macros["moveBack3PCam"] = mge::macros->MoveBack3PCam;
		lua_macros["moveDown3PCam"] = mge::macros->MoveDown3PCam;
		lua_macros["moveForward3PCam"] = mge::macros->MoveForward3PCam;
		lua_macros["moveLeft3PCam"] = mge::macros->MoveLeft3PCam;
		lua_macros["moveRight3PCam"] = mge::macros->MoveRight3PCam;
		lua_macros["moveUp3PCam"] = mge::macros->MoveUp3PCam;
		lua_macros["nextTrack"] = mge::macros->NextTrack;
		lua_macros["resetEnableZoom"] = mge::macros->ResetEnableZoom;
		lua_macros["showLastMessage"] = mge::macros->ShowLastMessage;
		lua_macros["takeScreenshot"] = mge::macros->TakeScreenshot;
		lua_macros["toggleBlending"] = mge::macros->ToggleBlending;
		lua_macros["toggleCrosshair"] = mge::macros->ToggleCrosshair;
		lua_macros["toggleDistantLand"] = mge::macros->ToggleDistantLand;
		lua_macros["toggleFpsCounter"] = mge::macros->ToggleFpsCounter;
		lua_macros["toggleGrass"] = mge::macros->ToggleGrass;
		lua_macros["toggleLightingMode"] = mge::macros->ToggleLightingMode;
		lua_macros["toggleShaders"] = mge::macros->ToggleShaders;
		lua_macros["toggleShadows"] = mge::macros->ToggleShadows;
		lua_macros["toggleStatusText"] = mge::macros->ToggleStatusText;
		lua_macros["toggleTransparencyAA"] = mge::macros->ToggleTransparencyAA;
		lua_macros["toggleZoom"] = mge::macros->ToggleZoom;

		// Legacy functions.
		lua_mge["getScreenHeight"] = []() { return TES3::Game::get()->windowHeight; };
		lua_mge["getScreenWidth"] = []() { return TES3::Game::get()->windowWidth; };
		lua_mge["getWeatherScattering"] = &mge_getWeatherScattering;
		lua_mge["setWeatherScattering"] = &mge_setWeatherScattering;
		lua_mge["getWeatherDLFog"] = &mge_getWeatherDLFog_legacy;
		lua_mge["setWeatherDLFog"] = &mge_setWeatherDLFog_legacy;
		lua_mge["getWeatherPPLLight"] = &mge_getWeatherPPLLight_legacy;
		lua_mge["setWeatherPPLLight"] = &mge_setWeatherPPLLight_legacy;
	}
}