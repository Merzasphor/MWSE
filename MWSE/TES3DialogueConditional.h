#pragma once

#include "TES3Defines.h"

namespace TES3 {
	enum class DialogueConditionalType : unsigned char {
		Function = 1,
		GlobalVar,
		LocalVar,
		JournalIndex,
		ItemCount,
		DeadActor,
		NotID,
		NotFaction,
		NotClass,
		NotRace,
		NotCell,
		NotLocal
	};

	enum class DialogueConditionalConstantType : char {
		Class = 'C',
		DeadActor = 'D',
		Faction = 'F',
		Item = 'I',
		Journal = 'J',
		Cell = 'L',
		Race = 'R',
		NotID = 'X',
		VariableFloat = 'f',
		VariableInt = 'i',
		VariableShort = 's'
	};

	enum class DialogueConditionalComparator : unsigned char {
		Equal = 0,
		NotEqual,
		Greater,
		GreaterEqual,
		Less,
		LessEqual
	};

	enum class DialogueConditionalFunction : int {
		ReactionLow = 0,
		ReactionHigh,
		RankRequirement,
		Reputation,
		HealthPercent,
		PCReputation,
		PCLevel,
		PCHealthPercent,
		PCMagicka,
		PCFatigue,
		PCStrength,
		PCBlock,
		PCArmorer,
		PCMediumArmor,
		PCHeavyArmor,
		PCBluntWeapon,
		PCLongBlade,
		PCAxe,
		PCSpear,
		PCAthletics,
		PCEnchant,
		PCDestruction,
		PCAlteration,
		PCIllusion,
		PCConjuration,
		PCMysticism,
		PCRestoration,
		PCAlchemy,
		PCUnarmored,
		PCSecurity,
		PCSneak,
		PCAcrobatics,
		PCLightArmor,
		PCShortBlade,
		PCMarksman,
		PCMercantile,
		PCSpeechcraft,
		PCHandToHand,
		PCSex,
		PCExpelled,
		PCCommonDisease,
		PCBlightDisease,
		PCClothingModifier,
		PCCrimeLevel,
		SameSex,
		SameRace,
		SameFaction,
		FactionRankDifference,
		Detected,
		Alarmed,
		Choice,
		PCIntelligence,
		PCWillpower,
		PCAgility,
		PCSpeed,
		PCEndurance,
		PCPersonality,
		PCLuck,
		PCCorprus,
		Weather,
		PCVampire,
		Level,
		Attacked,
		TalkedToPC,
		PCHealth,
		CreatureTarget,
		FriendHit,
		Fight,
		Hello,
		Alarm,
		Flee,
		ShouldAttack,
		Werewolf,
		PCWerewolfKills
	};

	struct DialogueConditional {
		union {
			BaseObject* object;
			const char* localVarName;
			DialogueConditionalFunction function;
		};
		DialogueConditionalType type;
		DialogueConditionalConstantType constantType;
		short localVarIndex;
		DialogueConditionalComparator compareOperator;
		float compareValue;

		DialogueConditional() = delete;
		~DialogueConditional() = delete;
	};
	static_assert(sizeof(DialogueConditional) == 0x10, "TES3::DialogueConditional failed size validation");
}
