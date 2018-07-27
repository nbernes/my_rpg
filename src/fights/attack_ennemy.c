/*
** EPITECH PROJECT, 2018
** my_prg
** File description:
** attack the ennemy
*/

#include "fight.h"

char *get_inst(int *inst)
{
	switch (inst[0]) {
	case 1: switch (inst[1]) { case 1: return ("FRENCH FRIES");
		case 2: return ("POTATO SLICE");
		case 3: return ("POTATO'PPERCUT");
		case 4: return ("POTATTACK");
		}
	case 2: switch (inst[1]) { case 1: return ("MASHED POTATOES");
		case 2: return ("POTATOXICITY");
		case 3: return ("POTATO BLINK");
		case 4: return ("POTATHOR");
		}
	case 3: switch (inst[1]) { case 1: return ("TUBERHEAL");
		case 2: return ("POTATROVOC'");
		case 3: return ("POTACOAT");
		case 4: return ("POTATRUST");
		}
	}
	return (NULL);
}

void cast_spell(actor_t *actor, fight_t *fight)
{
	int lifesteal;

	switch (fight->inst[1]) {
	case 1: lifesteal = fight->ennemy->hp / (actor->hp + 4);
		if (lifesteal <= 0)
			lifesteal = 1;
		fight->ennemy->hp -= lifesteal;
		actor->hp += lifesteal * 2 / 3;
		break;
	case 2: fight->ennemy->arm -= 2; break;
	case 3: actor->def += 2; break;
	case 4: actor->atk += 3; break;
	default: break;
	}
	if (fight->ennemy->arm < 0)
		fight->ennemy->arm = 0;
}

void attack_ennemy(actor_t *actor, fight_t *fight)
{
	switch (fight->inst[0]) {
	case SPELLS: cast_spell(actor, fight); break;
	case ATTACK: fight->ennemy->hp -= actor->atk / \
2 + 3 - fight->ennemy->arm / 2; break;
	case MAGIC: fight->ennemy->hp -= actor->atk - 2; break;
	default: break;
	}
	return;
}
