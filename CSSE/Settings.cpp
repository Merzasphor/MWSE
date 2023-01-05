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
		// Backwards compatibility.
		clear_filter_on_tab_switch = toml::find_or(v, "clear_on_tab_switch", clear_filter_on_tab_switch);

		clear_filter_on_tab_switch = toml::find_or(v, "clear_filter_on_tab_switch", clear_filter_on_tab_switch);
		filter_by_id = toml::find_or(v, "filter_by_id", filter_by_id);
		filter_by_name = toml::find_or(v, "filter_by_name", filter_by_name);
		filter_by_icon_path = toml::find_or(v, "filter_by_icon_path", filter_by_icon_path);
		filter_by_model_path = toml::find_or(v, "filter_by_model_path", filter_by_model_path);
		filter_by_enchantment_id = toml::find_or(v, "filter_by_enchantment_id", filter_by_enchantment_id);
		filter_by_script_id = toml::find_or(v, "filter_by_script_id", filter_by_script_id);
		filter_by_book_text = toml::find_or(v, "filter_by_book_text", filter_by_book_text);
		highlight_modified_items = toml::find_or(v, "highlight_modified_items", highlight_modified_items);
		case_sensitive = toml::find_or(v, "case_sensitive", case_sensitive);
		use_regex = toml::find_or(v, "use_regex", use_regex);
	}

	toml::value Settings_t::ObjectWindowSettings::into_toml() const {
		return toml::value(
			{
				{ "clear_filter_on_tab_switch", clear_filter_on_tab_switch },
				{ "filter_by_id", filter_by_id },
				{ "filter_by_name", filter_by_name },
				{ "filter_by_icon_path", filter_by_icon_path },
				{ "filter_by_model_path", filter_by_model_path },
				{ "filter_by_enchantment_id", filter_by_enchantment_id },
				{ "filter_by_script_id", filter_by_script_id },
				{ "filter_by_book_text", filter_by_book_text },
				{ "highlight_modified_items", highlight_modified_items },
				{ "case_sensitive", case_sensitive },
				{ "use_regex", use_regex },
			}
		);
	}

	//
	// QuickStart
	//

	void Settings_t::QuickstartSettings::from_toml(const toml::value& v) {
		enabled = toml::find_or(v, "enabled", enabled);
		load_cell = toml::find_or(v, "load_cell", load_cell);
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
				{ "load_cell", load_cell },
				{ "data_files", data_files },
				{ "active_file", active_file },
				{ "cell", cell },
				{ "position", position },
				{ "orientation", orientation },
			}
		);
	}

	//
	//
	//

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
		outFile << std::setw(80) << std::setprecision(8) << data;
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
