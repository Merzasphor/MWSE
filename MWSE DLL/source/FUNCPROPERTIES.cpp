//FuncProperties.cpp
#include <windows.h>
#include <algorithm>
using namespace std;

#include "FUNCPROPERTIES.h"
#include "REFERENCE.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "DEBUGGING.h"
#include "cLog.h"
#include "TES3OFFSETS.h"
#include <string.h>
// 22-08-2006 Tp21
#include "warnings.h"

static SPELRecord * GetSpellRecord(VMLONG spellId, TES3MACHINE & machine);

// These functions are used for validation in FUNCSETMAX... and for
// retrieving the value in FUNCGETMAX... execute() methods.
static ULONG GetMaxCondition(TES3MACHINE &machine, VPVOID refr, ULONG type);
static ULONG GetMaxCharge(TES3MACHINE &machine, VPVOID refr, ULONG type);

static VPVOID GetMaxChargeOffset(TES3MACHINE &machine, VPVOID refr, ULONG type);

//Tp21 22-08-2006: xGetSpellEffects
//TODO i don't think it works... (we don't get the return results... have to find that breakpoint)
FUNCGETSPELLEFFECTS::FUNCGETSPELLEFFECTS(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

bool FUNCGETBASEACROBATICS::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x13d, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEACR()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEALCHEMY::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x12d, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEALCHEMY()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEALTERATION::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x119, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEALTERATION()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEARMORER::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xf1, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEARMORER()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEATHLETICS::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x10d, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEATHLETICS()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEAXE::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x105, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASE()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEBLOCK::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xed, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEBLOCK()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEBLUNTWEAPON::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xfd, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEBLUNTWEAPON()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASECONJURATION::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x121, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASECONJURATION()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEDESTRUCTION::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x115, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEDESTRUCTION()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEENCHANT::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x111, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEENCHANT()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEHANDTOHAND::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x155, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEHANDTOHAND()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEHEAVYARMOR::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xf9, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEHEAVYARMOR()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEILLUSION::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x11d, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEILLUSION()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASELIGHTARMOR::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x141, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASELIGHTARMOR()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASELONGBLADE::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x101, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASELONGBLADE()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEMARKSMAN::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x149, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEMARKSMAN()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEMEDIUMARMOR::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xf5, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEMEDIUMARMOR()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEMERCANTILE::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x14d, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEMERCANTILE()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEMYSTICISM::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x125, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEMYSTICISM()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASERESTORATION::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x129, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASERESTORATION()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASESECURITY::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x135, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESECURITY()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASESHORTBLADE::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x145, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESHORTBLADE()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASESNEAK::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x139, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESNEAK()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASESPEAR::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x109, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESPEAR()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASESPEECHCRAFT::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x151, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESPEECHCRAFT()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETBASEUNARMORED::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x131, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEUNARMORED()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCGETPROGRESSLEVEL::execute(void)
{
	VPVOID refr;
	VMLONG value = -1;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x17A, value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETPROGRESSLEVEL()\n",value);
#endif	
	return machine.push(value);
}

bool FUNCSETPROGRESSLEVEL::execute(void)
{
	VPVOID refr;
	VMLONG progress = 0;
	bool success = false;
	
	if (GetTargetData(machine, &refr) && machine.pop(progress))
	{
		success = SetAttachData(machine, refr, 8, 0x17a, progress);
	}

#ifdef DEBUGGING
    cLog::mLogMessage("%d:FUNCSETVALUE(%d)\n",success,progress);
#endif	

	return machine.push(static_cast<VMREGTYPE>(success));
}

bool FUNCGETLOCKLEVEL::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMSHORT lockLevel = -1;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if (type == CONTAINER || type == DOOR)
		{
			TES3LOCK lockInfo;
			if (GetAttachData(machine, refr, 3, 0, lockInfo))
			{
				lockLevel = lockInfo.lockLevel;
			}
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETLOCKLEVEL()\n",lockLevel);
#endif	
	return machine.push(static_cast<VMREGTYPE>(lockLevel));
}

bool FUNCGETTRAP::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMLONG trapId = 0;
	VMLONG trapName = 0;
	VMSHORT trapCost = 0;

	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if (type == CONTAINER || type == DOOR)
		{
			TES3LOCK lockInfo;
			if (GetAttachData(machine, refr, 3, 0, lockInfo))
			{
				SPELRecord * trapSpell = lockInfo.trapSpell;
				if (trapSpell != 0)
				{
					trapId = reinterpret_cast<VMLONG>(strings.add(trapSpell->id));
					trapName = reinterpret_cast<VMLONG>(strings.add(trapSpell->friendlyName));
					trapCost = trapSpell->cost;
				}
			}
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETTRAP()\n",trapId);
#endif	
	return machine.push(static_cast<VMREGTYPE>(trapCost)) && machine.push(trapName) && machine.push(trapId);
}

bool FUNCSETTRAP::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMLONG spellId;
	bool success = false;
		
	if (GetTargetData(machine, &refr, &temp, &type) && machine.pop(spellId))
	{
		if (type == CONTAINER || type == DOOR)
		{
			TES3LOCK lockInfo;
			if (GetAttachData(machine, refr, 3, 0, lockInfo))
			{
				SPELRecord * newTrap = GetSpellRecord(spellId, machine);			
				
				// don't update if we received an unknown spell id
				if (spellId == 0 || newTrap != 0)
				{
					lockInfo.trapSpell = newTrap;
					success = SetAttachData(machine, refr, 3, 0, lockInfo);
				}
			}
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCSETTRAP()\n",success);
#endif	
	return machine.push(static_cast<VMREGTYPE>(success));
}

bool FUNCSPELLLIST::execute(void)
{
	LinkedListNode * next = 0;
	VMLONG totalSpells = 0;
	VMLONG spellId = 0;
	VMLONG name = 0;
	VMSHORT type = 0;
	VMSHORT cost = 0;
	VMSHORT effects = 0;
	VMLONG flags = 0;
	
	VPVOID refr, temp;
	unsigned long refType;

	if (machine.pop(reinterpret_cast<VMREGTYPE&>(next)) && GetTargetData(machine, &refr, &temp, &refType))
	{
		if (refType == NPC)
		{
			TES3REFERENCE * npcRef = reinterpret_cast<TES3REFERENCE*>(refr);
			NPCCopyRecord * npcCopy = reinterpret_cast<NPCCopyRecord*>(npcRef->templ);
			NPCBaseRecord * npcRec = npcCopy->baseNPC;
			totalSpells = npcRec->numberOfSpells;
			if (totalSpells > 0)
			{
				if (next == 0)
				{
					next = npcRec->spellStart;
				}

				SPELRecord * spell = reinterpret_cast<SPELRecord*>(next->dataNode);
				next = next->nextNode;

				spellId = reinterpret_cast<VMLONG>(strings.add(spell->id));
				name = reinterpret_cast<VMLONG>(strings.add(spell->friendlyName));
				type = spell->type;
				cost = spell->cost;
				flags = spell->flags;

				//count the number of effect slots in use
				for (int i = 0; i < 8; ++i)
				{
					if (spell->effects[i].effectId != 0xFFFF)
					{
						++effects;
					}
					else
					{
						break;
					}
				}
			}
		}
	}

	return machine.push(reinterpret_cast<VMREGTYPE>(next)) && machine.push(flags) && machine.push(static_cast<VMREGTYPE>(effects)) && machine.push(static_cast<VMREGTYPE>(cost)) 
		&& machine.push(static_cast<VMREGTYPE>(type)) && machine.push(name) && machine.push(spellId) && machine.push(totalSpells);
}

bool FUNCGETSPELL::execute(void)
{
	VMLONG spellId = 0;
	VMSHORT result = 0;
	VPVOID refr, temp;
	unsigned long refType;

	if (machine.pop(spellId) && GetTargetData(machine, &refr, &temp, &refType))
	{
		if (refType == NPC && spellId != 0)
		{
			char const * idString = machine.GetString(reinterpret_cast<VPVOID>(spellId));
			TES3REFERENCE * npcRef = reinterpret_cast<TES3REFERENCE*>(refr);
			NPCCopyRecord * npcCopy = reinterpret_cast<NPCCopyRecord*>(npcRef->templ);
			LinkedListNode * curr = npcCopy->baseNPC->spellStart;
			while (curr != 0)
			{
				SPELRecord * spell = reinterpret_cast<SPELRecord*>(curr->dataNode);
				if (strcmp(idString, spell->id) == 0)
				{
					result = 1;
					break;
				}
				curr = curr->nextNode;
			}
		}
	}

	return machine.push(static_cast<VMREGTYPE>(result));
}

bool FUNCGETSPELLINFO::execute(void)
{
	VMLONG spellId;
	VMLONG name = 0;
	VMSHORT type = 0;
	VMSHORT cost = 0;
	VMSHORT effects = 0;
	VMLONG flags = 0;

	if (machine.pop(spellId))
	{
		SPELRecord * spell = GetSpellRecord(spellId, machine);
		if (spell != 0)
		{
			name = reinterpret_cast<VMLONG>(strings.add(spell->friendlyName));
			type = spell->type;
			cost = spell->cost;
			flags = spell->flags;

			//count the number of effect slots in use
			for (int i = 0; i < 8; ++i)
			{
				if (spell->effects[i].effectId != 0xFFFF)
				{
					++effects;
				}
				else
				{
					break;
				}
			}
		}
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETSPELLINFO()\n",spellId);
#endif	
	return machine.push(flags) && machine.push(static_cast<VMREGTYPE>(effects)) && machine.push(static_cast<VMREGTYPE>(cost)) 
		&& machine.push(static_cast<VMREGTYPE>(type)) && machine.push(name);
}

bool FUNCGETSPELLEFFECTINFO::execute(void)
{
	VMLONG spellId;
	VMLONG effectIndex;
	VMSHORT effectId = -1;
	VMSHORT skillId;
	VMSHORT attributeId;
	VMLONG rangeType;
	VMLONG area;
	VMLONG duration;
	VMLONG magMin;
	VMLONG magMax;

	if (machine.pop(spellId) && machine.pop(effectIndex))
	{
		if (1 <= effectIndex && effectIndex <= 8)
		{			
			SPELRecord * spell = GetSpellRecord(spellId, machine);
			if (spell != 0)
			{
				--effectIndex; // 0-based array index
				effectId = spell->effects[effectIndex].effectId;
				skillId = spell->effects[effectIndex].skillId;
				attributeId = spell->effects[effectIndex].AttributeId;
				rangeType = spell->effects[effectIndex].RangeType;
				area = spell->effects[effectIndex].Area;
				duration = spell->effects[effectIndex].Duration;
				magMin = spell->effects[effectIndex].MagMin;
				magMax = spell->effects[effectIndex].MagMax;
			}
		}
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETSPELLINFO()\n",spellId);
#endif	
	return machine.push(magMax) && machine.push(magMin) && machine.push(duration) && machine.push(area) && machine.push(rangeType) 
		&& machine.push(static_cast<VMREGTYPE>(attributeId)) && machine.push(static_cast<VMREGTYPE>(skillId)) 
		&& machine.push(static_cast<VMREGTYPE>(effectId));
}

// GRM 15 Jan 2007
// Set value (worth in gold) of reference.
// <ref> xSetValue <long> -> [no value]
bool FUNCSETVALUE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset = 0;
	VMREGTYPE value = 0;
    bool set = false;
	char idstr[129];
    idstr[sizeof idstr-1] = '\0';

	if (GetTargetData(machine, &refr, &temp, &type) && machine.pop(value))
	{
		offset = offsetOfValue(type);
        // MISC is possibly gold.
        bool isGold = type == MISC &&
            GetIdString(machine, temp, idstr) &&
            strncmp(idstr, "gold_", 5) == 0;
        if (offset != 0 && !isGold) {
            if (type == CLOTHING) {
                // Clothing is a short. Since SetOffsetData only stores
                // longs, we need to fetch the value, and modify the
                // lower 16 bits.
                unsigned long oldValue;
                if (GetOffsetData(machine, temp, offset, &oldValue)) {
                    value = (oldValue & ~0xFFFF) | (value & 0xFFFF);
                }
            }
            // Note: count is ignored.
            set = SetOffsetData(machine, temp, offset, value);
        }
	}
#ifdef DEBUGGING
    cLog::mLogMessage("%d:FUNCSETVALUE(%d)\n",set,value);
#endif	
	return machine.push(static_cast<VMREGTYPE>(set));
}

// Set current charge of item, if possible
//  ref xSetCharge <float> -> [no value]
bool FUNCSETCHARGE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMFLOAT charge = 0;
    bool set = false;

    if (GetTargetData(machine, &refr, &temp, &type) && machine.pop(charge))
	{
        // Set charge in attached node. If not present, cannot
        // set current charge.
        set = SetAttachData(machine, refr, VARNODE, 4, _cpp_min(charge,
                                                               GetMaxCharge(machine, temp, type)));
	}
#ifdef DEBUGGING
	cLog::mLogMessage("FUNCSETCHARGE(%d)\n",charge);
#endif
	return machine.push(static_cast<VMREGTYPE>(set));
}

// Set current maximum charge of item, if possible
//  ref xSetCharge <float> -> [no value]
bool FUNCSETMAXCHARGE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMFLOAT maxcharge = 0;
    bool set = false;

	if (GetTargetData(machine, &refr, &temp, &type) && machine.pop(maxcharge))
	{
        VPVOID offset = GetMaxChargeOffset(machine, temp, type);
        if (offset) {
            VMFLOAT charge;
            // If the new max charge is less than the current charge,
            // force it to match.
            if (GetAttachData(machine, refr, VARNODE, 4, charge) &&
                charge >= maxcharge) {
                SetAttachData(machine, refr, VARNODE, 4, maxcharge);
            }
            // actually stored as integer
			set = SetOffsetData(machine,offset,0xc,static_cast<int>(maxcharge));
		}
	}

#ifdef DEBUGGING
	cLog::mLogMessage("FUNCSETMAXCHARGE(%d)\n",maxcharge);
#endif
	return machine.push(static_cast<VMREGTYPE>(set));
}

// GRM 17 Jan 2007
// <ref> xSetCondition <long> -> [no value]
bool FUNCSETCONDITION::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMREGTYPE value = 0;
    bool set = false;

    if (GetTargetData(machine, &refr, &temp, &type) && machine.pop(value)
        && (type == WEAPON || type == ARMOR))
	{
        // Condition is only stored as attached data. (Note that
        // GetCondition returns the maximum condition if the
        // attached data is not found).
        //
        // TODO: If the attached data is not found, it should be
        // created.
        set = SetAttachData(machine, refr, VARNODE, 3, _cpp_min(static_cast<ULONG>(value),
            GetMaxCondition(machine, temp, type)));
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("FUNCSETCONDITION(%d)\n",value);
#endif	
	return machine.push(static_cast<VMREGTYPE>(set));
}
// GRM 17 Jan 2007
// <ref> xSetMaxCondition <long> -> [no value]
bool FUNCSETMAXCONDITION::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMREGTYPE value = 0;
    bool set = false;

	if (GetTargetData(machine, &refr, &temp, &type) && machine.pop(value)
        && (type == WEAPON || type == ARMOR))
	{
		ULONG offset = offsetOfCondition(type); // misnomer, actually MaxCondition
        if ( offset ) {
            // If the new max condition is less than the current condition,
            // force it to match.
            VMREGTYPE condition;
            if (GetAttachData(machine, refr, VARNODE, 3, condition) &&
                condition > value) {
                    SetAttachData(machine, refr, VARNODE, 3, value);
            }

            if ( type == WEAPON) {
                // Weapon uses upper 16 bits of value
                ULONG oldValue;
                GetOffsetData(machine, temp, offset, &oldValue);
                value = (value << 16) | (oldValue & 0xFFFF);
            }

			set = SetOffsetData(machine, temp, offset, value);
        }
	}
#ifdef DEBUGGING
	cLog::mLogMessage("FUNCSETMAXCONDITION(%d)\n",value);
#endif	
	return machine.push(static_cast<VMREGTYPE>(set));
}

