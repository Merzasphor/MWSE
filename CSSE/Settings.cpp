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

	void Settings_t::ObjectWindowSettings::ColumnSettings::from_toml(const toml::value& v) {
		width = toml::find_or(v, "width", width);
	}

	toml::value Settings_t::ObjectWindowSettings::ColumnSettings::into_toml() const {
		return toml::value(
			{
				{ "width", width },
			}
		);
	}

	void Settings_t::ObjectWindowSettings::from_toml(const toml::value& v) {
		// Backwards compatibility.
		clear_filter_on_tab_switch = toml::find_or(v, "clear_on_tab_switch", clear_filter_on_tab_switch);

		// Search settings
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

		// Column settings
		column_actor_class = toml::find_or(v, "column_actor_class", column_actor_class);
		column_actor_essential = toml::find_or(v, "column_actor_essential", column_actor_essential);
		column_actor_faction = toml::find_or(v, "column_actor_faction", column_actor_faction);
		column_actor_faction_rank = toml::find_or(v, "column_actor_faction_rank", column_actor_faction_rank);
		column_actor_level = toml::find_or(v, "column_actor_level", column_actor_level);
		column_actor_respawns = toml::find_or(v, "column_actor_respawns", column_actor_respawns);
		column_all_lte_pc = toml::find_or(v, "column_all_lte_pc", column_all_lte_pc);
		column_animation = toml::find_or(v, "column_animation", column_animation);
		column_autocalc = toml::find_or(v, "column_autocalc", column_autocalc);
		column_blocked = toml::find_or(v, "column_blocked", column_blocked);
		column_book_is_scroll = toml::find_or(v, "column_book_is_scroll", column_book_is_scroll);
		column_book_teaches = toml::find_or(v, "column_book_teaches", column_book_teaches);
		column_charge = toml::find_or(v, "column_charge", column_charge);
		column_cost = toml::find_or(v, "column_cost", column_cost);
		column_count = toml::find_or(v, "column_count", column_count);
		column_creature_bipedal = toml::find_or(v, "column_creature_bipedal", column_creature_bipedal);
		column_creature_movement_type = toml::find_or(v, "column_creature_movement_type", column_creature_movement_type);
		column_creature_sound = toml::find_or(v, "column_creature_sound", column_creature_sound);
		column_creature_use_weapon_and_shield = toml::find_or(v, "column_creature_use_weapon_and_shield", column_creature_use_weapon_and_shield);
		column_effect = toml::find_or(v, "column_effect", column_effect);
		column_enchanting = toml::find_or(v, "column_enchanting", column_enchanting);
		column_enchantment = toml::find_or(v, "column_enchantment", column_enchantment);
		column_female = toml::find_or(v, "column_female", column_female);
		column_health = toml::find_or(v, "column_health", column_health);
		column_id = toml::find_or(v, "column_id", column_id);
		column_inventory = toml::find_or(v, "column_inventory", column_inventory);
		column_item_list = toml::find_or(v, "column_item_list", column_item_list);
		column_leveled_creature_list = toml::find_or(v, "column_leveled_creature_list", column_leveled_creature_list);
		column_light_radius = toml::find_or(v, "column_light_radius", column_light_radius);
		column_light_time = toml::find_or(v, "column_light_time", column_light_time);
		column_model = toml::find_or(v, "column_model", column_model);
		column_modified = toml::find_or(v, "column_modified", column_modified);
		column_name = toml::find_or(v, "column_name", column_name);
		column_organic = toml::find_or(v, "column_organic", column_organic);
		column_part = toml::find_or(v, "column_part", column_part);
		column_part_type = toml::find_or(v, "column_part_type", column_part_type);
		column_persists = toml::find_or(v, "column_persists", column_persists);
		column_playable = toml::find_or(v, "column_playable", column_playable);
		column_quality = toml::find_or(v, "column_quality", column_quality);
		column_race = toml::find_or(v, "column_race", column_race);
		column_rating = toml::find_or(v, "column_rating", column_rating);
		column_script = toml::find_or(v, "column_script", column_script);
		column_sound = toml::find_or(v, "column_sound", column_sound);
		column_spell_pc_start = toml::find_or(v, "column_spell_pc_start", column_spell_pc_start);
		column_type = toml::find_or(v, "column_type", column_type);
		column_uses = toml::find_or(v, "column_uses", column_uses);
		column_value = toml::find_or(v, "column_value", column_value);
		column_weapon_chop_max = toml::find_or(v, "column_weapon_chop_max", column_weapon_chop_max);
		column_weapon_chop_min = toml::find_or(v, "column_weapon_chop_min", column_weapon_chop_min);
		column_weapon_ignores_resistance = toml::find_or(v, "column_weapon_ignores_resistance", column_weapon_ignores_resistance);
		column_weapon_reach = toml::find_or(v, "column_weapon_reach", column_weapon_reach);
		column_weapon_silver = toml::find_or(v, "column_weapon_silver", column_weapon_silver);
		column_weapon_slash_max = toml::find_or(v, "column_weapon_slash_max", column_weapon_slash_max);
		column_weapon_slash_min = toml::find_or(v, "column_weapon_slash_min", column_weapon_slash_min);
		column_weapon_speed = toml::find_or(v, "column_weapon_speed", column_weapon_speed);
		column_weapon_thrust_max = toml::find_or(v, "column_weapon_thrust_max", column_weapon_thrust_max);
		column_weapon_thrust_min = toml::find_or(v, "column_weapon_thrust_min", column_weapon_thrust_min);
		column_weight = toml::find_or(v, "column_weight", column_weight);
		column_weight_class = toml::find_or(v, "column_weight_class", column_weight_class);
	}

	toml::value Settings_t::ObjectWindowSettings::into_toml() const {
		return toml::value(
			{
				// Search settings
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

				// Column settings
				{ "column_actor_class", column_actor_class },
				{ "column_actor_essential", column_actor_essential },
				{ "column_actor_faction", column_actor_faction },
				{ "column_actor_faction_rank", column_actor_faction_rank },
				{ "column_actor_level", column_actor_level },
				{ "column_actor_respawns", column_actor_respawns },
				{ "column_all_lte_pc", column_all_lte_pc },
				{ "column_animation", column_animation },
				{ "column_autocalc", column_autocalc },
				{ "column_blocked", column_blocked },
				{ "column_book_is_scroll", column_book_is_scroll },
				{ "column_book_teaches", column_book_teaches },
				{ "column_charge", column_charge },
				{ "column_cost", column_cost },
				{ "column_count", column_count },
				{ "column_creature_bipedal", column_creature_bipedal },
				{ "column_creature_movement_type", column_creature_movement_type },
				{ "column_creature_sound", column_creature_sound },
				{ "column_creature_use_weapon_and_shield", column_creature_use_weapon_and_shield },
				{ "column_effect", column_effect },
				{ "column_enchanting", column_enchanting },
				{ "column_enchantment", column_enchantment },
				{ "column_female", column_female },
				{ "column_health", column_health },
				{ "column_id", column_id },
				{ "column_inventory", column_inventory },
				{ "column_item_list", column_item_list },
				{ "column_leveled_creature_list", column_leveled_creature_list },
				{ "column_light_radius", column_light_radius },
				{ "column_light_time", column_light_time },
				{ "column_model", column_model },
				{ "column_modified", column_modified },
				{ "column_name", column_name },
				{ "column_organic", column_organic },
				{ "column_part", column_part },
				{ "column_part_type", column_part_type },
				{ "column_persists", column_persists },
				{ "column_playable", column_playable },
				{ "column_quality", column_quality },
				{ "column_race", column_race },
				{ "column_rating", column_rating },
				{ "column_script", column_script },
				{ "column_sound", column_sound },
				{ "column_spell_pc_start", column_spell_pc_start },
				{ "column_type", column_type },
				{ "column_uses", column_uses },
				{ "column_value", column_value },
				{ "column_weapon_chop_max", column_weapon_chop_max },
				{ "column_weapon_chop_min", column_weapon_chop_min },
				{ "column_weapon_ignores_resistance", column_weapon_ignores_resistance },
				{ "column_weapon_reach", column_weapon_reach },
				{ "column_weapon_silver", column_weapon_silver },
				{ "column_weapon_slash_max", column_weapon_slash_max },
				{ "column_weapon_slash_min", column_weapon_slash_min },
				{ "column_weapon_speed", column_weapon_speed },
				{ "column_weapon_thrust_max", column_weapon_thrust_max },
				{ "column_weapon_thrust_min", column_weapon_thrust_min },
				{ "column_weight", column_weight },
				{ "column_weight_class", column_weight_class },
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
