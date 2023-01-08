#pragma once

namespace se::cs {
	struct Settings_t {
		struct RenderWindowSettings {
			bool use_world_axis_rotations_by_default = true;

			void from_toml(const toml::value& v);
			toml::value into_toml() const;
		} render_window;

		struct ObjectWindowSettings {
			struct ColumnSettings {
				static constexpr auto DEFAULT_SIZE_ID = 100u;
				static constexpr auto DEFAULT_SIZE_BOOL = 45u;
				static constexpr auto DEFAULT_SIZE_SHORT = 45u;
				static constexpr auto DEFAULT_SIZE_FLOAT = 45u;

				size_t width = DEFAULT_SIZE_SHORT;

				void from_toml(const toml::value& v);
				toml::value into_toml() const;
			};

			bool clear_filter_on_tab_switch = true;
			bool filter_by_id = true;
			bool filter_by_name = true;
			bool filter_by_icon_path = true;
			bool filter_by_model_path = true;
			bool filter_by_enchantment_id = true;
			bool filter_by_script_id = true;
			bool filter_by_book_text = true;
			bool highlight_modified_items = true;
			bool use_regex = false;
			bool case_sensitive = false;

			ColumnSettings column_actor_class = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_actor_essential = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_actor_faction = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_actor_faction_rank = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_actor_level = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_actor_respawns = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_all_lte_pc = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_animation = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_autocalc = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_blocked = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_book_is_scroll = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_book_teaches = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_charge = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_cost = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_count = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_creature_bipedal = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_creature_movement_type = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_creature_sound = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_creature_use_weapon_and_shield = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_effect = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_enchanting = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_enchantment = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_female = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_health = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_id = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_inventory = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_item_list = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_light_radius = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_light_time = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_model = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_name = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_organic = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_part = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_part_type = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_persists = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_playable = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_quality = { ColumnSettings::DEFAULT_SIZE_FLOAT };
			ColumnSettings column_race = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_rating = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_script = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_sound = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_type = { ColumnSettings::DEFAULT_SIZE_ID };
			ColumnSettings column_uses = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_value = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_chop_max = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_chop_min = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_ignores_resistance = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_weapon_reach = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_silver = { ColumnSettings::DEFAULT_SIZE_BOOL };
			ColumnSettings column_weapon_slash_max = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_slash_min = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_speed = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_thrust_max = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weapon_thrust_min = { ColumnSettings::DEFAULT_SIZE_SHORT };
			ColumnSettings column_weight = { ColumnSettings::DEFAULT_SIZE_FLOAT };
			ColumnSettings column_weight_class = { ColumnSettings::DEFAULT_SIZE_FLOAT };

			void from_toml(const toml::value& v);
			toml::value into_toml() const;
		} object_window;

		struct QuickstartSettings {
			bool enabled = true;
			bool load_cell = true;
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