// GRM 15 Jan 2007
//  Common code for SETxxx functions.
//  ref xSetXxxxx <long|float> -> [no value]
bool CommonSet::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset = 0;
	VMFLOAT value = 0;
    bool set = false;

    if (GetTargetData(machine, &refr, &temp, &type) && machine.pop(value) &&
        canSet(type))
	{
		offset = getTypeOffset(type);
        if (offset != 0) {
            // Note: count is ignored.
            set = SetOffsetData(machine, temp, offset, value);
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%s(%f)\n", name, value);
#endif	
	return machine.push(static_cast<VMREGTYPE>(set));
}

bool FUNCGETSPELLEFFECTS::execute(void)
{
	bool result= true;
	VMREGTYPE pString= 0;
	const char* string= "null";
	VMREGTYPE count= 0;

	if(machine.pop(pString) && (string=machine.GetString((VPVOID)pString))!=0)
	{
		VMLONG strlength= strlen((const char*)string);
		parent= machine.GetFlow();
		result= machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_LENGTH_IMAGE),&strlength,sizeof(strlength))
			&& machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_IMAGE),(void*)string,strlength+1);
		if(result)
		{
			Context context= machine.GetFlow();
			context.Eip= (DWORD)reltolinear(FIXUPTEMPLATE);
			machine.SetFlow(context);
			result= machine.SetVMDebuggerBreakpoint(this);
		}
	}
	else
		result= false;

	return result;
}

