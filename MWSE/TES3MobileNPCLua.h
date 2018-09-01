#pragma once

#include "TES3MobileActorLua.h"

#include "TES3MobileNPC.h"
#include "TES3NPC.h"
#include "TES3Skill.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForMobileNPC(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForMobileActor(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("forceJump", &TES3::MobileNPC::flagForceJump);
			usertypeDefinition.set("forceMoveJump", &TES3::MobileNPC::flagForceMoveJump);
			usertypeDefinition.set("forceRun", &TES3::MobileNPC::flagForceRun);
			usertypeDefinition.set("forceSneak", &TES3::MobileNPC::flagForceSneak);

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("skills", sol::property([](TES3::MobileNPC& self) { return std::ref(self.skills); }));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("object", sol::readonly_property([](TES3::MobileNPC& self) { return makeLuaObject(self.npcInstance); }));

			// Allow read access to movement speeds.
			usertypeDefinition.set("moveSpeed", sol::readonly_property([](TES3::MobileNPC& self) { return self.animationData.asActor->calculateMovementSpeed(); }));
			usertypeDefinition.set("walkSpeed", sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed));
			usertypeDefinition.set("runSpeed", sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed));
			usertypeDefinition.set("swimSpeed", sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed));
			usertypeDefinition.set("swimRunSpeed", sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed));
			usertypeDefinition.set("flySpeed", sol::readonly_property(&TES3::MobileNPC::calculateWalkSpeed));

			// Friendly access to skills.
			usertypeDefinition.set("acrobatics", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Acrobatics]; }));
			usertypeDefinition.set("alchemy", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Alchemy]; }));
			usertypeDefinition.set("alteration", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Alteration]; }));
			usertypeDefinition.set("armorer", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Armorer]; }));
			usertypeDefinition.set("athletics", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Athletics]; }));
			usertypeDefinition.set("axe", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Axe]; }));
			usertypeDefinition.set("block", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Block]; }));
			usertypeDefinition.set("bluntWeapon", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::BluntWeapon]; }));
			usertypeDefinition.set("conjuration", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Conjuration]; }));
			usertypeDefinition.set("destruction", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Destruction]; }));
			usertypeDefinition.set("enchant", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Enchant]; }));
			usertypeDefinition.set("handToHand", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::HandToHand]; }));
			usertypeDefinition.set("heavyArmor", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::HeavyArmor]; }));
			usertypeDefinition.set("illusion", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Illusion]; }));
			usertypeDefinition.set("lightArmor", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::LightArmor]; }));
			usertypeDefinition.set("longBlade", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::LongBlade]; }));
			usertypeDefinition.set("marksman", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Marksman]; }));
			usertypeDefinition.set("mediumArmor", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::MediumArmor]; }));
			usertypeDefinition.set("mercantile", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Mercantile]; }));
			usertypeDefinition.set("mysticism", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Mysticism]; }));
			usertypeDefinition.set("restoration", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Restoration]; }));
			usertypeDefinition.set("security", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Security]; }));
			usertypeDefinition.set("shortBlade", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::ShortBlade]; }));
			usertypeDefinition.set("sneak", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Sneak]; }));
			usertypeDefinition.set("spear", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Spear]; }));
			usertypeDefinition.set("speechcraft", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Speechcraft]; }));
			usertypeDefinition.set("unarmored", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Unarmored]; }));
		}

		void bindTES3MobileNPC();
	}
}
