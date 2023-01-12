#include "CSDialogueInfo.h"

#include "CSDataHandler.h"
#include "CSDialogue.h"
#include "CSRecordHandler.h"

namespace se::cs {
	Dialogue* DialogueInfo::getDialogue() const {
		const auto& dialogues = *DataHandler::get()->recordHandler->dialogues;
		for (const auto& dialogue : dialogues) {
			for (const auto& info : dialogue->topics) {
				if (info == this) {
					return dialogue;
				}
			}
		}
		return nullptr;
	}
}
