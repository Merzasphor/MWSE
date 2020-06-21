#pragma once

#include "TES3MobileActorLua.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForTES3MobileNPC(sol::usertype<T>& usertypeDefinition) {
			setUserdataForTES3MobileActor(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["forceJump"] = &TES3::MobileNPC::flagForceJump;
			usertypeDefinition["forceMoveJump"] = &TES3::MobileNPC::flagForceMoveJump;
			usertypeDefinition["forceRun"] = &TES3::MobileNPC::flagForceRun;
			usertypeDefinition["forceSneak"] = &TES3::MobileNPC::flagForceSneak;

			// Indirect bindings to unions and arrays.
			usertypeDefinition["skills"] = sol::property([](TES3::MobileNPC& self) { return std::ref(self.skills); });

			// Access to other objects that need to be packaged.
			usertypeDefinition["object"] = sol::readonly_property([](TES3::MobileNPC& self) { return self.npcInstance; });

			// Allow read access to movement speeds.
			usertypeDefinition["moveSpeed"] = sol::readonly_property([](TES3::MobileNPC& self) { return self.animationData.asActor->calculateMovementSpeed(); });
			usertypeDefinition["walkSpeed"] = sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed);
			usertypeDefinition["runSpeed"] = sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed);
			usertypeDefinition["swimSpeed"] = sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed);
			usertypeDefinition["swimRunSpeed"] = sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed);
			usertypeDefinition["flySpeed"] = sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed);

			// Friendly access to skills.
			usertypeDefinition["acrobatics"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Acrobatics]; });
			usertypeDefinition["alchemy"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Alchemy]; });
			usertypeDefinition["alteration"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Alteration]; });
			usertypeDefinition["armorer"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Armorer]; });
			usertypeDefinition["athletics"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Athletics]; });
			usertypeDefinition["axe"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Axe]; });
			usertypeDefinition["block"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Block]; });
			usertypeDefinition["bluntWeapon"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::BluntWeapon]; });
			usertypeDefinition["conjuration"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Conjuration]; });
			usertypeDefinition["destruction"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Destruction]; });
			usertypeDefinition["enchant"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Enchant]; });
			usertypeDefinition["handToHand"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::HandToHand]; });
			usertypeDefinition["heavyArmor"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::HeavyArmor]; });
			usertypeDefinition["illusion"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Illusion]; });
			usertypeDefinition["lightArmor"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::LightArmor]; });
			usertypeDefinition["longBlade"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::LongBlade]; });
			usertypeDefinition["marksman"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Marksman]; });
			usertypeDefinition["mediumArmor"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::MediumArmor]; });
			usertypeDefinition["mercantile"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Mercantile]; });
			usertypeDefinition["mysticism"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Mysticism]; });
			usertypeDefinition["restoration"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Restoration]; });
			usertypeDefinition["security"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Security]; });
			usertypeDefinition["shortBlade"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::ShortBlade]; });
			usertypeDefinition["sneak"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Sneak]; });
			usertypeDefinition["spear"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Spear]; });
			usertypeDefinition["speechcraft"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Speechcraft]; });
			usertypeDefinition["unarmored"] = sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Unarmored]; });
		}

		void bindTES3MobileNPC();
	}
}
