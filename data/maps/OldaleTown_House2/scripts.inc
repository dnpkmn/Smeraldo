OldaleTown_House2_MapScripts:: @ 81FBF5A
	.byte 0

OldaleTown_House2_EventScript_Woman:: @ 81FBF5B
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man:: @ 81FBF64
    lock
	faceplayer
	checkflag FLAG_UNUSED_0x024
	goto_if_set FLAG_UNUSED_0x024, Script_goodluckfishing
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq Script_more
	msgbox Text_no MSGBOX_DEFAULT
	release
	end

Script_goodluckfishing::
msgbox Text_goodluck MSGBOX_DEFAULT
release
end

Text_goodluck:
.string "Come sta andando la pesca?$"

OldaleTown_House2_Text_PokemonLevelUp: @ 81FBF6D
	.string "Ciao! Questa è la casa del\n"
	.string "Vecchio Marinaio! A chi mi fa\l"
	.string "visita, regalo il mio Amo!\l"
	.string "Ti interessa un Amo Vecchio?$"

Text_no:
.string "Chi dorme non piglia pesci!$"

Script_more::
playfanfare MUS_OBTAIN_ITEM
giveitem ITEM_OLD_ROD
waitfanfare
msgbox Text_hf MSGBOX_DEFAULT
closemessage
setflag FLAG_UNUSED_0x024
release
end

Text_hf:
.string "Pescali grossi!$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon: @ 81FBFB0
	.string "If the POKéMON with you become\n"
	.string "stronger, you'll be able to go farther\l"
	.string "away from here.$"