BYTE FUNCGETSPELLEFFECTS::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCGETSPELLEFFECTS::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	if(machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_IMAGE),&flow.Eax,sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result= CallOriginalFunction(machine,ORIG_GETSPELLEFFECTS);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("FUNCGETSPELLEFFECTSb() %s\n",result?"succeeded":"failed");
#endif

	return result;
}

bool FUNCGETVALUE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset = 0;
	ULONG count = 0;
	ULONG value = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		offset = offsetOfValue(type);
		if (offset && GetOffsetData(machine, temp, offset, &value))
		{
			// clothing value is stored in a short not long like all others
			if (type == CLOTHING)
				value %= 65536;
	
			// gold is special (it's always worth one, but not in the CS)
			if ( type == MISC && GetIdString(machine, temp, idstr))
				if (!strncmp(idstr,"Gold_",5 )) 
					value = 1;
	
			if (GetAttachData(machine, refr, VARNODE, 0, &count))
				value *= count;
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETVALUE()\n",value);
#endif	
	return machine.push((VMREGTYPE)value);
}

bool FUNCGETOWNER::execute(void)
{
	VPVOID refr;
	ULONG data;
	ULONG id = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr))
	{
		if (GetAttachData(machine, refr, VARNODE, 1, &data) && data)
		{
			if (GetIdString(machine, (VPVOID)data, idstr))
				id= (ULONG)strings.add((const char*)idstr);
			else
				id= (ULONG)strings.add("unknown");
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCGETOWNER()\n",id, (id?(char*)id:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)id);
}


bool FUNCGETWEIGHT::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset = 0;
	ULONG count = 0;
	VMFLOAT weight = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if ( offset = offsetOfWeight(type) )
			GetOffsetData(machine,temp,offset,(ULONG*)&weight);
		
		if ( GetAttachData(machine, refr, VARNODE, 0, &count) )
			weight *= count;
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETWEIGHT()\n",weight);
#endif	
	return machine.push((VMFLOAT)weight);
}


