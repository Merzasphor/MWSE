#pragma once

#include "TES3UIDefines.h"
#include "NINode.h"
#include "NIPick.h"

namespace TES3 {
	namespace UI {
		struct MenuInputController {
			NI::Pick pick;
			char unknown_0x38[0x50];
			Element* textInputFocus;
			char unknown_0x8C[0x20];

			void acquireTextInput(Element* element);
			void displayObjectTooltip(TES3::Object * object, TES3::ItemData * itemData, int count = 0);

			//
			// Custom functions.
			//

			void updateObjectTooltip();
		};
		static_assert(sizeof(MenuInputController) == 0xAC, "TES3::UI::MenuInputController failed size validation");

		struct FontColor {
			int r;
			int g;
			int b;
		};
		static_assert(sizeof(FontColor) == 0xC, "TES3::UI::FontColor failed size validation");

		enum FontColorId : unsigned int {
			normal,
			normal_over,
			normal_pressed,
			active,
			active_over,
			active_pressed,
			disabled,
			disabled_over,
			disabled_pressed,
			link,
			link_over,
			link_pressed,
			journal,
			journal_over,
			journal_pressed,
			journal_topic,
			journal_topic_over,
			journal_topic_pressed,
			journal_finished_quest_topic,
			journal_finished_quest_topic_over,
			journal_finished_quest_topic_pressed,
			answer,
			answer_over,
			answer_pressed,
			header,
			notify,
			big_normal,
			big_normal_over,
			big_normal_pressed,
			big_link,
			big_link_over,
			big_link_pressed,
			big_answer,
			big_answer_over,
			big_answer_pressed,
			big_header,
			big_notify,
			background,
			focus,
			npc_health,
			health,
			magic,
			fatigue,
			misc,
			weapon_fill,
			magic_fill,
			positive,
			negative,
			count,

			MAX_ID = count
		};

		struct MenuController {
			Element* mainRoot; // 0x0
			Element* helpRoot; // 0x4
			NI::Node* mainNode; // 0x8
			NI::Node* helpNode; // 0xC
			MenuInputController* menuInputController; // 0x10
			int unknown_0x14;
			void * unknown_0x18;
			int unknown_0x1C;
			ScriptCompiler * scriptCompiler; // 0x20
			int unknown_0x24; // Maybe toggle flags?
			int helpDelay; // 0x28
			char unknown_0x2C;
			int unknown_0x30;
			bool inventoryMenuEnabled; // 0x34
			bool statsMenuEnabled; // 0x35
			bool magicMenuEnabled; // 0x36
			bool mapMenuEnabled; // 0x37
			char unknown_0x38;
			char unknown_0x39;
			char padding_0x3A[2];
			short unknown_0x3C;
			FontColor fontColors[FontColorId::MAX_ID + 1];
			int unknown_0x28C;
			int unknown_0x290;
			int unknown_0x294;
			int unknown_0x298;
			int unknown_0x29C;
			char unknown_0x2A0;

			//
			// Other related this-call functions.
			//

			void setInventoryMenuEnabled(bool enabled);
			void setMagicMenuEnabled(bool enabled);
			void setMapMenuEnabled(bool enabled);
			void setStatsMenuEnabled(bool enabled);

			//
			// Custom functions.
			//

			bool getInventoryMenuEnabled();
			bool getMagicMenuEnabled();
			bool getMapMenuEnabled();
			bool getStatsMenuEnabled();

		};
		static_assert(sizeof(MenuController) == 0x2A4, "TES3::UI::MenuController failed size validation");

	}
}