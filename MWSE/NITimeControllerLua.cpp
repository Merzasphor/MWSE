#include "NITimeControllerLua.h"

#include "NIObjectLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NILookAtController.h"
#include "NIKeyframeController.h"
#include "NITimeController.h"

namespace mwse::lua {
	template <typename T>
	void setUserdataForNITimeController(sol::usertype<T>& usertypeDefinition) {
		setUserdataForNIObject(usertypeDefinition);

		// Basic property binding.
		usertypeDefinition["frequency"] = &NI::TimeController::frequency;
		usertypeDefinition["phase"] = &NI::TimeController::phase;
		usertypeDefinition["lowKeyFrame"] = &NI::TimeController::lowKeyFrame;
		usertypeDefinition["highKeyFrame"] = &NI::TimeController::highKeyFrame;
		usertypeDefinition["startTime"] = &NI::TimeController::startTime;
		usertypeDefinition["lastScaledTime"] = &NI::TimeController::lastScaledTime;
		usertypeDefinition["lastTime"] = &NI::TimeController::lastTime;
		usertypeDefinition["target"] = sol::readonly_property(&NI::TimeController::target);
		usertypeDefinition["nextController"] = &NI::TimeController::nextController;
		usertypeDefinition["active"] = sol::property(&NI::TimeController::getActive, &NI::TimeController::setActive);
		usertypeDefinition["animTimingType"] = sol::property(&NI::TimeController::getAnimTimingType, &NI::TimeController::setAnimTimingType);
		usertypeDefinition["cycleType"] = sol::property(&NI::TimeController::getCycleType, &NI::TimeController::setCycleType);

		// Basic function binding.
		usertypeDefinition["setTarget"] = &NI::TimeController::setTarget;
		usertypeDefinition["start"] = &NI::TimeController::start;
		usertypeDefinition["stop"] = &NI::TimeController::stop;
	}

	void bindNITimeController() {
		// Get our lua state.
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		// Bind NI::TimeController
		{
			// Start our usertype.
			auto usertypeDefinition = state.new_usertype<NI::TimeController>("niTimeController");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::Object>();
			setUserdataForNITimeController(usertypeDefinition);
		}

		// Bind NI::LookAtController
		{
			// Start our usertype.
			auto usertypeDefinition = state.new_usertype<NI::LookAtController>("niLookAtController");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::TimeController, NI::Object>();
			setUserdataForNITimeController(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["axis"] = sol::property(&NI::LookAtController::getAxis, &NI::LookAtController::setAxis);
			usertypeDefinition["flip"] = sol::property(&NI::LookAtController::getFlip, &NI::LookAtController::setFlip);
			usertypeDefinition["lookAt"] = sol::property(&NI::LookAtController::getLookAt, &NI::LookAtController::setLookAt);
		}

		// Bind various keyframe data types.
		{
			// Bind NI::AnimationKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::AnimationKey>("niAnimationKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["timing"] = &NI::AnimationKey::timing;
			}

			// Bind NI::FloatKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::FloatKey>("niFloatKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::FloatKey::timing;

				// Basic property binding.
				usertypeDefinition["value"] = &NI::FloatKey::value;
			}

			// Bind NI::RotKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::RotKey>("niRotKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::RotKey::timing;

				// Basic property binding.
				usertypeDefinition["value"] = &NI::RotKey::value;
			}

			// Bind NI::BezRotKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::BezRotKey>("niBezRotKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::RotKey, NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::BezRotKey::timing;
				usertypeDefinition["value"] = &NI::BezRotKey::value;