bool FUNCGETENCUMB::execute(void)
{
	bool result= false;
	VMPTR<TES3REFERENCE*> pref(machine);
	VMPTR<TES3REFERENCE> ref(machine);
	VMPTR<TES3LISTNODE> stacknode(machine);
	VMPTR<TES3STACK> thisstack(machine);
	VMPTR<TES3TEMPLATE> templ(machine);
	VPLISTNODE pstacknode= 0;
	
	bool leveled = false;
	VMFLOAT totalweight = 0.0;
	VMFLOAT weight = 0.0;
	int i;
	try
	{
		pref= (TES3REFERENCE**)reltolinear(SCRIPTTARGETREF_IMAGE);
		if (!*pref) throw 0;
	
		ref= *pref;
		if ( REFERENCE::GetInventory(machine,*pref,pstacknode) )
		{
			while ( pstacknode )
			{
				stacknode = pstacknode;
				if (stacknode->dataptr)
				{
					thisstack = (VPSTACK)stacknode->dataptr;
					if (thisstack->templ)
					{
						templ = thisstack->templ;
						if ( i = offsetOfWeight(templ->type) ) 
						{
							machine.ReadMem(LONGOFFSET(thisstack->templ,i),&weight,sizeof(weight));
							totalweight += (weight * abs((int)thisstack->count));
						}
						else if ( templ->type == 'IVEL' )
						{
							totalweight += 0.000001;
							leveled = true;
						}
					}
				}
				pstacknode = stacknode->next;
			}
		}
		if ( leveled )
			totalweight *= -1;
		result= machine.push((VMFLOAT)totalweight);
	}
	catch(...)
	{
		result= machine.push((VMFLOAT)totalweight);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETENCUMB() %s\n",totalweight,result?"succeeded":"failed");
#endif	
	return result;
}


bool FUNCGETCONDITION::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	VMLONG condition = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
        if (type == LOCK || type == REPAIR || type == WEAPON || type == ARMOR || type == PROBE)
		{
			if (!GetAttachData(machine, refr, VARNODE, 3, condition))
			{
				condition = GetMaxCondition(machine, temp, type);
			}
		}
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETCONDITION()\n",condition);
#endif	
	return machine.push(condition);
}

