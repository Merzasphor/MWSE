#pragma once

namespace TES3 {
	struct Statistic {
		void * vTable;
		float base;
		float current;
	};
	static_assert(sizeof(Statistic) == 0xC, "TES3::Statistic failed size validation");


	struct SkillStatistic : Statistic {
		unsigned int type; // 0xC // Not specialization?
	};
	static_assert(sizeof(SkillStatistic) == 0x10, "TES3::SkillStatistic failed size validation");
}
