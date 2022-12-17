#pragma once

namespace se::cs {
	struct Settings_t {
		struct RenderWindowSettings {
			bool use_world_axis_rotations_by_default = true;

			void from_toml(const toml::value& v);
			toml::value into_toml() const;
		} render_window;

		void load();
		void save();

		void from_toml(const toml::value& v);
		toml::value into_toml() const;
	};

	extern Settings_t settings;

}