bool FUNCGETMAXCOND::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
        value = GetMaxCondition(machine, temp, type);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETMAXCOND()\n",value);
#endif	
	return machine.push((VMREGTYPE)value);
}

bool FUNCGETCHARGE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG ench = 0;
	ULONG value = 0;
	VMFLOAT charge = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if (!GetAttachData(machine, refr, VARNODE, 4, charge))
		{
            charge = GetMaxCharge(machine, temp, type);
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETCHARGE()\n",charge);
#endif	
	return machine.push(charge);
}

bool FUNCGETMAXCHARGE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG ench = 0;
	ULONG value = 0;
	VMFLOAT maxcharge = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
        maxcharge = GetMaxCharge(machine, temp, type);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETMAXCHARGE()\n",maxcharge);
#endif	
	return machine.push(maxcharge);
}

bool FUNCGETQUALITY::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset;
	ULONG count = 0;
	VMFLOAT quality = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		offset = offsetOfQuality(type);
		if (offset)
			GetOffsetData(machine,temp,offset,(ULONG*)&quality);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETQUALITY()\n",quality);
#endif	
	return machine.push((VMFLOAT)quality);
}

bool FUNCGETNAME::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	VPVOID addr = 0;
	ULONG str = 0;
	char namestr[129];
	namestr[128] = 0;
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (type == NPC || type == CREA)
			GetOffsetData(machine,base?base:temp,0x1c,(ULONG*)&addr);
		else if (type == CONT) // CONT
			GetOffsetData(machine,temp,0x1b,(ULONG*)&addr);
		else if (type == LIGHT) // LIGH
			GetOffsetData(machine,temp,0x12,(ULONG*)&addr);
		else if (type == CLOTHING || type == ARMOR || type == WEAPON
			|| type == MISC || type == BOOK || type == ALCHEMY)
			GetOffsetData(machine,temp,0x11,(ULONG*)&addr);
		else if (type == ACTIVATOR)
			GetOffsetData(machine,temp,0xe,(ULONG*)&addr);
		else if (type == DOOR)
			addr = LONGOFFSET(temp,0x0d);
		else if (type == APPARATUS)
			addr = LONGOFFSET(temp,0x19);
		else if (type == INGREDIENT || type == REPAIR || type == PROBE || type == PICK)
			addr = LONGOFFSET(temp,0x11);

		if (addr && machine.ReadMem((VPVOID)addr, namestr, 128))
				str = (ULONG)strings.add((const char*)namestr);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCGETNAME()\n",str, (str?(char*)str:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)str);
}

