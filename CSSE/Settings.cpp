#include "Settings.h"

#include "LogUtil.h"

namespace se::cs {
	Settings_t settings;

	void Settings_t::RenderWindowSettings::from_toml(const toml::value& v) {
		use_world_axis_rotations_by_default = toml::find_or(v, "use_world_axis_rotations_by_default", use_world_axis_rotations_by_default);
	}

	toml::value Settings_t::RenderWindowSettings::into_toml() const {
		return toml::value({
			{ "use_world_axis_rotations_by_default", use_world_axis_rotations_by_default },
			});
	}

	void Settings_t::load() {
		if (std::filesystem::exists("csse.toml")) {
			const auto data = toml::parse("csse.toml");
			render_window = toml::find_or(data, "render_window", render_window);
		}
	}

	void Settings_t::save() {
		std::ofstream outFile;
		outFile.open("csse.toml");

		const toml::value data = settings;
		outFile << data << std::endl;
	}

	void Settings_t::from_toml(const toml::value& v) {
		render_window = toml::find_or(v, "render_window", render_window);
	}

	toml::value Settings_t::into_toml() const {
		return toml::value({
			{ "render_window", render_window },
			});
	}
}
