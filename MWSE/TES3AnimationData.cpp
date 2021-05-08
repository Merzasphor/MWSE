#include "TES3AnimationData.h"
#include "TES3ActorAnimationData.h"

#include "NINode.h"
#include "NIKeyframeManager.h"

#include "LuaManager.h"

#include "LuaPlayAnimationGroupEvent.h"

namespace TES3 {
	const auto TES3_AnimationData_playAnimationGroupForIndex = reinterpret_cast<void(__thiscall*)(AnimationData*, int, int, int, int)>(0x470AE0);
	void AnimationData::playAnimationGroupForIndex(int animationGroup, int triIndex, int startFlag, int loopCount) {
		if (mwse::lua::event::PlayAnimationGroupEvent::getEventEnabled()) {
			auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
			sol::object response = stateHandle.triggerEvent(new mwse::lua::event::PlayAnimationGroupEvent(this, animationGroup, triIndex, startFlag, loopCount));
			if (response.get_type() == sol::type::table) {
				sol::table eventData = response;

				// Allow event blocking.
				if (eventData.get_or("block", false)) {
					return;
				}

				// Allow overrides.
				animationGroup = eventData.get_or("group", animationGroup);
				startFlag = eventData.get_or("flags", startFlag);
				loopCount = eventData.get_or("loopCount", loopCount);
			}
		}

		TES3_AnimationData_playAnimationGroupForIndex(this, animationGroup, triIndex, startFlag, loopCount);
	}

	const auto TES3_AnimationData_setHeadNode = reinterpret_cast<void(__thiscall*)(AnimationData*, NI::Node*)>(0x4704B0);
	void AnimationData::setHeadNode(NI::Node* head) {
		TES3_AnimationData_setHeadNode(this, head);
	}

	Reference* AnimationData::getReference() const {
		if (actorNode) {
			return actorNode->getTes3Reference(false);
		}
		return nullptr;
	}

	void AnimationData::playAnimationGroup(int animationGroup, int startFlag, int loopCount) {
		playAnimationGroupForIndex(animationGroup, 0, startFlag, loopCount);
		playAnimationGroupForIndex(animationGroup, 1, startFlag, loopCount);
		playAnimationGroupForIndex(animationGroup, 2, startFlag, loopCount);
	}

	const auto TES3_AnimAttachment_setLayerKeyframes = reinterpret_cast<bool(__thiscall*)(TES3::AnimationData*, TES3::KeyframeDefinition*, int, int)>(0x46BA30);
	const auto TES3_AnimAttachment_mergeAnimGroups = reinterpret_cast<bool(__thiscall*)(TES3::AnimationData*, TES3::AnimationGroup*, int)>(0x4708D0);

	void AnimationData::setAnimationLayer(TES3::KeyframeDefinition* keyframe, int layerIndex) {
		// Set sequence group layer and update animation group pointers.
		TES3_AnimAttachment_setLayerKeyframes(this, keyframe, layerIndex, 1);
		TES3_AnimAttachment_mergeAnimGroups(this, keyframe->animationGroup, layerIndex);
	}

	bool AnimationData::hasSpecialAnimations() const {
		return keyframeLayers[0].lower != nullptr;
	}

	void AnimationData::clearAnimationLayer(int layerIndex) {
		// Free NiSequence clones.
		auto& layer = keyframeLayers[layerIndex];
		if (layer.lower) {
			layer.lower->release();
			layer.lower = nullptr;
		}
		if (layer.upper) {
			layer.upper->release();
			layer.upper = nullptr;
		}
		if (layer.leftArm) {
			layer.leftArm->release();
			layer.leftArm = nullptr;
		}
	}

}