//Tp21 22-08-2006: xSetName
//TODO xSetName, very buggy
bool FUNCSETNAME::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	VPVOID addr = 0;
	ULONG str = 0;

	VMREGTYPE newname = 0;
	const char* string= "null";
	

	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if(machine.pop(newname) && (string=machine.GetString((VPVOID)newname))!=0)
		{
			//if the type is npc_ or crea
		if (type == NPC || type == CREA)
			GetOffsetData(machine,base?base:temp,0x1c,(ULONG*)&addr);
		else if (type == CONT)
			GetOffsetData(machine,temp,0x1b,(ULONG*)&addr);
		else if (type == LIGHT)
			GetOffsetData(machine,temp,0x12,(ULONG*)&addr);
		else if (type == CLOTHING || type == ARMOR || type == WEAPON 
			|| type == MISC || type == BOOK || type == ALCHEMY)
			GetOffsetData(machine,temp,0x11,(ULONG*)&addr);
		else if (type == ACTIVATOR)
			GetOffsetData(machine,temp,0xe,(ULONG*)&addr);
		else if (type == DOOR)
			addr = LONGOFFSET(temp,0x0d);
		else if (type == APPARATUS)
			addr = LONGOFFSET(temp,0x19);
		else if (type == INGREDIENT || type == REPAIR || type == PROBE || type == PICK)
			addr = LONGOFFSET(temp,0x11);

			//this writes the string (max char= 128!)
			//no check for maximum characters
			if ( addr )
				machine.WriteMem((VPVOID)addr, string, 128);

//			if addr is true, read the name from memory
//			if (addr && machine.ReadMem((VPVOID)addr, namestr, 128))
//					str = (ULONG)strings.add((const char*)namestr);
//					machine.WriteMem((VPVOID)addr, namestr, 128);
		}
	}
#ifdef DEBUGGING
//	cLog::mLogMessage("%lx %s %s= FUNCSETNAME()\n",str, (str?(char*)str:"(null)"), string);
#endif	

	return true;
}

bool FUNCGETBASEID::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG id = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (base && GetIdString(machine, (VPVOID)base, idstr))
			id= (ULONG)strings.add((const char*)idstr);
		else if (temp && GetIdString(machine, (VPVOID)temp, idstr))
			id= (ULONG)strings.add((const char*)idstr);
		else
			id= (ULONG)strings.add("unknown");
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCGETBASEID()\n",id, (id?(char*)id:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)id);
}



bool FUNCGETBASESTR::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x96, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESTR()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEINT::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x99, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEINT()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEWIL::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x9c, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEWIL()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEAGI::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x9f, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEAGI()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASESPE::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xa2, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESPE()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEEND::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xa5, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEEND()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEPER::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xa8, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEPER()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASELUC::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xab, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASELUC()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}



bool FUNCISFEMALE::execute(void)
{
	VPVOID refr, temp;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp))
		if (GetOffsetData(machine, temp, OFFSET_NPCFLAGS, &value))
			value %= 2;	// lowest bit
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISFEMALE()\n",value);
#endif	
	return machine.push((VMREGTYPE)value);
}

