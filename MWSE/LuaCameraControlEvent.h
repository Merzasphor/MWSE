#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"
#include "TES3Vectors.h"

namespace mwse::lua::event {
	class CameraControlEvent : public GenericEvent, public DisableableEvent<CameraControlEvent> {
	public:
		CameraControlEvent(TES3::PlayerAnimationController* animController,
			const TES3::Transform& prevCameraTransform,
			const TES3::Transform& prevArmCameraTransform,
			const TES3::Transform& cameraTransform,
			const TES3::Transform& armCameraTransform);
		sol::table createEventTable();

	protected:
		TES3::PlayerAnimationController* m_AnimationController;
		TES3::Transform m_PrevCameraTransform;
		TES3::Transform m_PrevArmCameraTransform;
		TES3::Transform m_CameraTransform;
		TES3::Transform m_ArmCameraTransform;
	};
}
