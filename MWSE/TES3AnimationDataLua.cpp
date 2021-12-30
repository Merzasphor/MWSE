#include "TES3AnimationDataLua.h"

#include "LuaManager.h"

#include "TES3AnimationData.h"
#include "TES3AnimationGroup.h"
#include "TES3Reference.h"
#include "TES3Sound.h"

#include "NIGeometry.h"
#include "NIKeyframeManager.h"

namespace mwse::lua {
	void bindTES3AnimationData() {
		// Get our lua state.
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		{
			// Start our usertype.
			auto usertypeDefinition = state.new_usertype<TES3::AnimationData::SequenceGroup>("tes3animationDataSequenceGroup");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property bindings.
			usertypeDefinition["lower"] = &TES3::AnimationData::SequenceGroup::lower;
			usertypeDefinition["upper"] = &TES3::AnimationData::SequenceGroup::upper;
			usertypeDefinition["leftArm"] = &TES3::AnimationData::SequenceGroup::leftArm;
		}

		{
			// Start our usertype.
			auto usertypeDefinition = state.new_usertype<TES3::AnimationData::SoundGenKey>("tes3animationDataSoundGenKey");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property bindings.
			usertypeDefinition["pitch"] = &TES3::AnimationData::SoundGenKey::pitch;
			usertypeDefinition["sound"] = &TES3::AnimationData::SoundGenKey::sound;
			usertypeDefinition["startFrame"] = &TES3::AnimationData::SoundGenKey::startFrame;
			usertypeDefinition["startTime"] = &TES3::AnimationData::SoundGenKey::startTime;
			usertypeDefinition["volume"] = &TES3::AnimationData::SoundGenKey::volume;
		}

		{
			// Start our usertype.
			auto usertypeDefinition = state.new_usertype<TES3::AnimationData>("tes3animationData");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property bindings.
			usertypeDefinition["actorNode"] = &TES3::AnimationData::actorNode;
			usertypeDefinition["animationGroups"] = sol::readonly_property(&TES3::AnimationData::getAnimationGroups);
			usertypeDefinition["animationGroupSoundgenCounts"] = sol::readonly_property(&TES3::AnimationData::getAnimationGroupSoundgenCounts);
			//usertypeDefinition["animationGroupSoundgens"] = sol::readonly_property(&TES3::AnimationData::getAnimationGroupSoundgens);
			usertypeDefinition["animGroupLayerIndicies"] = sol::readonly_property(&TES3::AnimationData::getAnimGroupLayerIndicies);
			usertypeDefinition["approxRootTravelSpeeds"] = sol::readonly_property(&TES3::AnimationData::getApproxRootTravelSpeeds);
			usertypeDefinition["currentAnimGroupLayers"] = sol::readonly_property(&TES3::AnimationData::getCurrentAnimGroupLayers);
			usertypeDefinition["currentAnimGroups"] = sol::readonly_property(&TES3::AnimationData::getCurrentAnimGroups);
			usertypeDefinition["currentNodeIndices"] = sol::readonly_property(&TES3::AnimationData::getCurrentNodeIndices);
			usertypeDefinition["currentSoundgenIndices"] = sol::readonly_property(&TES3::AnimationData::getCurrentSoundgenIndices);
			usertypeDefinition["deltaTime"] = &TES3::AnimationData::deltaTime;
			usertypeDefinition["flags"] = &TES3::AnimationData::flags;
			usertypeDefinition["hasOverrideAnimations"] = sol::readonly_property(&TES3::AnimationData::hasOverrideAnimations);
			usertypeDefinition["headGeometry"] = &TES3::AnimationData::headGeometry;
			usertypeDefinition["headNode"] = &TES3::AnimationData::headNode;
			usertypeDefinition["keyframeLayers"] = sol::readonly_property(&TES3::AnimationData::getKeyframeLayers);
			usertypeDefinition["lipsyncLevel"] = &TES3::AnimationData::lipsyncLevel;
			usertypeDefinition["loopCounts"] = sol::readonly_property(&TES3::AnimationData::getLoopCounts);
			usertypeDefinition["manager"] = &TES3::AnimationData::manager;
			usertypeDefinition["modelRootNode"] = &TES3::AnimationData::modelRootNode;
			usertypeDefinition["nextLoopCounts"] = &TES3::AnimationData::nextLoopCounts;
			usertypeDefinition["playbackSpeed"] = &TES3::AnimationData::playbackSpeed;
			usertypeDefinition["positionDeltaModelRoot"] = &TES3::AnimationData::positionDeltaModelRoot;
			usertypeDefinition["spine1Node"] = &TES3::AnimationData::spine1Node;
			usertypeDefinition["spine2Node"] = &TES3::AnimationData::spine2Node;
			usertypeDefinition["spineAngle"] = &TES3::AnimationData::spineAngle;
			usertypeDefinition["timings"] = sol::readonly_property(&TES3::AnimationData::getTimings);
			usertypeDefinition["weaponSpeed"] = &TES3::AnimationData::weaponSpeed;

			// Basic function bondings.
			usertypeDefinition["getReference"] = &TES3::AnimationData::getReference;
			usertypeDefinition["playAnimationGroup"] = &TES3::AnimationData::playAnimationGroup;
			usertypeDefinition["playAnimationGroupForIndex"] = &TES3::AnimationData::playAnimationGroupForIndex;
			usertypeDefinition["setHeadNode"] = &TES3::AnimationData::setHeadNode;
			usertypeDefinition["setOverrideLayerKeyframes"] = &TES3::AnimationData::setOverrideLayerKeyframes;
		}
	}
}