bool FUNCMYCELLID::execute(void)
{
	VPVOID refr, addr;
	ULONG data;
	ULONG id = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr))
	{
		if (GetOffsetData(machine, refr, 5, &data) && data)
			if (GetOffsetData(machine, (VPVOID)data, 3, (ULONG*)&addr) && addr)
				if (GetOffsetData(machine, addr, 4, &data) && data)
					if (machine.ReadMem((VPVOID)data, (VPVOID)idstr, 128))
						id= (ULONG)strings.add((const char*)idstr);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCMYCELLID()\n",id, (id?(char*)id:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)id);
}




bool FUNCGETBASEGOLD::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG value = 0;
	ULONG gold = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (!base)
			base = temp;
		if ( type == NPC )
			GetOffsetData(machine, base, OFFSET_NPCBASEGOLD, &gold);
		else if ( type == CREA )
			GetOffsetData(machine, base, OFFSET_CREBASEGOLD, &gold);
		gold %= 65536; // it's a short here, so lower half only
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETBASEGOLD()\n",gold);
#endif	
	return machine.push((VMREGTYPE)gold);
}

bool FUNCGETGOLD::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG value = 0;
	ULONG gold = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (!GetAttachData(machine, refr, 8, OFFSET_GOLD, &gold))
		{
			if (!base)
				base = temp;
			if ( type == NPC )
				GetOffsetData(machine, base, OFFSET_NPCBASEGOLD, &gold);
			else if ( type == CREA )
				GetOffsetData(machine, base, OFFSET_CREBASEGOLD, &gold);
			gold %= 65536; // it's a short here, so lower half only
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETGOLD()\n",gold);
#endif	
	return machine.push((VMREGTYPE)gold);
}

bool FUNCSETBASEGOLD::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG value = 0;
	VMREGTYPE gold = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
        	if (machine.pop(gold))
		{
			if (!base)
				base = temp;
			if ( type == NPC )
				if (GetOffsetData(machine, base, OFFSET_NPCBASEGOLD, &value))
				{
					value /= 65536;
					gold %= 65536;  // gold is hold the lower half here
					gold = gold + value * 65536;
					SetOffsetData(machine, base, OFFSET_NPCBASEGOLD, gold);
				}
			else if ( type == CREA )
				if (GetOffsetData(machine, base, OFFSET_CREBASEGOLD, &value))
				{
					value /= 65536;
					gold %= 65536;  // gold is hold the lower half here
					gold = gold + value * 65536;
					SetOffsetData(machine, base, OFFSET_CREBASEGOLD, gold);
				}
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCSETBASEGOLD()\n",gold);
#endif	
	return machine.push((VMREGTYPE)gold);
}

bool FUNCSETGOLD::execute(void)
{
	bool result = false;
	VPVOID refr;
	ULONG value = 0;
	VMREGTYPE gold = 0;
	
	if (GetTargetData(machine, &refr))
	{
        	if (machine.pop(gold))
			result = SetAttachData(machine, refr, 8, OFFSET_GOLD, (ULONG)gold);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCSETGOLD()\n",gold);
#endif	
	return result;
}



bool FUNCISTRADER::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == NPC)
	{
		if (!base || !GetOffsetData(machine, base, 1, &value) || value != NPC)
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);
		flags &= 0x000037FF;
	
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) && temp) // class info
		{
			if (GetOffsetData(machine,temp,1,&value) && value == 'SALC') 
			{
				GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
				cflags &= 0x000037FF;
			}
		}
		
		flags |= cflags; 
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISTRADER()\n",flags);
#endif	
	return machine.push((VMREGTYPE)flags);
}

bool FUNCISTRAINER::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == NPC)
	{
		if (!base || !GetOffsetData(machine, base, 1, &value) || value != NPC)
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);
		flags &= 0x00004000;
	
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) && temp) // class info
		{
			if (GetOffsetData(machine,temp,1,&value) && value == 'SALC') 
			{
				GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
				cflags &= 0x00004000;
			}
		}
		if ( flags | cflags ) 
			flags = 1;
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISTRAINER()\n",flags);
#endif	
	return machine.push((VMREGTYPE)flags);
}

bool FUNCISPROVIDER::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == NPC)
	{
		if (!base || !GetOffsetData(machine, base, 1, &value) || value != NPC)
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);
		flags &= 0x00038800;
	
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) && temp) // class info
		{
			if (GetOffsetData(machine,temp,1,&value) && value == 'SALC') 
			{
				GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
				cflags &= 0x00038800;
			}
		}
		flags |= cflags;
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISPROVIDER()\n",flags);
#endif	
	return machine.push((VMREGTYPE)flags);
}



