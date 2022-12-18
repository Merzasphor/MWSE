#pragma once

namespace se::cs {
	struct Settings_t {
		struct RenderWindowSettings {
			bool use_world_axis_rotations_by_default = true;

			void from_toml(const toml::value& v);
			toml::value into_toml() const;
		} render_window;

		struct ObjectWindowSettings {
			bool clear_on_tab_switch = true;
			bool filter_by_id = true;
			bool filter_by_name = true;

			void from_toml(const toml::value& v);
			toml::value into_toml() const;
		} object_window;

		struct QuickstartSettings {
			bool enabled = true;
			std::vector<std::string> data_files = {};
			std::string active_file;
			std::string cell = {};
			std::array<float, 3> position = { 0.0f, 0.0f, 0.0f };
			std::array<float, 3> orientation = { 0.0f, 0.0f, 0.0f };

			void from_toml(const toml::value& v);
			toml::value into_toml() const;
		} quickstart;

		void load();
		void save();

		void from_toml(const toml::value& v);
		toml::value into_toml() const;
	};

	extern Settings_t settings;

}