				// Basic property binding.
				usertypeDefinition["intermediate"] = &NI::BezRotKey::intermediate;
			}

			// Bind NI::TCBRotKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::TCBRotKey>("niTCBRotKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::RotKey, NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::TCBRotKey::timing;
				usertypeDefinition["value"] = &NI::TCBRotKey::value;

				// Basic property binding.
				usertypeDefinition["bias"] = &NI::TCBRotKey::bias;
				usertypeDefinition["continuity"] = &NI::TCBRotKey::continuity;
				usertypeDefinition["intermediateA"] = &NI::TCBRotKey::intermediateA;
				usertypeDefinition["intermediateB"] = &NI::TCBRotKey::intermediateB;
				usertypeDefinition["tension"] = &NI::TCBRotKey::tension;
			}

			// Bind NI::PosKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::PosKey>("niPosKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::PosKey::timing;

				// Basic property binding.
				usertypeDefinition["value"] = &NI::PosKey::value;
			}

			// Bind NI::BezPosKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::BezPosKey>("niBezPosKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::PosKey, NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::BezPosKey::timing;
				usertypeDefinition["value"] = &NI::BezPosKey::value;

				// Basic property binding.
				usertypeDefinition["inTangent"] = &NI::BezPosKey::inTangent;
				usertypeDefinition["intermediateA"] = &NI::BezPosKey::intermediateA;
				usertypeDefinition["intermediateB"] = &NI::BezPosKey::intermediateB;
				usertypeDefinition["outTangent"] = &NI::BezPosKey::outTangent;
			}

			// Bind NI::TCBPosKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::TCBPosKey>("niTCBPosKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::PosKey, NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::TCBPosKey::timing;
				usertypeDefinition["value"] = &NI::TCBPosKey::value;

				// Basic property binding.
				usertypeDefinition["bias"] = &NI::TCBPosKey::bias;
				usertypeDefinition["continuity"] = &NI::TCBPosKey::continuity;
				usertypeDefinition["derivedA"] = &NI::TCBPosKey::derivedA;
				usertypeDefinition["derivedB"] = &NI::TCBPosKey::derivedB;
				usertypeDefinition["intermediateA"] = &NI::TCBPosKey::intermediateA;
				usertypeDefinition["intermediateB"] = &NI::TCBPosKey::intermediateB;
				usertypeDefinition["tension"] = &NI::TCBPosKey::tension;
			}

			// Bind NI::ScaleKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::ScaleKey>("niScaleKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::ScaleKey::timing;

				// Basic property binding.
				usertypeDefinition["value"] = &NI::ScaleKey::value;
			}

			// Bind NI::BezScaleKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::BezScaleKey>("niBezScaleKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::ScaleKey, NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::BezScaleKey::timing;
				usertypeDefinition["value"] = &NI::BezScaleKey::value;

				// Basic property binding.
				usertypeDefinition["inTangent"] = &NI::BezScaleKey::inTangent;
				usertypeDefinition["outTangent"] = &NI::BezScaleKey::outTangent;
			}

			// Bind NI::TCBScaleKey
			{
				// Start our usertype.
				auto usertypeDefinition = state.new_usertype<NI::TCBScaleKey>("niTCBScaleKey");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::ScaleKey, NI::AnimationKey>();
				usertypeDefinition["timing"] = &NI::TCBScaleKey::timing;
				usertypeDefinition["value"] = &NI::TCBScaleKey::value;

				// Basic property binding.
				usertypeDefinition["bias"] = &NI::TCBScaleKey::bias;
				usertypeDefinition["continuity"] = &NI::TCBScaleKey::continuity;
				usertypeDefinition["derivedA"] = &NI::TCBScaleKey::derivedA;
				usertypeDefinition["derivedB"] = &NI::TCBScaleKey::derivedB;
				usertypeDefinition["tension"] = &NI::TCBScaleKey::tension;
			}
		}

		// Bind NI::KeyframeData
		{
			// Start our usertype.
			auto usertypeDefinition = state.new_usertype<NI::KeyframeData>("niKeyframeData");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::Object>();
			setUserdataForNIObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["positionKeyCount"] = sol::readonly_property(&NI::KeyframeData::positionKeyCount);
			usertypeDefinition["positionKeys"] = sol::readonly_property(&NI::KeyframeData::getPositionKeys_lua);
			usertypeDefinition["positionType"] = sol::readonly_property(&NI::KeyframeData::positionType);
			usertypeDefinition["rotationKeyCount"] = sol::readonly_property(&NI::KeyframeData::rotationKeyCount);
			usertypeDefinition["rotationKeys"] = sol::readonly_property(&NI::KeyframeData::getRotationKeys_lua);
			usertypeDefinition["rotationType"] = sol::readonly_property(&NI::KeyframeData::rotationType);
			usertypeDefinition["scaleKeyCount"] = sol::readonly_property(&NI::KeyframeData::scaleKeyCount);
			usertypeDefinition["scaleKeys"] = sol::readonly_property(&NI::KeyframeData::getScaleKeys_lua);
			usertypeDefinition["scaleType"] = sol::readonly_property(&NI::KeyframeData::scaleType);
		}

		// Bind NI::KeyframeController
		{
			// Start our usertype.
			auto usertypeDefinition = state.new_usertype<NI::KeyframeController>("niKeyframeController");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::TimeController, NI::Object>();
			setUserdataForNITimeController(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["data"] = sol::readonly_property(&NI::KeyframeController::keyframeData);
			usertypeDefinition["lastUsedPositionIndex"] = &NI::KeyframeController::lastPosIndex;
			usertypeDefinition["lastUsedRotationIndex"] = &NI::KeyframeController::lastRotIndex;
			usertypeDefinition["lastUsedScaleIndex"] = &NI::KeyframeController::lastScaleIndex;
		}
	}
}
