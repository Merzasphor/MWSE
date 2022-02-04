#pragma once

namespace mwse::lua::event {
	template <typename T>
	class DisableableEvent {
	public:
		static bool getEventEnabled() { return m_EventEnabled; }
		static void setEventEnabled(bool enabled) { m_EventEnabled = enabled; }

	protected:
		static bool m_EventEnabled;
	};
}
