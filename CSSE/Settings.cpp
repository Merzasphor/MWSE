#include "Settings.h"

#include "LogUtil.h"

namespace se::cs {
	Settings_t settings;
	
	//
	// Render Window
	//

	void Settings_t::RenderWindowSettings::from_toml(const toml::value& v) {
		use_world_axis_rotations_by_default = toml::find_or(v, "use_world_axis_rotations_by_default", use_world_axis_rotations_by_default);
	}

	toml::value Settings_t::RenderWindowSettings::into_toml() const {
		return toml::value(
			{
				{ "use_world_axis_rotations_by_default", use_world_axis_rotations_by_default },
			}
		);
	}

	//
	// Object Window
	//

	void Settings_t::ObjectWindowSettings::from_toml(const toml::value& v) {
		clear_on_tab_switch = toml::find_or(v, "clear_on_tab_switch", clear_on_tab_switch);
		filter_by_id = toml::find_or(v, "filter_by_id", filter_by_id);
		filter_by_name = toml::find_or(v, "filter_by_name", filter_by_name);
	}

	toml::value Settings_t::ObjectWindowSettings::into_toml() const {
		return toml::value(
			{
				{ "clear_on_tab_switch", clear_on_tab_switch },
				{ "filter_by_id", filter_by_id },
				{ "filter_by_name", filter_by_name },
			}
		);
	}

	//
	// QuickStart
	//

	void Settings_t::QuickstartSettings::from_toml(const toml::value& v) {
		enabled = toml::find_or(v, "enabled", enabled);
		data_files = toml::find_or(v, "data_files", data_files);
		active_file = toml::find_or(v, "active_file", active_file);
		cell = toml::find_or(v, "cell", cell);
		position = toml::find_or(v, "position", position);
		orientation = toml::find_or(v, "orientation", orientation);
	}

	toml::value Settings_t::QuickstartSettings::into_toml() const {
		return toml::value(
			{
				{ "enabled", enabled },
				{ "data_files", data_files },
				{ "active_file", active_file },
				{ "cell", cell },
				{ "position", position },
				{ "orientation", orientation },
			}
		);
	}

	void Settings_t::load() {
		if (std::filesystem::exists("csse.toml")) {
			const auto data = toml::parse("csse.toml");
			from_toml(data);
		}
	}

	void Settings_t::save() {
		std::ofstream outFile;
		outFile.open("csse.toml");

		const toml::value data = settings;
		outFile << std::setw(80) << std::setprecision(8) << data << std::endl;
	}

	void Settings_t::from_toml(const toml::value& v) {
		render_window = toml::find_or(v, "render_window", render_window);
		object_window = toml::find_or(v, "object_window", object_window);
		quickstart = toml::find_or(v, "quickstart", quickstart);
	}

	toml::value Settings_t::into_toml() const {
		return toml::value(
			{
				{ "title", "Construction Set Extender" },
				{ "object_window", object_window },
				{ "render_window", render_window },
				{ "quickstart", quickstart },
			}
		);
	}
}
