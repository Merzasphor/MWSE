#include "TES3Skill.h"

#include "TES3Util.h"

namespace TES3 {
	int Skill::getNameGMST() {
		return mwse::tes3::getSkillNameGMST(skill);
	}
}