// 2005-07-12  CDC  More powerful alternatives to the IsTrader/Trainer/Provider functions
bool FUNCGETSERVICE::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG mask = 0x0003FFFF;
	
	if (machine.pop((VMREGTYPE&)mask)) 
		mask &= 0x0003FFFF;
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == NPC)
	{
		if (!base || !GetOffsetData(machine, base, 1, &type) || type != NPC)
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);		// the npc data
		//if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) 	// class info if available?
		//	&& temp && GetOffsetData(machine,temp,1,&type) && type == 'SALC')
		//	GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
		flags |= cflags; 
		flags &= mask;
	}
	return machine.push((VMREGTYPE)flags);
}

bool FUNCSETSERVICE::execute(void)
{
	VPVOID refr, temp, base;
	VMREGTYPE data;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	
	if (!machine.pop(data)) return false;

	flags = data & 0x0003FFFF;
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == NPC)
	{
		if (!base || !GetOffsetData(machine, base, 1, &type) || type != NPC)
			base = temp;  // in case npc isn't currently loaded
		
		return SetOffsetData(machine,base,OFFSET_NPCSERVICES,flags);
	}
	return false;
}

bool FUNCMODSERVICE::execute(void)
{
	VPVOID refr, temp, base;
	VMREGTYPE data;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	
	if (!machine.pop(data)) return false;
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == NPC)
	{
		if (!base || !GetOffsetData(machine, base, 1, &type) || type != NPC)
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);		// the npc data
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) 	// class info if available?
			&& temp && GetOffsetData(machine,temp,1,&type) && type == CLASS)
			GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
		flags |= cflags; 

	if ( ((signed long)data) < 0 )	// Want to remove services
		flags = flags & (~((ULONG)(0-(signed long)data)));
	else				// Want to add services
		flags = flags | (data & 0x0003FFFF);
		return SetOffsetData(machine,base,OFFSET_NPCSERVICES,flags);
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////


// Return maximum condition of item.
static ULONG GetMaxCondition(TES3MACHINE &machine, VPVOID refr, ULONG type)
{
    ULONG value = 0;
    ULONG offset = offsetOfCondition(type); // misnomer, actually MaxCondition
    if ( offset ) {
        GetOffsetData(machine, refr, offset, &value);
        if ( type == WEAPON) {
            // Weapon uses upper 16 bits of value
            value >>= 16;
        }
    }
    return value;
}

// Return maximum charge of item.
static ULONG GetMaxCharge(TES3MACHINE &machine, VPVOID refr, ULONG type)
{
	VPVOID offset = 0;
	ULONG value = 0;
    offset = GetMaxChargeOffset(machine, refr, type);
    if (offset) {  // found enchantment record
        // actually stored as integer
		GetOffsetData(machine,offset,0xc,&value);
	}
    return value;
}

// Return offset of maximum charge for item, if possible. Return 0 if
// not found.
static VPVOID GetMaxChargeOffset(TES3MACHINE &machine, VPVOID refr, ULONG type)
{
    ULONG ench = 0;
    ULONG autoCalc = 0;

    if ( type == ARMOR ) {
        // Armour.
		GetOffsetData(machine, refr, 0x30, &ench);
    } else if ( type == CLOTHING ) {
        // Clothing.
		GetOffsetData(machine, refr, 0x2d, &ench);
    } else if ( type == WEAPON ) {
        // Weapon.
		GetOffsetData(machine, refr, 0x1d, &ench);
    }

    if (ench) {  // found enchantment record
		GetOffsetData(machine,reinterpret_cast<VPVOID>(ench),0x10,&autoCalc);
    }
    // Only the low-order byte of 'autoCalc' is used.
    // FIXME: it is not clear if this is correct.
    return ((autoCalc & 0xFF)!=0) ? reinterpret_cast<VPVOID>(ench) : NULL;
}

static SPELRecord * GetSpellRecord(VMLONG spellId, TES3MACHINE & machine)
{
	SPELRecord * spell = 0;
	if (spellId != 0)
	{
		char const * idString = machine.GetString(reinterpret_cast<VPVOID>(spellId));
		TES3CELLMASTER* cellMaster = *(reinterpret_cast<TES3CELLMASTER**>reltolinear(MASTERCELL_IMAGE));
		spell = reinterpret_cast<SPELRecord*>(cellMaster->recordLists->spellsList->head);
		while (spell != 0 && strcmp(idString, spell->id) != 0)
		{
			spell = spell->nextRecord;
		}
	}
	return spell;
}