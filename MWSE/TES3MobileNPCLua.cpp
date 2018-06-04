#include "TES3MobileNPCLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileNPC.h"
#include "TES3NPC.h"
#include "TES3Skill.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileNPC() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto mobileNPCUsertype = state.create_simple_usertype<TES3::MobileNPC>();
			mobileNPCUsertype.set("new", sol::no_constructor);

			// We inherit MobileActor.
			mobileNPCUsertype.set(sol::base_classes, sol::bases<TES3::MobileActor, TES3::MobileObject>());

			// Basic property binding.
			mobileNPCUsertype.set("forceSneak", &TES3::MobileNPC::flagForceSneak);
			mobileNPCUsertype.set("forceRun", &TES3::MobileNPC::flagForceRun);
			mobileNPCUsertype.set("forceJump", &TES3::MobileNPC::flagForceJump);
			mobileNPCUsertype.set("forceMoveJump", &TES3::MobileNPC::flagForceMoveJump);

			// Indirect bindings to unions and arrays.
			mobileNPCUsertype.set("skills", sol::property([](TES3::MobileNPC& self) { return std::ref(self.skills); }));

			// Access to other objects that need to be packaged.
			mobileNPCUsertype.set("object", sol::readonly_property([](TES3::MobileNPC& self) { makeLuaObject(self.npcInstance); }));

			// Friendly access to skills.
			mobileNPCUsertype.set("acrobatics", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Acrobatics]; }));
			mobileNPCUsertype.set("alchemy", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Alchemy]; }));
			mobileNPCUsertype.set("alteration", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Alteration]; }));
			mobileNPCUsertype.set("armorer", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Armorer]; }));
			mobileNPCUsertype.set("athletics", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Athletics]; }));
			mobileNPCUsertype.set("axe", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Axe]; }));
			mobileNPCUsertype.set("block", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Block]; }));
			mobileNPCUsertype.set("bluntWeapon", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::BluntWeapon]; }));
			mobileNPCUsertype.set("conjuration", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Conjuration]; }));
			mobileNPCUsertype.set("destruction", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Destruction]; }));
			mobileNPCUsertype.set("enchant", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Enchant]; }));
			mobileNPCUsertype.set("handToHand", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::HandToHand]; }));
			mobileNPCUsertype.set("heavyArmor", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::HeavyArmor]; }));
			mobileNPCUsertype.set("illusion", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Illusion]; }));
			mobileNPCUsertype.set("lightArmor", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::LightArmor]; }));
			mobileNPCUsertype.set("longBlade", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::LongBlade]; }));
			mobileNPCUsertype.set("marksman", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Marksman]; }));
			mobileNPCUsertype.set("mediumArmor", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::MediumArmor]; }));
			mobileNPCUsertype.set("mercantile", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Mercantile]; }));
			mobileNPCUsertype.set("mysticism", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Mysticism]; }));
			mobileNPCUsertype.set("restoration", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Restoration]; }));
			mobileNPCUsertype.set("security", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Security]; }));
			mobileNPCUsertype.set("shortBlade", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::ShortBlade]; }));
			mobileNPCUsertype.set("sneak", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Sneak]; }));
			mobileNPCUsertype.set("spear", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Spear]; }));
			mobileNPCUsertype.set("speechcraft", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Speechcraft]; }));
			mobileNPCUsertype.set("unarmored", sol::readonly_property([](TES3::MobileNPC& self) { return &self.skills[TES3::SkillID::Unarmored]; }));

			// Finish up our usertype.
			state.set_usertype("TES3MobileNPC", mobileNPCUsertype);
		}
	}
}
